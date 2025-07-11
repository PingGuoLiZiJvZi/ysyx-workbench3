#include <proc.h>
#define MAX_NR_PROC 4
static PCB pcb[MAX_NR_PROC] __attribute__((used)) = {};
static const char *argv[] = {
	"/bin/exec-test",
	NULL};
static const char *envp[] = {
	NULL};
static PCB pcb_boot = {};
PCB *current = NULL;
extern void naive_uload(PCB *pcb, const char *filename);
extern void context_kload(PCB *pcb, void (*entry)(void *), void *arg);
extern void context_uload(PCB *pcb, char *filename, const char *argv[], const char *envp[]);
void switch_boot_pcb()
{
	current = &pcb_boot;
}

void hello_fun(void *arg)
{
	int j = 1;
	while (1)
	{
		if (j % 100 == 0)
			printf("Hello, %s! %d\n", (char *)arg, j);
		j++;
		yield();
	}
}

void init_proc()
{
	context_kload(&pcb[0], hello_fun, "ha ji mi");
	context_uload(&pcb[1], "/bin/pal", argv, envp);
	switch_boot_pcb();
	printf("Boot process initialized.\n");
	yield();

	Log("Initializing processes...");
	// panic("testing context switch,so should not reach here!");
	// load program here
	naive_uload(NULL, "/bin/bmp-test");
}

Context *schedule(Context *prev)
{

	current->cp = prev;
	// printf("current == boot pcb? %s\n", current == &pcb_boot ? "yes" : "no");
	current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);

	// printf("Scheduling: switching from %p to %p\n", current->cp, prev);
	// printf("Switching to PCB%d\n", current - pcb);
	// printf("Switch from as %p to as %p\n", prev->pdir, current->cp->pdir);
	return current->cp;
}
