// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_YSYX_25040129_REG_H_
#define VERILATED_VTOP_YSYX_25040129_REG_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_ysyx_25040129_REG final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__rst,0,0);
    VL_IN8(__PVT__rd,4,0);
    VL_IN8(__PVT__reg_write,0,0);
    VL_IN8(__PVT__src1_id,4,0);
    VL_IN8(__PVT__src2_id,4,0);
    VL_IN(__PVT__result,31,0);
    VL_OUT(__PVT__src1,31,0);
    VL_OUT(__PVT__src2,31,0);
    VL_OUTW(__PVT__regs_out,511,0,16);
    VlWide<16>/*511:0*/ __PVT__regs;
    VlWide<16>/*511:0*/ __Vdly__regs;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_ysyx_25040129_REG(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_ysyx_25040129_REG();
    VL_UNCOPYABLE(Vtop_ysyx_25040129_REG);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
