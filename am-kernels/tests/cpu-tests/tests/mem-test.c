#define RAM_BASE 0x0f000000
#define RAM_SIZE 0x2000
#define STACK_TOP (RAM_BASE + RAM_SIZE) // 栈顶在RAM末尾
#include <klib.h>
// 内存测试函数
void mem_test_word()
{

	// 测试范围：RAM起始到栈底（避开栈区）
	volatile unsigned int *start = (volatile unsigned int *)RAM_BASE;
	volatile unsigned int *end = (volatile unsigned int *)(STACK_TOP - 0x1000); // 留出256字节栈空间

	// 8位写入测试
	for (volatile unsigned int *p = start; p < end; p++)
	{
		*p = (uintptr_t)p;
	}
	// 8位读取验证
	for (volatile unsigned int *p = start; p < end; p++)
	{
		if (*p != (uintptr_t)p)
		{
			halt(1); // 验证失败，挂起
		}
	}
}
void mem_test_half()
{
	// 测试范围：RAM起始到栈底（避开栈区）
	volatile unsigned short *start = (volatile unsigned short *)RAM_BASE;
	volatile unsigned short *end = (volatile unsigned short *)(STACK_TOP - 0x1000); // 留出256字节栈空间

	// 16位写入测试
	for (volatile unsigned short *p = start; p < end; p++)
	{
		*p = (unsigned short)(uintptr_t)p;
	}
	// 16位读取验证
	for (volatile unsigned short *p = start; p < end; p++)
	{
		if (*p != (unsigned short)(uintptr_t)p)
		{
			halt(1); // 验证失败，挂起
		}
	}
}
void mem_test_byte()
{
	// 测试范围：RAM起始到栈底（避开栈区）
	volatile unsigned char *start = (volatile unsigned char *)RAM_BASE;
	volatile unsigned char *end = (volatile unsigned char *)(STACK_TOP - 0x1000); // 留出256字节栈空间

	// 8位写入测试
	for (volatile unsigned char *p = start; p < end; p++)
	{
		*p = (unsigned char)(uintptr_t)p;
	}
	// 8位读取验证
	for (volatile unsigned char *p = start; p < end; p++)
	{
		if (*p != (unsigned char)(uintptr_t)p)
		{
			halt(1); // 验证失败，挂起
		}
	}
}
int main()
{
	mem_test_word();
	mem_test_half();
	mem_test_byte();
	return 0;
}