#pragma once
#include "Vtop.h"
#include "verilated.h"
#include "paddr_simple.h"
#include "disasm.h"
#include "Iringbuf.h"
#include "Difftest.h"
#include <stdio.h>
#define DIFFTEST_TO_REF 1
#define DIFFTEST_TO_DUT 0
static char regs[16][8] = {
	"$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
	"s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"};

class Npc
{
public:
	Npc(int argc, char **argv)
	{
		Verilated::commandArgs(argc, argv);
		top = new Vtop;
		init_disasm();
	}
	~Npc()
	{
		delete top;
	}
	void reset_top()
	{
		top->clk = 0;
		top->rst = 1;
		top->eval();
		top->clk = 1;
		top->eval();
		top->rst = 0;
#ifdef TRACE
		update_messages();
#endif
	}
	void step_top()
	{

		top->clk = 0;
		top->eval();
		top->clk = 1;
		top->eval();
#ifdef TRACE
		update_messages();
#endif
	}

	void reg_display()
	{
		printf("pc= %010u\t0x%08x\n", top->pc, top->pc);
		for (int i = 0; i < sizeof(regs) / sizeof(regs[0]); i++)
		{
			printf("%s= %010u\t0x%08x", regs[i], top->regs[i], top->regs[i]);
			if (i % 2 == 1)
				printf("\n");
		}
	}
	void init_difftest(long img_size)
	{
		assert(ref_so_file != NULL);

		void *handle;
		handle = dlopen(ref_so_file, RTLD_LAZY);
		assert(handle);

		ref_difftest_memcpy = (void (*)(uint32_t addr, void *buf, size_t n, bool direction))dlsym(handle, "difftest_memcpy");
		assert(ref_difftest_memcpy);
		// a value of type "void *" cannot be assigned to an entity of type "void (*)(uint32_t addr, void *buf, size_t n, bool direction)"
		ref_difftest_regcpy = (void (*)(void *dut, bool direction))dlsym(handle, "difftest_regcpy");
		assert(ref_difftest_regcpy);
		ref_difftest_exec = (void (*)(uint64_t n))dlsym(handle, "difftest_exec");
		// a value of type "void *" cannot be assigned to an entity of type "void (*)(void *dut, bool direction)" ref_difftest_exec = dlsym(handle, "difftest_exec");
		assert(ref_difftest_exec);

		void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
		assert(ref_difftest_init);
		// a value of type "void *" cannot be used to initialize an entity of type "void (*)(int)"
		ref_difftest_init(port);
		ref_difftest_memcpy(0, pmem, img_size, DIFFTEST_TO_REF);
		ref_difftest_regcpy(regs_val, DIFFTEST_TO_REF);
	}
	void difftest_step()
	{
		if (is_skip_ref)
		{
			is_skip_ref = 0;
			ref_difftest_memcpy(0, pmem, 0x8000000, DIFFTEST_TO_REF);
			ref_difftest_regcpy(regs_val, DIFFTEST_TO_REF);
			ref_difftest_exec(1);
			return;
		}
		else
		{
			uint32_t ref_regs[17];
			ref_difftest_regcpy(ref_regs, DIFFTEST_TO_DUT);
			if (top->pc != ref_regs[0])
			{
				printf("pc is different, ref %x, dut %x\n", ref_regs[0], top->pc);
				irbuf->print_iringbuf();
				printf("\n");
				assert(0);
			}
			for (int i = 0; i < sizeof(regs) / sizeof(regs[0]); i++)
			{
				if (top->regs[i] != ref_regs[i + 1])
				{
					printf("reg %s is different, ref %u, dut %u,pc = %x\n", regs[i], ref_regs[i + 1], top->regs[i], top->pc);
					irbuf->print_iringbuf();
					printf("\n");
					assert(0);
				}
			}
			ref_difftest_exec(1);
		}
	}
	void difftest_skip_ref()
	{
		is_skip_ref = 1;
	}
	static uint32_t get_reg(char *name, bool *success)
	{
		if (strcmp(name, "pc") == 0)
		{
			if (success != NULL)
				*success = true;
			return top->pc;
		}
		for (int i = 0; i < sizeof(regs) / sizeof(regs[0]); i++)
		{
			if (strcmp(name, regs[i]) == 0)
			{
				if (success != NULL)
					*success = true;
				return top->regs[i];
			}
		}
		if (success != NULL)
			*success = false;
		return 0;
	}
	void update_messages()
	{
		disassemble(disasm, sizeof(disasm), top->pc, (uint8_t *)&top->inst, 4);
		sprintf(message, "pc 0x%08x inst 0x%08x %s\n", top->pc, top->inst, disasm);
		regs_val[0] = top->pc;
		for (int i = 0; i < sizeof(regs) / sizeof(regs[0]); i++)
		{
			regs_val[i + 1] = top->regs[i];
		}
	}
	static Vtop *top;
	void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
	void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
	void (*ref_difftest_exec)(uint64_t n) = NULL;
	Iringbuf *irbuf = NULL;
	char ref_so_file[256] = "/home/pglzjz/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so";
	int port = 0;
	char message[64];
	char disasm[32];
	uint32_t regs_val[17];
	int is_skip_ref = 0;
};
