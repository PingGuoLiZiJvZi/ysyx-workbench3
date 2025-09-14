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
#include <stdio.h>
#include <sys/select.h>
// const char cpl_name[][20] = {
// 	"U-mode",
// 	"S-mode",
// 	"HS-mode",
// 	"M-mode"};
word_t handle_in_mmode(word_t NO, vaddr_t epc)
{
	word_t MIE = (cpu.mstatus >> 3) & 1;
	cpu.mstatus &= ~(1 << 3);
	cpu.mstatus &= ~(1 << 7);
	cpu.mstatus |= MIE << 7; // MIE = MIE
	cpu.mstatus |= (((cpu.CPL) & 3) << 11);
	// printf("mstatus set to %x,there should not be interrupt\n", cpu.mstatus);
	cpu.mepc = epc;
	cpu.mcause = NO;
	cpu.CPL = 3;
	return cpu.mtvec;
}
word_t handle_in_smode(word_t NO, vaddr_t epc)
{
	word_t SIE = (cpu.sstatus >> 1) & 1;
	cpu.sstatus &= ~(1 << 1);
	cpu.sstatus &= ~(1 << 5);
	cpu.sstatus |= SIE << 5; // SIE = SIE
	cpu.sstatus |= (((cpu.CPL) & 3) << 8);
	// printf("sstatus set to %x,there should not be interrupt\n", cpu.sstatus);
	// printf("pc = %x, go to stvec %x\n", epc, cpu.stvec);
	// printf("NO = %d\n", NO);
	cpu.sepc = epc;
	cpu.scause = NO;
	cpu.mcause = NO;
	cpu.CPL = 1;
	return cpu.stvec;
}
word_t isa_raise_intr(word_t NO, vaddr_t epc)
{
	IFDEF(CONFIG_ETRACE, printf("error %d at %x\n", cpu.mcause, epc));
	switch (cpu.CPL)
	{
	case 3:
		if ((1 << NO) & cpu.medeleg)
		{
			return handle_in_smode(NO, epc);
		}
		else
		{
			return handle_in_mmode(NO, epc);
		}
		break;
	case 1:
	case 0:
		return handle_in_smode(NO, epc);
	default:
		assert(0);
		return 0xdeadbeef;
	}
}
int is_stdin_ready()
{
	struct timeval tv = {0, 0};
	fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(0, &readfds);
	select(1, &readfds, NULL, NULL, &tv);
	return FD_ISSET(0, &readfds);
}
word_t isa_query_intr()
{
	if (cpu.CPL == 3 && (cpu.mie & (1 << 7)) && (cpu.mstatus & (1 << 3)) && cpu.intr)
	{
		// 机器模式允许中断，并且有中断请求
		cpu.intr = false;
		// printf("enabled interrupt, mstatus = %x\n", cpu.mstatus);
		return IRQ_TIMER;
		if (is_stdin_ready())
			return IRQ_UART;
		else
			return IRQ_TIMER;
	}
	if (cpu.CPL <= 1 && (cpu.sie & (1 << 5)) && (cpu.sstatus & (1 << 1)) && cpu.intr)
	{
		// 监督模式允许中断，并且有中断请求
		cpu.intr = false;
		// printf("enabled interrupt, sstatus = %x\n", cpu.sstatus);
		if (is_stdin_ready())
			return IRQ_UART;
		else
			return IRQ_TIMER;
	}
	return INTR_EMPTY;
}
