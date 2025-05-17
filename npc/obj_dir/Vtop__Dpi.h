// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/pglzjz/ysyx-workbench/npc/vsrc/top.v:1:30
    extern void ebreak_trigger();
    // DPI import at /home/pglzjz/ysyx-workbench/npc/vsrc/top.v:3:29
    extern int paddr_read(int addr, int len, int is_fetch, int is_avail);
    // DPI import at /home/pglzjz/ysyx-workbench/npc/vsrc/top.v:4:30
    extern void paddr_write(int addr, int len, int data, int is_avail);
    // DPI import at /home/pglzjz/ysyx-workbench/npc/vsrc/top.v:2:30
    extern void unknown_inst(int inst);

#ifdef __cplusplus
}
#endif

#endif  // guard
