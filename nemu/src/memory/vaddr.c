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
word_t vaddr_ifetch(vaddr_t addr, int len)
{
	addr = trans_check(addr, len, MEM_TYPE_IFETCH);
	return paddr_read(addr, len);
}

word_t vaddr_read(vaddr_t addr, int len)
{
	addr = trans_check(addr, len, MEM_TYPE_READ);
	return paddr_read(addr, len);
}

void vaddr_write(vaddr_t addr, int len, word_t data)
{
	addr = trans_check(addr, len, MEM_TYPE_WRITE);
	paddr_write(addr, len, data);
}
