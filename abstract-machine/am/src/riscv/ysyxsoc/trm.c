#include <am.h>
#include <klib-macros.h>
#include "npc.h"
#include "riscv.h"
extern char _heap_start;
extern char _heap_end;
int main(const char *args);
extern char _data_lma[];	 // 数据段加载地址(MA)
extern char _data_vma[];	 // 数据段运行地址(SA)
extern char _data_vma_end[]; // 数据段结束地址(SA)
extern char _bss_start[];
extern char _bss_end[];

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : : "r"(code))
Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // defined in CFLAGS

#define UART_RBR (0) // 接收缓冲寄存器 (DLAB=0)
#define UART_THR (0) // 发送保持寄存器 (DLAB=0)
#define UART_DLL (0) // 除数锁存器 LSB (DLAB=1)
#define UART_DLM (1) // 除数锁存器 MSB (DLAB=1)
#define UART_LCR (3) // 线路控制寄存器
#define UART_LSR (5) // 线路状态寄存器

void putch(char ch)
{
	volatile uint8_t *uart = (volatile uint8_t *)SERIAL_PORT;

	while ((uart[UART_LSR] & 0x40) == 0)
		;
	outb(SERIAL_PORT, ch);
}
void uart_init()
{
	volatile uint8_t *uart = (volatile uint8_t *)SERIAL_PORT;

	// 1. 设置DLAB=1以访问除数寄存器
	uart[UART_LCR] = 0x80; // 设置LCR的bit7(DLAB)=1

	// 2. 设置波特率除数 (示例值，实际值需计算)
	uart[UART_DLM] = 0x00; // 除数高位
	uart[UART_DLL] = 0x03; // 除数低位 (115200 baud @ 1.8432MHz)

	// 3. 设置通信参数并清除DLAB
	// 8位数据，无校验，1位停止位 (0b00000011)
	uart[UART_LCR] = 0x03;
}
void halt(int code)
{
	npc_trap(code);
	while (1)
		;
}

void _trm_init()
{
	int ret = main(mainargs);
	halt(ret);
}

void bootloader()
{
	/* 复制数据段到SRAM */
	for (unsigned i = 0; i < _data_vma_end - _data_vma; i++)
	{
		_data_vma[i] = _data_lma[i];
	}

	/* 清零BSS段 */
	for (char *p = _bss_start; p < _bss_end; p++)
	{
		*p = 0;
	}
}

void display_message()
{
	unsigned int ysyx, id;

	__asm__ volatile(
		"csrr %0, 0x114\n"
		"csrr %1, 0x514\n"
		: "=r"(ysyx), "=r"(id) // 输出约束
		:					   // 无输入
		:					   // 无破坏寄存器
	);

	for (int i = 0; i < 4; i++)
	{
		putch((ysyx & 0xFF000000) >> 24);
		ysyx <<= 8;
	}
	putch(':');
	for (int i = 0; i < 8; i++)
	{
		unsigned char digit = id % 10;
		putch('0' + digit);
		id /= 10;
	}
	putch('\n');
}