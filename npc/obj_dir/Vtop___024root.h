// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop___024unit;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ ysyx_25040129_top__DOT__reg_write;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_MEM__DOT__write_len;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_OUTW(regs,511,0,16);
    VL_OUT(pc,31,0);
    VL_OUT(inst,31,0);
    IData/*31:0*/ ysyx_25040129_top__DOT__src1;
    IData/*31:0*/ ysyx_25040129_top__DOT__src2;
    IData/*31:0*/ ysyx_25040129_top__DOT__imm;
    IData/*31:0*/ ysyx_25040129_top__DOT__result;
    IData/*31:0*/ ysyx_25040129_top__DOT__next_pc;
    IData/*31:0*/ ysyx_25040129_top__DOT__read_data;
    VlWide<16>/*511:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs;
    IData/*31:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_MEM__DOT__addr;
    IData/*31:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_MEM__DOT____VdfgExtracted_haa08dfc0__0;
    IData/*31:0*/ __Vfunc_paddr_read__0__Vfuncout;
    IData/*31:0*/ __Vfunc_paddr_read__1__Vfuncout;
    IData/*31:0*/ __Vfunc_paddr_read__35__Vfuncout;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
