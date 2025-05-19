// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ysyx_25040129_EXU.h"

VL_ATTR_COLD void Vtop_ysyx_25040129_EXU___ctor_var_reset(Vtop_ysyx_25040129_EXU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_EXU___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__src1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__src2 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__imm = VL_RAND_RESET_I(32);
    vlSelf->__PVT__funct7 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__opcode = VL_RAND_RESET_I(7);
    vlSelf->__PVT__result = VL_RAND_RESET_I(32);
    vlSelf->__PVT__read_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__ebreak = VL_RAND_RESET_I(1);
    vlSelf->__PVT__csr_read = VL_RAND_RESET_I(1);
    vlSelf->__PVT__csr_data = VL_RAND_RESET_I(32);
}
