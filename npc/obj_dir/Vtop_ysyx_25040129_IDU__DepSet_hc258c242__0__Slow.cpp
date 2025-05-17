// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ysyx_25040129_IDU.h"

VL_ATTR_COLD void Vtop_ysyx_25040129_IDU___ctor_var_reset(Vtop_ysyx_25040129_IDU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_IDU___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__inst = VL_RAND_RESET_I(32);
    vlSelf->__PVT__src1_id = VL_RAND_RESET_I(5);
    vlSelf->__PVT__src2_id = VL_RAND_RESET_I(5);
    vlSelf->__PVT__imm = VL_RAND_RESET_I(32);
    vlSelf->__PVT__rd = VL_RAND_RESET_I(5);
    vlSelf->__PVT__funct7 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__opcode = VL_RAND_RESET_I(7);
    vlSelf->__PVT__reg_write = VL_RAND_RESET_I(1);
}
