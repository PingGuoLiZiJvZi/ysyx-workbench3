// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_YSYX_25040129_PC_H_
#define VERILATED_VTOP_YSYX_25040129_PC_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_ysyx_25040129_PC final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__rst,0,0);
    VL_IN(__PVT__next_pc,31,0);
    VL_OUT(__PVT__pc,31,0);
    IData/*31:0*/ __Vdly__pc;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_ysyx_25040129_PC(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_ysyx_25040129_PC();
    VL_UNCOPYABLE(Vtop_ysyx_25040129_PC);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
