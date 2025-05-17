// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024unit.h"

extern "C" void ebreak_trigger();

VL_INLINE_OPT void Vtop___024unit____Vdpiimwrap_ebreak_trigger_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_ebreak_trigger_TOP____024unit\n"); );
    // Body
    ebreak_trigger();
}

extern "C" void unknown_inst(int inst);

VL_INLINE_OPT void Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(IData/*31:0*/ inst) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit\n"); );
    // Body
    int inst__Vcvt;
    for (size_t inst__Vidx = 0; inst__Vidx < 1; ++inst__Vidx) inst__Vcvt = inst;
    unknown_inst(inst__Vcvt);
}

extern "C" int paddr_read(int addr, int len, int is_fetch, int is_avail);

VL_INLINE_OPT void Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ is_fetch, IData/*31:0*/ is_avail, IData/*31:0*/ &paddr_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int len__Vcvt;
    for (size_t len__Vidx = 0; len__Vidx < 1; ++len__Vidx) len__Vcvt = len;
    int is_fetch__Vcvt;
    for (size_t is_fetch__Vidx = 0; is_fetch__Vidx < 1; ++is_fetch__Vidx) is_fetch__Vcvt = is_fetch;
    int is_avail__Vcvt;
    for (size_t is_avail__Vidx = 0; is_avail__Vidx < 1; ++is_avail__Vidx) is_avail__Vcvt = is_avail;
    int paddr_read__Vfuncrtn__Vcvt;
    paddr_read__Vfuncrtn__Vcvt = paddr_read(addr__Vcvt, len__Vcvt, is_fetch__Vcvt, is_avail__Vcvt);
    paddr_read__Vfuncrtn = paddr_read__Vfuncrtn__Vcvt;
}

extern "C" void paddr_write(int addr, int len, int data, int is_avail);

VL_INLINE_OPT void Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ data, IData/*31:0*/ is_avail) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit\n"); );
    // Body
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int len__Vcvt;
    for (size_t len__Vidx = 0; len__Vidx < 1; ++len__Vidx) len__Vcvt = len;
    int data__Vcvt;
    for (size_t data__Vidx = 0; data__Vidx < 1; ++data__Vidx) data__Vcvt = data;
    int is_avail__Vcvt;
    for (size_t is_avail__Vidx = 0; is_avail__Vidx < 1; ++is_avail__Vidx) is_avail__Vcvt = is_avail;
    paddr_write(addr__Vcvt, len__Vcvt, data__Vcvt, is_avail__Vcvt);
}
