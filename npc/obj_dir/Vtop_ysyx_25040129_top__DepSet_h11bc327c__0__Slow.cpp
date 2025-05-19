// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ysyx_25040129_top.h"

VL_ATTR_COLD void Vtop_ysyx_25040129_top___ctor_var_reset(Vtop_ysyx_25040129_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_ysyx_25040129_top___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->inst = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(512, vlSelf->regs);
    vlSelf->__PVT__src1_id = VL_RAND_RESET_I(5);
    vlSelf->__PVT__src1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__src2_id = VL_RAND_RESET_I(5);
    vlSelf->__PVT__src2 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__imm = VL_RAND_RESET_I(32);
    vlSelf->__PVT__result = VL_RAND_RESET_I(32);
    vlSelf->__PVT__rd = VL_RAND_RESET_I(5);
    vlSelf->__PVT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__funct7 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__opcode = VL_RAND_RESET_I(7);
    vlSelf->__PVT__jump_target = VL_RAND_RESET_I(32);
    vlSelf->__PVT__mepc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__mtvec = VL_RAND_RESET_I(32);
    vlSelf->__PVT__is_branch = VL_RAND_RESET_I(1);
    vlSelf->__PVT__reg_write = VL_RAND_RESET_I(1);
    vlSelf->__PVT__mret = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ecall = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ebreak = VL_RAND_RESET_I(1);
    vlSelf->__PVT__csr_write = VL_RAND_RESET_I(1);
    vlSelf->__PVT__csr_read = VL_RAND_RESET_I(1);
    vlSelf->__PVT__csr_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__read_data = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(512, vlSelf->__Vcellout__u_ysyx_25040129_REG__regs_out);
    vlSelf->__Vcellinp__u_ysyx_25040129_CSR__csr_addr = VL_RAND_RESET_I(12);
}
