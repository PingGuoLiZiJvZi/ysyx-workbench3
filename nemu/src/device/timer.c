/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <device/map.h>
#include <device/alarm.h>
#include <utils.h>

static uint32_t *rtc_port_base = NULL;
extern uint64_t mtime_cmp;
extern uint64_t intr_cnt;
static void rtc_io_handler(uint32_t offset, int len, bool is_write)
{
	assert(offset == 0 || offset == 4);
	if (!is_write)
	{
		uint64_t us = get_time();
		rtc_port_base[0] = (uint32_t)us;
		rtc_port_base[1] = us >> 32;
	}
}
static void rtc_mtimecmp_handler(uint32_t offset, int len, bool is_write)
{
	assert(len == 4);
	if (is_write)
	{
		intr_cnt = 0;
		printf("mtime_cmp set to %ld\n", mtime_cmp);
	}
}
#ifndef CONFIG_TARGET_AM
static void timer_intr()
{
	printf("timer_intr called, nemu_state.state = %d\n", nemu_state.state);
	if (nemu_state.state == NEMU_RUNNING)
	{
		extern void dev_raise_intr();
		dev_raise_intr();
	}
}
#endif

void init_timer()
{
	rtc_port_base = (uint32_t *)new_space(8);
#ifdef CONFIG_HAS_PORT_IO
	add_pio_map("rtc", CONFIG_RTC_PORT, rtc_port_base, 8, rtc_io_handler);
#else
	add_mmio_map("rtc", CONFIG_RTC_MMIO, rtc_port_base, 8, rtc_io_handler);
	add_mmio_map("mtimecmp", CONFIG_RTC_MMIO + 0x4000, &mtime_cmp, 8, rtc_mtimecmp_handler);
#endif
	IFNDEF(CONFIG_TARGET_AM, add_alarm_handle(timer_intr));
}
