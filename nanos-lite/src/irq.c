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
size_t sys_write(int fd, const char *buf, size_t count)
{
	if (fd != 1 && fd != 2)
	{
		Log("Invalid file descriptor %d for write syscall", fd);
		return -1; // Invalid file descriptor
	}
	for (size_t i = 0; i < count; i++)
		putch(buf[i]);
	return count; // Return the number of bytes written
}
static Context *do_event(Event e, Context *c)
{
#ifdef CONFIG_STARCE
	printf("Syscall event triggered: %d,call_id = %d,arg1 = %d, arg2 = %d, arg3 = %d, arg4 = %d\n",
		   e.event, c->GPR1, c->GPR2, c->GPR3, c->GPR4);
#endif
	switch (e.event)
	{

	case EVENT_YIELD:
	{
		Log("Syscall event triggered");
		int syscall_id = c->GPR1;
		switch (syscall_id)
		{
		case SYS_exit:
			Log("Exit syscall called with status %d", c->GPR2);
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
			c->GPRx = sys_write(c->GPR2, (const char *)c->GPR3, c->GPR4);
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
