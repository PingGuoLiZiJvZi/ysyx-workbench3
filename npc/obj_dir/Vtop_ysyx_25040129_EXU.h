// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_YSYX_25040129_EXU_H_
#define VERILATED_VTOP_YSYX_25040129_EXU_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_ysyx_25040129_EXU final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__funct7,6,0);
    VL_IN8(__PVT__funct3,2,0);
    VL_IN8(__PVT__opcode,6,0);
    VL_IN(__PVT__pc,31,0);
    VL_IN(__PVT__src1,31,0);
    VL_IN(__PVT__src2,31,0);
    VL_IN(__PVT__imm,31,0);
    VL_OUT(__PVT__result,31,0);
    VL_IN(__PVT__read_data,31,0);

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_ysyx_25040129_EXU(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_ysyx_25040129_EXU();
    VL_UNCOPYABLE(Vtop_ysyx_25040129_EXU);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
