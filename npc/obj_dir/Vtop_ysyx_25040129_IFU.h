// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_YSYX_25040129_IFU_H_
#define VERILATED_VTOP_YSYX_25040129_IFU_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_ysyx_25040129_IFU final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__is_branch,0,0);
    VL_IN(__PVT__pc,31,0);
    VL_OUT(__PVT__next_pc,31,0);
    VL_IN(__PVT__jump_target,31,0);
    VL_OUT(__PVT__inst,31,0);
    IData/*31:0*/ __Vfunc_paddr_read__0__Vfuncout;
    IData/*31:0*/ __Vfunc_paddr_read__1__Vfuncout;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_ysyx_25040129_IFU(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_ysyx_25040129_IFU();
    VL_UNCOPYABLE(Vtop_ysyx_25040129_IFU);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
