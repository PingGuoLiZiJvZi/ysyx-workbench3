#include <trap.h>
// SPI寄存器定义 (基地址0x10000000)
#define SPI_BASE 0x10001000
#define SPI_CTRL (4)
#define SPI_DIV (5)
#define SPI_SS (6)
unsigned int func[6] = {0};
// 控制寄存器位定义
#define GO_BSY (1 << 8)
#define ASS (1 << 13)
#define LSB (1 << 11)
#define CHAR_LEN_MASK 0x7F
#define UART_BASE 0x10000000
// 通信参数配置
#define SLAVE_ID 0	   // bitrev模块的slave编号
#define DATA_BITS 0x40 // 数据位数
#define CLK_DIV 0	   // 分频系数(最高速度)

__attribute__((noinline)) void char_test()
{
	*(volatile char *)(UART_BASE) = 'A';
	*(volatile char *)(UART_BASE) = '\n';
	while (1)
		;
}

unsigned int flash_read(unsigned int addr)
{
	volatile unsigned int *base = (unsigned int *)SPI_BASE;
	base[SPI_DIV] = 0;
	base[SPI_CTRL] = ASS | DATA_BITS;
	base[0] = 0x00000000;
	base[1] = 0x03000000 | (addr & 0x00ffffff);
	base[SPI_SS] = (1 << SLAVE_ID);
	base[SPI_CTRL] |= GO_BSY;
	while (base[SPI_CTRL] & GO_BSY)
		;
	unsigned char *reschar = (unsigned char *)base;
	return reschar[0] << 24 | reschar[1] << 16 | reschar[2] << 8 | reschar[3];
}
void load_char_test(unsigned int start)
{
	for (int i = 0; i < 6; i++)
	{
		func[i] = flash_read(start);
		start += 4;
	}
}
int main()
{

	load_char_test(0x18);
	void (*test)(void) = (void (*)(void))func;
	test();
	char_test();
}