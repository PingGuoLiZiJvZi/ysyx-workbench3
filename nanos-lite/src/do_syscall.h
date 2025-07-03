#ifndef DO_SYSCALL_H__
#define DO_SYSCALL_H__
#include <common.h>
// #define STRACE
#include "strace.h"
#ifndef size_t
#define size_t unsigned int
#endif
#ifndef mode_t
#define mode_t unsigned int
#endif
#ifndef uintptr_t
#define uintptr_t unsigned int
#endif
extern int fs_open(const char *pathname, int flags, mode_t mode);
extern size_t fs_read(int fd, void *buf, size_t len);
extern int fs_close(int fd);
extern size_t fs_write(int fd, const char *buf, size_t len);
extern size_t fs_lseek(int fd, size_t offset, int whence);
enum
{
	SYS_exit,
	SYS_yield,
	SYS_open,
	SYS_read,
	SYS_write,
	SYS_kill,
	SYS_getpid,
	SYS_close,
	SYS_lseek,
	SYS_brk,
	SYS_fstat,
	SYS_time,
	SYS_signal,
	SYS_execve,
	SYS_fork,
	SYS_link,
	SYS_unlink,
	SYS_wait,
	SYS_times,
	SYS_gettimeofday
};

size_t sys_brk(size_t new_end)
{
	extern char end;
	static size_t heap_end = (size_t)&end;
	if (new_end < heap_end)
	{
		Log("Cannot shrink heap");
		return -1; // Cannot shrink the heap
	}
	size_t old_end = heap_end;
	heap_end = new_end;
	return old_end; // Return the old end of the heap
}

#endif