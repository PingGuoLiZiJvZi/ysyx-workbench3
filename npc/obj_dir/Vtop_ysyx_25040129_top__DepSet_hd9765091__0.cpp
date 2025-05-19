// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_ysyx_25040129_top.h"

VL_INLINE_OPT void Vtop_ysyx_25040129_top___ico_sequent__TOP__ysyx_25040129_top__0(Vtop_ysyx_25040129_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_ysyx_25040129_top___ico_sequent__TOP__ysyx_25040129_top__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_REG.__PVT__rst 
        = vlSelfRef.rst;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_PC.__PVT__rst 
        = vlSelfRef.rst;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_REG.__PVT__clk 
        = vlSelfRef.clk;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_PC.__PVT__clk 
        = vlSelfRef.clk;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_CSR.__PVT__clk 
        = vlSelfRef.clk;
}

VL_INLINE_OPT void Vtop_ysyx_25040129_top___nba_sequent__TOP__ysyx_25040129_top__0(Vtop_ysyx_25040129_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_ysyx_25040129_top___nba_sequent__TOP__ysyx_25040129_top__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__mepc = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_CSR.__PVT__mepc;
    vlSelfRef.__PVT__mtvec = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_CSR.__PVT__mtvec;
    vlSelfRef.__PVT__csr_data = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_CSR.__PVT__csr_out;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IFU.__PVT__mepc 
        = vlSelfRef.__PVT__mepc;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IFU.__PVT__mtvec 
        = vlSelfRef.__PVT__mtvec;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_CSR.__PVT__csr_data 
        = vlSelfRef.__PVT__csr_data;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_EXU.__PVT__csr_data 
        = vlSelfRef.__PVT__csr_data;
}

VL_INLINE_OPT void Vtop_ysyx_25040129_top___nba_sequent__TOP__ysyx_25040129_top__1(Vtop_ysyx_25040129_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_ysyx_25040129_top___nba_sequent__TOP__ysyx_25040129_top__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_ASSIGN_W(512,vlSelfRef.__Vcellout__u_ysyx_25040129_REG__regs_out, vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_REG.__PVT__regs_out);
    VL_ASSIGN_W(512,vlSelfRef.regs, vlSelfRef.__Vcellout__u_ysyx_25040129_REG__regs_out);
}

VL_INLINE_OPT void Vtop_ysyx_25040129_top___nba_sequent__TOP__ysyx_25040129_top__2(Vtop_ysyx_25040129_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_ysyx_25040129_top___nba_sequent__TOP__ysyx_25040129_top__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_PC.__PVT__pc;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_CSR.__PVT__mepc_data 
        = vlSelfRef.pc;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_EXU.__PVT__pc 
        = vlSelfRef.pc;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_BRC.__PVT__pc 
        = vlSelfRef.pc;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IFU.__PVT__pc 
        = vlSelfRef.pc;
}

VL_INLINE_OPT void Vtop_ysyx_25040129_top___nba_sequent__TOP__ysyx_25040129_top__3(Vtop_ysyx_25040129_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_ysyx_25040129_top___nba_sequent__TOP__ysyx_25040129_top__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.inst = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IFU.__PVT__inst;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__inst 
        = vlSelfRef.inst;
}

VL_INLINE_OPT void Vtop_ysyx_25040129_top___nba_sequent__TOP__ysyx_25040129_top__4(Vtop_ysyx_25040129_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_ysyx_25040129_top___nba_sequent__TOP__ysyx_25040129_top__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rd = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__rd;
    vlSelfRef.__PVT__funct7 = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__funct7;
    vlSelfRef.__PVT__src2_id = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__src2_id;
    vlSelfRef.__PVT__src1_id = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__src1_id;
    vlSelfRef.__PVT__funct3 = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__funct3;
    vlSelfRef.__PVT__opcode = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__opcode;
    vlSelfRef.__PVT__reg_write = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__reg_write;
    vlSelfRef.__PVT__csr_write = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__csr_write;
    vlSelfRef.__PVT__mret = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__mret;
    vlSelfRef.__PVT__ecall = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__ecall;
    vlSelfRef.__PVT__ebreak = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__ebreak;
    vlSelfRef.__PVT__csr_read = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__csr_read;
    vlSelfRef.__PVT__imm = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IDU.__PVT__imm;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_REG.__PVT__rd 
        = vlSelfRef.__PVT__rd;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_EXU.__PVT__funct7 
        = vlSelfRef.__PVT__funct7;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_REG.__PVT__src2_id 
        = vlSelfRef.__PVT__src2_id;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_REG.__PVT__src1_id 
        = vlSelfRef.__PVT__src1_id;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_EXU.__PVT__funct3 
        = vlSelfRef.__PVT__funct3;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_MEM.__PVT__funct3 
        = vlSelfRef.__PVT__funct3;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_BRC.__PVT__funct3 
        = vlSelfRef.__PVT__funct3;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_EXU.__PVT__opcode 
        = vlSelfRef.__PVT__opcode;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_BRC.__PVT__opcode 
        = vlSelfRef.__PVT__opcode;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_MEM.__PVT__opcode 
        = vlSelfRef.__PVT__opcode;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_REG.__PVT__reg_write 
        = vlSelfRef.__PVT__reg_write;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_CSR.__PVT__csr_write 
        = vlSelfRef.__PVT__csr_write;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IFU.__PVT__mret 
        = vlSelfRef.__PVT__mret;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_CSR.__PVT__ecall 
        = vlSelfRef.__PVT__ecall;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IFU.__PVT__ecall 
        = vlSelfRef.__PVT__ecall;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_EXU.__PVT__ebreak 
        = vlSelfRef.__PVT__ebreak;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_CSR.__PVT__csr_read 
        = vlSelfRef.__PVT__csr_read;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_EXU.__PVT__csr_read 
        = vlSelfRef.__PVT__csr_read;
    vlSelfRef.__Vcellinp__u_ysyx_25040129_CSR__csr_addr 
        = (0xfffU & VL_SEL_IIII(32, vlSelfRef.__PVT__imm, 0U, 0xcU));
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_EXU.__PVT__imm 
        = vlSelfRef.__PVT__imm;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_MEM.__PVT__imm 
        = vlSelfRef.__PVT__imm;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_BRC.__PVT__imm 
        = vlSelfRef.__PVT__imm;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_CSR.__PVT__csr_addr 
        = vlSelfRef.__Vcellinp__u_ysyx_25040129_CSR__csr_addr;
}

VL_INLINE_OPT void Vtop_ysyx_25040129_top___nba_comb__TOP__ysyx_25040129_top__0(Vtop_ysyx_25040129_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_ysyx_25040129_top___nba_comb__TOP__ysyx_25040129_top__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__src2 = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_REG.__PVT__src2;
    vlSelfRef.__PVT__src1 = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_REG.__PVT__src1;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_EXU.__PVT__src2 
        = vlSelfRef.__PVT__src2;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_MEM.__PVT__src2 
        = vlSelfRef.__PVT__src2;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_BRC.__PVT__src2 
        = vlSelfRef.__PVT__src2;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_EXU.__PVT__src1 
        = vlSelfRef.__PVT__src1;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_MEM.__PVT__src1 
        = vlSelfRef.__PVT__src1;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_BRC.__PVT__src1 
        = vlSelfRef.__PVT__src1;
}

VL_INLINE_OPT void Vtop_ysyx_25040129_top___nba_comb__TOP__ysyx_25040129_top__1(Vtop_ysyx_25040129_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_ysyx_25040129_top___nba_comb__TOP__ysyx_25040129_top__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__read_data = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_MEM.__PVT__read_data;
    vlSelfRef.__PVT__is_branch = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_BRC.__PVT__is_branch;
    vlSelfRef.__PVT__jump_target = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_BRC.__PVT__branch_target;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_EXU.__PVT__read_data 
        = vlSelfRef.__PVT__read_data;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IFU.__PVT__is_branch 
        = vlSelfRef.__PVT__is_branch;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IFU.__PVT__jump_target 
        = vlSelfRef.__PVT__jump_target;
}

VL_INLINE_OPT void Vtop_ysyx_25040129_top___nba_comb__TOP__ysyx_25040129_top__2(Vtop_ysyx_25040129_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_ysyx_25040129_top___nba_comb__TOP__ysyx_25040129_top__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__result = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_EXU.__PVT__result;
    vlSelfRef.__PVT__next_pc = vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_IFU.__PVT__next_pc;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_REG.__PVT__result 
        = vlSelfRef.__PVT__result;
    vlSymsp->TOP__ysyx_25040129_top__u_ysyx_25040129_PC.__PVT__next_pc 
        = vlSelfRef.__PVT__next_pc;
}
