#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>

#define MEM_START 0x80000000
#define MEM_SIZE 256 * 1024 * 1024 // 256MB Flash
#define UART_START 0x10000000
#define UART_SIZE 0x8
extern uint8_t pmem[];
extern void mem_read(int32_t addr, int32_t *data);
extern void mem_write(int32_t addr, int32_t data);
extern "C" void soc_write(uint32_t addr, uint8_t strb, uint32_t data)
{
	addr = addr & ~0x3; // 对齐到4字节
	uint8_t *write_addr = NULL;
	if (addr >= MEM_START && addr < MEM_START + MEM_SIZE)
	{
		write_addr = (uint8_t *)(pmem + (addr - MEM_START));
	}
	else if (addr >= UART_START && addr < UART_START + UART_SIZE)
	{
		putc(data & 0xFF, stderr);
		return;
	}
	else
	{
		printf("soc_write: Invalid address 0x%08x\n", addr);
		assert(0 && "Invalid address for soc_write");
		return;
	}
	switch (strb)
	{
	case 0b0001:
		*((uint8_t *)write_addr) = data & 0xFF;
		break;
	case 0b0010:
		*(((uint8_t *)write_addr) + 1) = (data & 0xFF00) >> 8;
		break;
	case 0b0100:
		*(((uint8_t *)write_addr) + 2) = (data & 0xFF0000) >> 16;
		break;
	case 0b1000:
		*(((uint8_t *)write_addr) + 3) = (data & 0xFF000000) >> 24;
		break;
	case 0b0011:
		*((uint16_t *)write_addr) = data & 0xFFFF;
		break;
	case 0b1100:
		*(((uint16_t *)write_addr) + 1) = (data & 0xFFFF0000) >> 16;
		break;
	case 0b1111:
		*((uint32_t *)write_addr) = data;
		break;
	default:
		printf("soc_write: Invalid strb 0x%02x for address 0x%08x\n", strb, addr);
#ifdef WAVE

#endif
		assert(0 && "Invalid strb for soc_write");
		break;
	}
}
extern "C" uint32_t soc_read(uint32_t addr)
{

	addr = addr & ~0x3;
	uint8_t *read_addr = NULL;
	if (addr >= MEM_START && addr < MEM_START + MEM_SIZE)
	{
		int32_t res = 0;
		mem_read(addr, &res);
		return res;
	}
	else if (addr >= UART_START && addr < UART_START + UART_SIZE)
	{
		int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
		fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
		int c = getchar();
		if (c == EOF)
			return -1;
		printf("UART:GET %c\n", c);
		return c;
	}
	else
	{
		printf("soc_read: Invalid address 0x%08x\n", addr);
		assert(0 && "Invalid address for soc_read");
		return 0;
	}
	return *(uint32_t *)read_addr;
}