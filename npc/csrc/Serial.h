#pragma once
#include <stdint.h>
#include "Iomap.h"
#define CH_OFFSET 0
#define DEVICE_BASE 0xa0000000

#define SERIAL_PORT (DEVICE_BASE + 0x00003f8)
static uint8_t serial_base[8] = {0};

static void serial_putc(char ch)
{
	putc(ch, stderr);
}

static void serial_io_handler(uint32_t offset, int len, bool is_write)
{
	assert(len == 1);
	switch (offset)
	{
	case CH_OFFSET:
		if (is_write)
			serial_putc(serial_base[0]);
		else
		{
			printf("do not support read");
			assert(0);
		}
		break;
	default:
		printf("do not support offset = %d", offset);
		assert(0);
	}
}

void inline init_serial()
{
	add_mmio_map("serial", SERIAL_PORT, serial_base, 8, serial_io_handler);
}
