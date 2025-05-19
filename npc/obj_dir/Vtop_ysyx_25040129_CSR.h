// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_YSYX_25040129_CSR_H_
#define VERILATED_VTOP_YSYX_25040129_CSR_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_ysyx_25040129_CSR final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__csr_write,0,0);
    VL_IN8(__PVT__csr_read,0,0);
    VL_IN8(__PVT__ecall,0,0);
    VL_IN16(__PVT__csr_addr,11,0);
    VL_IN(__PVT__csr_data,31,0);
    VL_OUT(__PVT__csr_out,31,0);
    VL_IN(__PVT__mepc_data,31,0);
    VL_IN(__PVT__mstate_data,31,0);
    VL_IN(__PVT__mcause_data,31,0);
    VL_OUT(__PVT__mtvec,31,0);
    VL_OUT(__PVT__mepc,31,0);
    IData/*31:0*/ __PVT__mstatus;
    IData/*31:0*/ __PVT__mcause;
    IData/*31:0*/ __Vdly__mepc;
    IData/*31:0*/ __Vdly__mstatus;
    IData/*31:0*/ __Vdly__mcause;
    IData/*31:0*/ __Vdly__mtvec;
    IData/*31:0*/ __Vdly__csr_out;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_ysyx_25040129_CSR(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_ysyx_25040129_CSR();
    VL_UNCOPYABLE(Vtop_ysyx_25040129_CSR);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
