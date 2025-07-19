#include <trap.h>
// SPI寄存器定义 (基地址0x10000000)
#define SPI_BASE 0x10001000
#define SPI_CTRL (4)
#define SPI_DIV (5)
#define SPI_SS (6)

// 控制寄存器位定义
#define GO_BSY (1 << 8)
#define ASS (1 << 13)
#define CHAR_LEN_MASK 0x7F

// 通信参数配置
#define SLAVE_ID 7	   // bitrev模块的slave编号
#define DATA_BITS 0x10 // 数据位数
#define CLK_DIV 0	   // 分频系数(最高速度)

unsigned char answer = 0x55;
unsigned char data = 0xAA;

int main()
{
	volatile unsigned int *base = (unsigned int *)SPI_BASE;
	// 写入分频寄存器，最大频率
	base[SPI_DIV] = 0;
	base[SPI_CTRL] = ASS | DATA_BITS;

	// 2. 选择slave (bitrev模块编号7)
	base[SPI_SS] = (1 << SLAVE_ID);

	base[0] = data << 8;

	// 5. 启动传输
	base[SPI_CTRL] |= GO_BSY;

	// 6. 轮询等待传输完成
	while (base[SPI_CTRL] & GO_BSY)
		;

	// 7. 读取接收数据
	unsigned int res = base[0];
	printf("data = %x ,res = %x\n", data, res);
	check(res == answer);

	return 0;
}