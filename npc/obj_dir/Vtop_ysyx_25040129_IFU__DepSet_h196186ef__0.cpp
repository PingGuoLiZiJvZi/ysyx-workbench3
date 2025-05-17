// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ysyx_25040129_IFU.h"

VL_INLINE_OPT void Vtop_ysyx_25040129_IFU___nba_comb__TOP__ysyx_25040129_top__u_ysyx_25040129_IFU__0(Vtop_ysyx_25040129_IFU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_IFU___nba_comb__TOP__ysyx_25040129_top__u_ysyx_25040129_IFU__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__next_pc = ((IData)(vlSelfRef.__PVT__is_branch)
                                 ? vlSelfRef.__PVT__jump_target
                                 : ((IData)(4U) + vlSelfRef.__PVT__pc));
}
