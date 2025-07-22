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

#include <isa.h>
#include <memory/paddr.h>
word_t trans_check(vaddr_t addr, int len, int type)
{
	int res = isa_mmu_check(addr, len, type);
	if (res == MMU_DIRECT)
		return addr;
	else if (res == MMU_TRANSLATE)
		return isa_mmu_translate(addr, len, type);
	else
		panic("MMU check failed for vaddr %x,type %d\n", addr, type);
}
word_t map_to_rom_and_ram(word_t addr)
{
	if (addr >= 0x20000000 && addr < 0x20001000)	  // ROM
		return addr + 0x60000000;					  // 实际地址为0x80000000-0x80001000
	else if (addr >= 0x0f000000 && addr < 0x0f002000) // RAM
		return addr + 0x81000000 - 0x0f000000;		  // 实际地址为0x81000000-0x81002000
	else if (addr >= 0x30000000 && addr < 0x40000000) // Flash
		return addr + 0x50000000;					  // 实际地址为0x80000000-0x90000000
	else if (addr >= 0x80000000 && addr < 0x80100000) // PSRAM
		return addr + 0x2000000;					  // 实际地址为0x82000000-0x82010000
	else if (addr >= 0xa0000000 && addr < 0xa2000000) // SDRAM
		return addr - 0x1d000000;					  // 实际地址为0x83000000-0x85000000
	return addr;									  // Other addresses remain unchanged
}
word_t vaddr_ifetch(vaddr_t addr, int len)
{
	addr = map_to_rom_and_ram(addr);
	return paddr_read(addr, len);
}

word_t vaddr_read(vaddr_t addr, int len)
{
	addr = map_to_rom_and_ram(addr);
	return paddr_read(addr, len);
}

void vaddr_write(vaddr_t addr, int len, word_t data)
{
	addr = map_to_rom_and_ram(addr);
	paddr_write(addr, len, data);
}
