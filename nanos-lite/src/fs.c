#include <fs.h>

typedef size_t (*ReadFn)(void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn)(const void *buf, size_t offset, size_t len);
extern size_t ramdisk_read(void *buf, size_t offset, size_t len);
extern size_t ramdisk_write(const void *buf, size_t offset, size_t len);
typedef struct
{
	char *name;
	size_t size;
	size_t disk_offset;
	// Current position in the file
	ReadFn read;
	WriteFn write;
	size_t cursor;
} Finfo;

enum
{
	FD_STDIN,
	FD_STDOUT,
	FD_STDERR,
	FD_FB
};
size_t invalid_read(void *buf, size_t offset, size_t len)
{
	panic("should not reach here");
	return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len)
{
	panic("should not reach here");
	return 0;
}

size_t output_write(const void *buf, size_t offset, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		putch(((const char *)buf)[i]);
	}
	return len;
}
/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
	[FD_STDIN] = {"stdin", 0, 0, invalid_read, invalid_write},
	[FD_STDOUT] = {"stdout", 0, 0, invalid_read, output_write},
	[FD_STDERR] = {"stderr", 0, 0, invalid_read, output_write},
#include "files.h"
};

int fs_open(const char *pathname, int flags, int mode)
{
	for (int i = 0; i < sizeof(file_table) / sizeof(Finfo); i++)
	{
		if (strcmp(pathname, file_table[i].name) == 0)
		{
			return i; // Return the index as the file descriptor
		}
	}
	panic("open: file not found");
	return -1; // File not found
}
size_t fs_read(int fd, void *buf, size_t len)
{
	if (fd < 0 || fd >= sizeof(file_table) / sizeof(Finfo))
	{
		panic("read: invalid file descriptor");
	}
	if (file_table[fd].read == invalid_read)
	{
		return 0;
	}
	if (len + file_table[fd].cursor > file_table[fd].size)
	{
		panic("read: read exceeds file size");
	}
	file_table[fd].cursor += len; // Update cursor position
	size_t bytes_read = file_table[fd].read(buf, file_table[fd].disk_offset, len);
	return bytes_read; // Return the number of bytes read
}
size_t fs_write(int fd, const void *buf, size_t len)
{
	if (fd < 0 || fd >= sizeof(file_table) / sizeof(Finfo))
	{
		panic("write: invalid file descriptor");
	}
	if (file_table[fd].write == invalid_write)
	{
		return 0;
	}
	if (len + file_table[fd].cursor > file_table[fd].size)
	{
		panic("write: write exceeds file size");
	}
	file_table[fd].cursor += len;
	size_t bytes_written = file_table[fd].write(buf, file_table[fd].disk_offset, len);

	return bytes_written; // Return the number of bytes written
}
size_t fs_lseek(int fd, size_t offset, int whence)
{
	if (fd < 0 || fd >= sizeof(file_table) / sizeof(Finfo))
	{
		panic("lseek: invalid file descriptor");
	}
	if (fd <= 2) // stdin, stdout, stderr
	{
		return 0; // No seek for stdin/stdout/stderr
	}
	switch (whence)
	{
	case SEEK_SET:
		file_table[fd].cursor = offset; // Set cursor to the specified offset
		return offset;					// Return the new position
		break;
	case SEEK_CUR:
		file_table[fd].cursor += offset; // Move cursor by the specified offset
		return file_table[fd].cursor;	 // Return the new position
		break;
	case SEEK_END:
		file_table[fd].cursor = file_table[fd].size + offset; // Set cursor to the end plus offset
		return file_table[fd].cursor;						  // Return the new position
		break;
	default:
		panic("lseek: invalid whence");
		return -1;
		break;
	}
}
int fs_close(int fd)
{
	if (fd < 0 || fd >= sizeof(file_table) / sizeof(Finfo))
	{
		panic("close: invalid file descriptor");
	}
	file_table[fd].cursor = 0; // Reset cursor to 0
	return 0;
}
void init_fs()
{
	// TODO: initialize the size of /dev/fb
	Log("Initializing file system...");
	for (int i = 0; i < sizeof(file_table) / sizeof(Finfo); i++)
	{
		file_table[i].cursor = 0; // Initialize cursor to 0
		if (file_table[i].read == NULL)
		{
			file_table[i].read = ramdisk_read;
		}
		if (file_table[i].write == NULL)
		{
			file_table[i].write = ramdisk_write;
		}
	}
}
