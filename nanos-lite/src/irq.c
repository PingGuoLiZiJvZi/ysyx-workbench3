#include <common.h>
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
static Context *do_event(Event e, Context *c)
{
	switch (e.event)
	{

	case EVENT_YIELD:
	{
		Log("Syscall event triggered");
		int syscall_id = c->GPR1;
		switch (syscall_id)
		{
		case SYS_exit:
			Log("Exit syscall called with status %d", c->GPR1);
			halt(c->GPR2); // Terminate the process
			return c;	   // Terminate the process
		case SYS_yield:
			Log("Yield syscall called");
			yield();
			c->GPRx = 0; // Set return value to 0
			return c;
		case SYS_open:
			Log("Open syscall called with path %s, flags %d, mode %d",
				(char *)c->GPR2, c->GPR3, c->GPR4);
			c->GPRx = -1; // Simulate failure for now
			return c;
		case SYS_read:
			Log("Read syscall called with fd %d, buf %p, len %d",
				c->GPR2, (void *)c->GPR3, c->GPR4);
			c->GPRx = -1; // Simulate failure for now
			return c;
		case SYS_write:
			Log("Write syscall called with fd %d, buf %p, len %d",
				c->GPR2, (void *)c->GPR3, c->GPR4);
			c->GPRx = -1; // Simulate failure for now
			return c;
		case SYS_kill:
			Log("Kill syscall called with pid %d", c->GPR2);
			c->GPRx = -1; // Simulate failure for now
			return c;
		case SYS_getpid:
			Log("Get PID syscall called");
			c->GPRx = 1; // Simulate a PID of 1
			return c;
		case SYS_close:
			Log("Close syscall called with fd %d", c->GPR2);
			c->GPRx = -1; // Simulate failure for now
			return c;
		default:
			Log("Unhandled syscall ID = %d", syscall_id);
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
