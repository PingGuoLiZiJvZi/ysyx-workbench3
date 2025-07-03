
#include "do_syscall.h"

static Context *do_event(Event e, Context *c)
{
	switch (e.event)
	{

	case EVENT_YIELD:
	{
		CASE_LOG("Yield event triggered");
		int syscall_id = c->GPR1;
		switch (syscall_id)
		{
		case SYS_exit:
			CASE_LOG("Exit syscall called with code %d", c->GPR2);
			halt(c->GPR2); // Terminate the process
			return c;	   // Terminate the process
		case SYS_yield:
			CASE_LOG("Yield syscall called");
			yield();
			c->GPRx = 0; // Set return value to 0
			return c;
		case SYS_open:
			CASE_LOG("Open syscall called with path %s, flags %d, mode %d",
					 (char *)c->GPR2, c->GPR3, c->GPR4);
			c->GPRx = -1; // Simulate failure for now
			return c;
		case SYS_read:
			CASE_LOG("Read syscall called with fd %d, buf %p, len %d",
					 c->GPR2, (void *)c->GPR3, c->GPR4);
			c->GPRx = -1; // Simulate failure for now
			return c;
		case SYS_write:
			CASE_LOG("Write syscall called with fd %d, buf %p, len %d",
					 c->GPR2, (void *)c->GPR3, c->GPR4);
			c->GPRx = fs_write(c->GPR2, (const char *)c->GPR3, c->GPR4);
			return c;
		case SYS_kill:
			CASE_LOG("Kill syscall called with pid %d, sig %d",
					 c->GPR2, c->GPR3);
			c->GPRx = -1; // Simulate failure for now
			return c;
		case SYS_getpid:
			CASE_LOG("Getpid syscall called");
			c->GPRx = 1; // Simulate a PID of 1
			return c;
		case SYS_close:
			CASE_LOG("Close syscall called with fd %d", c->GPR2);
			c->GPRx = -1; // Simulate failure for now
			return c;
		case SYS_brk:
			CASE_LOG("Brk syscall called with new_end %zu", c->GPR2);
			c->GPRx = 0;
			return c;
		default:
			CASE_LOG("Unhandled syscall ID %d", syscall_id);
			c->GPRx = -1; // Simulate failure for unhandled syscalls
			return c;
		}

	default:
		panic("Unhandled event ID = %d", e.event);
	}

		return c;
	}
}

void init_irq(void)
{
	Log("Initializing interrupt/exception handler...");
	cte_init(do_event);
}
