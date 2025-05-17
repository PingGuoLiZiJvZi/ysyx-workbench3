// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_YSYX_25040129_MEM_H_
#define VERILATED_VTOP_YSYX_25040129_MEM_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_ysyx_25040129_MEM final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__opcode,6,0);
    VL_IN8(__PVT__funct3,2,0);
    CData/*2:0*/ __PVT__write_len;
    CData/*0:0*/ __PVT__is_avail_read;
    CData/*0:0*/ __PVT__is_avail_write;
    VL_IN(__PVT__imm,31,0);
    VL_IN(__PVT__src1,31,0);
    VL_IN(__PVT__src2,31,0);
    VL_OUT(__PVT__read_data,31,0);
    IData/*31:0*/ __PVT__addr;
    IData/*31:0*/ __Vfunc_paddr_read__0__Vfuncout;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_ysyx_25040129_MEM(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_ysyx_25040129_MEM();
    VL_UNCOPYABLE(Vtop_ysyx_25040129_MEM);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
