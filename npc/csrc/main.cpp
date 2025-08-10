#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated.h"
#include "Sdb.h"
#include "performance_counter.h"
Sdb *sdb = NULL;
uint32_t Npc::regs_val[33] = {0};
uint32_t Npc::inst = 0;
bool Npc::is_device = false;
bool Npc::wbu_state = 0;
NPC_STATE Sdb::npc_state = NPC_RUNNING;
extern "C" void ebreak_trigger()
{
	if (Npc::regs_val[11] == 0)
	{
		printf("HIT GOOD TRAP\n");
		print_performance_counters();
		exit(0);
		Sdb::npc_state = NPC_STOP;
	}
	else
	{
		printf("HIT BAD TRAP\n");
		sdb->npc.reg_display();
		sdb->print_iringbuf();
#ifdef WAVE
		sdb->npc.tfp->flush();
#endif
		exit(-1);
		Sdb::npc_state = NPC_ABORT;
	}
}
extern "C" void unknown_inst(int inst)
{
	if (inst != 0)
	{
		printf("Unknown instruction %x\n", inst);
		sdb->print_iringbuf();
		sdb->npc.reg_display();
#ifdef WAVE
		sdb->npc.tfp->flush();
#endif
		assert(0);
	}
}
extern "C" void update_regs(int reg1, int reg2, int reg3, int reg4, int reg5, int reg6, int reg7, int reg8,
							int reg9, int reg10, int reg11, int reg12, int reg13, int reg14, int reg15, int reg16,
							int reg17, int reg18, int reg19, int reg20, int reg21, int reg22, int reg23, int reg24,
							int reg25, int reg26, int reg27, int reg28, int reg29, int reg30, int reg31, int reg32)
{
	Npc::regs_val[1] = reg1;
	Npc::regs_val[2] = reg2;
	Npc::regs_val[3] = reg3;
	Npc::regs_val[4] = reg4;
	Npc::regs_val[5] = reg5;
	Npc::regs_val[6] = reg6;
	Npc::regs_val[7] = reg7;
	Npc::regs_val[8] = reg8;
	Npc::regs_val[9] = reg9;
	Npc::regs_val[10] = reg10;
	Npc::regs_val[11] = reg11;
	Npc::regs_val[12] = reg12;
	Npc::regs_val[13] = reg13;
	Npc::regs_val[14] = reg14;
	Npc::regs_val[15] = reg15;
	Npc::regs_val[16] = reg16;
	Npc::regs_val[17] = reg17;
	Npc::regs_val[18] = reg18;
	Npc::regs_val[19] = reg19;
	Npc::regs_val[20] = reg20;
	Npc::regs_val[21] = reg21;
	Npc::regs_val[22] = reg22;
	Npc::regs_val[23] = reg23;
	Npc::regs_val[24] = reg24;
	Npc::regs_val[25] = reg25;
	Npc::regs_val[26] = reg26;
	Npc::regs_val[27] = reg27;
	Npc::regs_val[28] = reg28;
	Npc::regs_val[29] = reg29;
	Npc::regs_val[30] = reg30;
	Npc::regs_val[31] = reg31;
	Npc::regs_val[32] = reg32;
}
extern "C" void update_pc(uint32_t pc)
{
	Npc::regs_val[0] = pc;
}
extern "C" void update_inst(uint32_t inst)
{
	Npc::inst = inst;
}
extern "C" void update_is_device(bool is_device)
{
	Npc::is_device = is_device;
}
extern "C" void update_wbu_state(bool wbu_state)
{
	Npc::wbu_state = wbu_state;
}
int main(int argc, char **argv)
{
	sdb = new Sdb(argc, argv);
	sdb->sdb_mainloop();
	int res = sdb->npc_state != NPC_QUIT;
	if (res)
	{
		sdb->print_iringbuf();
		return -1;
	}
	return 0;
}