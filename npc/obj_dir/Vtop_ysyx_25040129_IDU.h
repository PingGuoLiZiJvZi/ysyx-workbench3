// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_YSYX_25040129_IDU_H_
#define VERILATED_VTOP_YSYX_25040129_IDU_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_ysyx_25040129_IDU final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_OUT8(__PVT__src1_id,4,0);
    VL_OUT8(__PVT__src2_id,4,0);
    VL_OUT8(__PVT__rd,4,0);
    VL_OUT8(__PVT__funct7,6,0);
    VL_OUT8(__PVT__funct3,2,0);
    VL_OUT8(__PVT__opcode,6,0);
    VL_OUT8(__PVT__reg_write,0,0);
    VL_OUT8(__PVT__ecall,0,0);
    VL_OUT8(__PVT__ebreak,0,0);
    VL_OUT8(__PVT__mret,0,0);
    VL_OUT8(__PVT__csr_write,0,0);
    VL_OUT8(__PVT__csr_read,0,0);
    VL_IN(__PVT__inst,31,0);
    VL_OUT(__PVT__imm,31,0);

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_ysyx_25040129_IDU(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_ysyx_25040129_IDU();
    VL_UNCOPYABLE(Vtop_ysyx_25040129_IDU);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
