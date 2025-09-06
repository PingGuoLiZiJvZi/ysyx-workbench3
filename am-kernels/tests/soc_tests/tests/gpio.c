#define GPIO_PORT 0x10002000
#define SWITCH_OFFSET 0x04
#define LED_OFFSET 0x0
#define PASSWORD 0x1234
#include <trap.h>
#include <stdio.h>
int main()
{
	unsigned short res = 0;
	unsigned char offset = 0;
	unsigned char cnt = 0;
	while (1)
	{
		*(volatile unsigned short *)(GPIO_PORT + LED_OFFSET) = 1 << offset; // 点亮对应的LED
		cnt = (cnt + 1) % 16;												// 每次循环增加计
		if (!cnt)
			offset = (offset + 1) % 16; // 循环切换LED
		res = *(volatile unsigned short *)(GPIO_PORT + SWITCH_OFFSET);
		printf("Switch state: %x\n", res);
		if (res == PASSWORD)
		{
			printf("Password correct, switch state: %x\n", res);
			break; // 密码正确，退出循环
		}
	}
}