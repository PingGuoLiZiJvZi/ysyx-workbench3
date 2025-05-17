#pragma once
#include <dlfcn.h>
#include <capstone/capstone.h>
#include <assert.h>

static size_t (*cs_disasm_dl)(csh handle, const uint8_t *code,
							  size_t code_size, uint64_t address, size_t count, cs_insn **insn);
static void (*cs_free_dl)(cs_insn *insn, size_t count);

static csh handle;

void init_disasm();
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);