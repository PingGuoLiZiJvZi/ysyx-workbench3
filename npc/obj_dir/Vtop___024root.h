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
    VL_OUT8(ifu_state,2,0);
    CData/*0:0*/ ysyx_25040129_top__DOT__is_rsp_valid_from_mmem_to_ifu;
    CData/*0:0*/ ysyx_25040129_top__DOT__is_jalr_out_idu;
    CData/*3:0*/ ysyx_25040129_top__DOT__alu_opcode;
    CData/*0:0*/ ysyx_25040129_top__DOT__reg_write_out_idu;
    CData/*1:0*/ ysyx_25040129_top__DOT__lsu_write_out_idu;
    CData/*2:0*/ ysyx_25040129_top__DOT__lsu_read_out_idu;
    CData/*0:0*/ ysyx_25040129_top__DOT__ecall_out_idu;
    CData/*0:0*/ ysyx_25040129_top__DOT__is_jump_out_idu;
    CData/*0:0*/ ysyx_25040129_top__DOT__ebreak_out_idu;
    CData/*0:0*/ ysyx_25040129_top__DOT__mret_out_idu;
    CData/*0:0*/ ysyx_25040129_top__DOT__csr_write_out_idu;
    CData/*0:0*/ ysyx_25040129_top__DOT__is_req_valid_from_lsu_to_mmem;
    CData/*0:0*/ ysyx_25040129_top__DOT__is_rsp_valid_from_mmem_to_lsu;
    CData/*0:0*/ ysyx_25040129_top__DOT__csr_write_out_wbu;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_IFU__DOT__state;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_IFU__DOT__next_state;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_IFU__DOT__next_state;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_IDU__DOT__state;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_IDU__DOT__next_state;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__state;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__next_state;
    CData/*0:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__is_branch;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__next_state;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_LSU__DOT__state;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_LSU__DOT__next_state;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_WBU__DOT__state;
    CData/*2:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_WBU__DOT__next_state;
    CData/*0:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_WBU__DOT____VdfgRegularize_h4ef58c57_2_0;
    CData/*4:0*/ __Vtableidx1;
    CData/*6:0*/ __Vtableidx2;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_OUTW(regs,511,0,16);
    SData/*9:0*/ __Vtableidx3;
    VL_OUT(pc,31,0);
    VL_OUT(inst,31,0);
    IData/*31:0*/ ysyx_25040129_top__DOT__inst_from_mmem;
    IData/*31:0*/ ysyx_25040129_top__DOT__pc_from_ifu;
    IData/*31:0*/ ysyx_25040129_top__DOT__inst_to_idu;
    IData/*31:0*/ ysyx_25040129_top__DOT__src2_in_idu;
    IData/*31:0*/ ysyx_25040129_top__DOT__src1_out_idu;
    IData/*31:0*/ ysyx_25040129_top__DOT__src2_out_idu;
    IData/*31:0*/ ysyx_25040129_top__DOT__imm;
    IData/*31:0*/ ysyx_25040129_top__DOT__result_out_exu;
    IData/*31:0*/ ysyx_25040129_top__DOT__branch_target_out_exu;
    IData/*31:0*/ ysyx_25040129_top__DOT__result_out_lsu;
    IData/*31:0*/ ysyx_25040129_top__DOT__mmem_read_data_in_lsu;
    IData/*31:0*/ ysyx_25040129_top__DOT__target_from_csr_to_wbu;
    VlWide<16>/*511:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs;
    IData/*31:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mepc;
    IData/*31:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus;
    IData/*31:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mcause;
    IData/*31:0*/ ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mtvec;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
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
