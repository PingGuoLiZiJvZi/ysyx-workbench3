#include <proc.h>
#include <elf.h>

#ifdef __LP64__
#define Elf_Ehdr Elf64_Ehdr
#define Elf_Phdr Elf64_Phdr
#else
#define Elf_Ehdr Elf32_Ehdr
#define Elf_Phdr Elf32_Phdr
#endif
static char program_buf[0x100000];
extern size_t get_ramdisk_size(void);
extern size_t ramdisk_read(void *buf, size_t offset, size_t len);
static uintptr_t loader(PCB *pcb, const char *filename)
{
	Log("Loading program '%s'...", filename);
	uint32_t size = get_ramdisk_size();
	if (size >= sizeof(program_buf))
	{
		panic("Program size exceeds buffer size");
	}
	ramdisk_read(program_buf, 0, size);
	Elf_Ehdr *ehdr = (Elf_Ehdr *)program_buf;
	assert(*(uint32_t *)ehdr->e_ident == 0x464c457f); // Check ELF magic number
	return ehdr->e_entry;							  // Return the entry point address
	return 0;
}

void naive_uload(PCB *pcb, const char *filename)
{
	uintptr_t entry = loader(pcb, filename);
	Log("Jump to entry = %p", entry);
	((void (*)())entry)();
}
