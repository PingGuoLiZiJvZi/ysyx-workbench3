#include <am.h>
#include "npc.h"
#include "riscv.h"
#include <klib.h>
static AddrSpace kas = {};
static void *(*pgalloc_usr)(int) = NULL;
static void (*pgfree_usr)(void *) = NULL;
static int vme_enable = 0;

static Area segments[] = { // Kernel memory mappings
	NPC_PADDR_SPACE};

#define USER_SPACE RANGE(0x40000000, 0x80000000)

static inline void set_satp(void *pdir)
{
	uintptr_t mode = 1ul << (__riscv_xlen - 1);
	asm volatile("csrw satp, %0" : : "r"(mode | ((uintptr_t)pdir >> 12)));
}

static inline uintptr_t get_satp()
{
	uintptr_t satp;
	asm volatile("csrr %0, satp" : "=r"(satp));
	return satp << 12;
}

bool vme_init(void *(*pgalloc_f)(int), void (*pgfree_f)(void *))
{
	pgalloc_usr = pgalloc_f;
	pgfree_usr = pgfree_f;

	kas.pgsize = PGSIZE;
	kas.ptr = pgalloc_f(PGSIZE);

	int i;
	for (i = 0; i < LENGTH(segments); i++)
	{
		void *va = segments[i].start;
		for (; va < segments[i].end; va += PGSIZE)
		{
			map(&kas, va, va, 0);
		}
	}
	set_satp(kas.ptr);
	vme_enable = 1;

	return true;
}

void protect(AddrSpace *as)
{
}

void unprotect(AddrSpace *as)
{
}

void map(AddrSpace *as, void *va, void *pa, int prot)
{
}

Context *ucontext(AddrSpace *as, Area kstack, void *entry)
{
	return NULL;
}
