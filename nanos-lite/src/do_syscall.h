#ifndef DO_SYSCALL_H__
#define DO_SYSCALL_H__
#include <common.h>
#include <sys/time.h>
#include <proc.h>
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
extern int naive_uload(PCB *pcb, const char *filename);
size_t sys_brk(size_t new_end)
{
	extern char end;
	static size_t heap_end = (size_t)&end;
	CASE_LOG("sys_brk: old_end = 0x%x, new_end = 0x%x", heap_end, new_end);
	if (new_end < heap_end)
	{
		CASE_LOG("sys_brk: Cannot shrink the heap from 0x%x to 0x%x", heap_end, new_end);
		return heap_end; // Cannot shrink the heap
	}
	size_t old_end = heap_end;
	heap_end = new_end;
	return old_end; // Return the old end of the heap
}
size_t sys_gettimeofday(struct timeval *tv, struct timezone *tz)
{
	uint64_t t0 = io_read(AM_TIMER_UPTIME).us;
	if (tv)
	{
		tv->tv_sec = t0 / 1000000;
		tv->tv_usec = t0 % 1000000;
	}
	if (tz)
	{
		panic("Timezone not supported in Nanos-lite");
	}
	return 0;
}
int sys_execve(const char *filename, char *const argv[], char *const envp[])
{
	CASE_LOG("sys_execve: filename = %s, argv = %p, envp = %p", filename, argv, envp);
	naive_uload(NULL, filename);
	panic("should not reach here after sys_execve");
	return -1;
}
int sys_exit(int status)
{
	CASE_LOG("sys_exit: status = %d", status);
	naive_uload(NULL, "/bin/nterm");
	panic("should not reach here after sys_exit");
	return -1; // This should never be reached
}
#endif