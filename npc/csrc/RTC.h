#pragma once
#define DEVICE_BASE 0xa0000000
#define RTC_ADDR (DEVICE_BASE + 0x0000048)
#include <stdint.h>
#include <assert.h>
#include <sys/time.h>
#include <stdlib.h>
#include "Iomap.h"
static uint32_t rtc_port_base[2] = {0};
static uint64_t boot_time = 0;
static uint64_t get_time()
{
	if (boot_time == 0)
	{
		struct timeval now;
		gettimeofday(&now, NULL);
		boot_time = now.tv_sec * 1000000 + now.tv_usec;
	}
	struct timeval now;
	gettimeofday(&now, NULL);
	uint64_t us = now.tv_sec * 1000000 + now.tv_usec;
	us -= boot_time;
	return us;
}
static void rtc_io_handler(uint32_t offset, int len, bool is_write)
{
	// printf("rtc_io_handler offset = %d len = %d is_write = %d\n", offset, len, is_write);
	assert(offset == 0 || offset == 4);
	if (!is_write)
	{
		uint64_t us = get_time();
		rtc_port_base[0] = (uint32_t)us;
		rtc_port_base[1] = us >> 32;
	}
}

static void inline init_timer()
{
	add_mmio_map("rtc", RTC_ADDR, rtc_port_base, 8, rtc_io_handler);
}