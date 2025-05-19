// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_YSYX_25040129_TOP_H_
#define VERILATED_VTOP_YSYX_25040129_TOP_H_  // guard

#include "verilated.h"
class Vtop_ysyx_25040129_BRC;
class Vtop_ysyx_25040129_CSR;
class Vtop_ysyx_25040129_EXU;
class Vtop_ysyx_25040129_IDU;
class Vtop_ysyx_25040129_IFU;
class Vtop_ysyx_25040129_MEM;
class Vtop_ysyx_25040129_PC;
class Vtop_ysyx_25040129_REG;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_ysyx_25040129_top final : public VerilatedModule {
  public:
    // CELLS
    Vtop_ysyx_25040129_REG* __PVT__u_ysyx_25040129_REG;
    Vtop_ysyx_25040129_PC* __PVT__u_ysyx_25040129_PC;
    Vtop_ysyx_25040129_IFU* __PVT__u_ysyx_25040129_IFU;
    Vtop_ysyx_25040129_IDU* __PVT__u_ysyx_25040129_IDU;
    Vtop_ysyx_25040129_EXU* __PVT__u_ysyx_25040129_EXU;
    Vtop_ysyx_25040129_BRC* __PVT__u_ysyx_25040129_BRC;
    Vtop_ysyx_25040129_MEM* __PVT__u_ysyx_25040129_MEM;
    Vtop_ysyx_25040129_CSR* __PVT__u_ysyx_25040129_CSR;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*4:0*/ __PVT__src1_id;
    CData/*4:0*/ __PVT__src2_id;
    CData/*4:0*/ __PVT__rd;
    CData/*6:0*/ __PVT__funct7;
    CData/*2:0*/ __PVT__funct3;
    CData/*6:0*/ __PVT__opcode;
    CData/*0:0*/ __PVT__is_branch;
    CData/*0:0*/ __PVT__reg_write;
    CData/*0:0*/ __PVT__mret;
    CData/*0:0*/ __PVT__ecall;
    CData/*0:0*/ __PVT__ebreak;
    CData/*0:0*/ __PVT__csr_write;
    CData/*0:0*/ __PVT__csr_read;
    VL_OUTW(regs,511,0,16);
    SData/*11:0*/ __Vcellinp__u_ysyx_25040129_CSR__csr_addr;
    VL_OUT(pc,31,0);
    VL_OUT(inst,31,0);
    IData/*31:0*/ __PVT__src1;
    IData/*31:0*/ __PVT__src2;
    IData/*31:0*/ __PVT__imm;
    IData/*31:0*/ __PVT__result;
    IData/*31:0*/ __PVT__next_pc;
    IData/*31:0*/ __PVT__jump_target;
    IData/*31:0*/ __PVT__mepc;
    IData/*31:0*/ __PVT__mtvec;
    IData/*31:0*/ __PVT__csr_data;
    IData/*31:0*/ __PVT__read_data;
    VlWide<16>/*511:0*/ __Vcellout__u_ysyx_25040129_REG__regs_out;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_ysyx_25040129_top(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_ysyx_25040129_top();
    VL_UNCOPYABLE(Vtop_ysyx_25040129_top);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
