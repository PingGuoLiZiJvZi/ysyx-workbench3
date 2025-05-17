// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ysyx_25040129_PC.h"

VL_ATTR_COLD void Vtop_ysyx_25040129_PC___ctor_var_reset(Vtop_ysyx_25040129_PC* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_PC___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__clk = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__pc = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__pc = VL_RAND_RESET_I(32);
}
