#include <memory.h>
#include "strace.h"
#include <stdio.h>
static void *pf = NULL;

void *new_page(size_t nr_page)
{
	CASE_LOG("new_page: Allocating %u pages", nr_page);
	printf("from %p to %p\n", pf, pf + nr_page * PGSIZE);
	assert(pf);
	void *p = pf;
	pf += nr_page * PGSIZE;
	return p;
}

#ifdef HAS_VME
static void *pg_alloc(int n)
{
	return NULL;
}
#endif

void free_page(void *p)
{
	CASE_LOG("not implement yet");
}

/* The brk() system call handler. */
int mm_brk(uintptr_t brk)
{
	return 0;
}

void init_mm()
{
	pf = (void *)ROUNDUP(heap.start, PGSIZE);
	Log("free physical pages starting from %p", pf);

#ifdef HAS_VME
	vme_init(pg_alloc, free_page);
#endif
}
