#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#ifdef __ISA_NATIVE__
#error can not support ISA=native
#endif

#define SYS_yield 1
extern int _syscall_(int, uintptr_t, uintptr_t, uintptr_t);

int main()
{
	putchar('1');	// Indicate the start of the program
	malloc(0x1000); // Ensure the heap is initialized
	putchar('2');	// Indicate that malloc was called
	return _syscall_(SYS_yield, 0, 0, 0);
}
