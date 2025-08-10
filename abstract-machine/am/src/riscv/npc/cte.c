#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>
extern void __am_get_cur_as(Context *c);
extern void __am_switch(Context *c);
static Context *(*user_handler)(Event, Context *) = NULL;

Context *__am_irq_handle(Context *c)
{
	__am_get_cur_as(c);
	// print_context(c);
	if (user_handler)
	{
		Event ev = {0};
		switch (c->mcause)
		{
		case 11:
			ev.event = EVENT_YIELD;
			c->mepc += 4;
			break;
		case 8:
			ev.event = EVENT_YIELD;
			c->mepc += 4;
			break;
		case 7: // IRQ_TIMER
			ev.event = EVENT_IRQ_TIMER;
			c->mepc -= 0;
			break;
		default:
			ev.event = EVENT_ERROR;
			break;
		}
		c = user_handler(ev, c);
		// skip ecall
		assert(c != NULL);
	}
	__am_switch(c);
	// print_context(c);
	return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context *(*handler)(Event, Context *))
{
	// initialize exception entry
	asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

	// register event handler
	user_handler = handler;

	return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg)
{
	Context *ctx = (Context *)((uintptr_t)kstack.end - sizeof(Context));
	ctx->mepc = (uintptr_t)entry;
	ctx->gpr[2] = (uintptr_t)kstack.end; // stack pointer
	ctx->gpr[10] = (uintptr_t)arg;		 // a0
	ctx->mstatus = 0x80;
	ctx->next_priv = 0;
	ctx->pdir = NULL; // no address space for kernel context
	return ctx;
}

void yield()
{
#ifdef __riscv_e
	asm volatile("li a5, -1; ecall");
#else
	asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled()
{
	return false;
}

void iset(bool enable)
{
}
