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
	assert(ehdr->e_ident[0] == ELFMAG0 &&
		   ehdr->e_ident[1] == ELFMAG1 &&
		   ehdr->e_ident[2] == ELFMAG2 &&
		   ehdr->e_ident[3] == ELFMAG3);		// Check ELF magic number
	uint32_t program_off = ehdr->e_phoff;		// Program header offset
	uint32_t program_num = ehdr->e_phnum;		// Number of program headers
	assert(program_off > 0 && program_num > 0); // Ensure valid program header
	for (uint32_t i = 0; i < program_num; i++)
	{
		Elf_Phdr *phdr = (Elf_Phdr *)(program_buf + program_off + i * sizeof(Elf_Phdr));
		if (phdr->p_type == PT_LOAD) // Loadable segment
		{
			uintptr_t vaddr = phdr->p_vaddr;
			printf("vaddr = 0x%x\n", vaddr); // Virtual address
			uintptr_t paddr = vaddr;		 // Physical address (for simplicity)
			uint32_t memsz = phdr->p_memsz;	 // Memory size
			uint32_t filesz = phdr->p_filesz;
			printf("memsz = 0x%x filesz = 0x%x\n", memsz, filesz);		 // File size
			assert(memsz >= filesz);									 // Ensure memory size is at least file size
			memcpy((void *)paddr, program_buf + phdr->p_offset, filesz); // Load segment into memory
			memset((void *)(paddr + filesz), 0, memsz - filesz);		 // Zero out the rest of the segment
		}
	}
	// Check ELF magic number
	return ehdr->e_entry; // Return the entry point address
	return 0;
}

void naive_uload(PCB *pcb, const char *filename)
{
	uintptr_t entry = loader(pcb, filename);
	Log("Jump to entry = %p", entry);
	((void (*)())entry)();
}
