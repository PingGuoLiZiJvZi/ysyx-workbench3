#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated.h"
#include "Sdb.h"
NPC_STATE Sdb::npc_state = NPC_RUNNING;
extern "C" void flash_read(int32_t addr, int32_t *data) { assert(0); }
extern "C" void mrom_read(int32_t addr, int32_t *data) { assert(0); }
extern "C" void ebreak_trigger()
{
	if (Npc::top->regs[10] == 0)
	{
		printf("HIT GOOD TRAP\n");
		Sdb::npc_state = NPC_STOP;
	}
	else
	{
		printf("HIT BAD TRAP\n");
		Sdb::npc_state = NPC_ABORT;
	}
}
extern "C" void unknown_inst(int inst)
{
	if (inst != 0)
	{
		printf("Unknown instruction %x\n", inst);
		assert(0);
	}
}
int main(int argc, char **argv)
{
	Sdb sdb(argc, argv);
	sdb.sdb_mainloop();
	int res = sdb.npc_state != NPC_QUIT;
	if (res)
	{
		sdb.print_iringbuf();
		return -1;
	}
	return 0;
}