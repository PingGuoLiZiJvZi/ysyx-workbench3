// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ysyx_25040129_PC.h"

VL_INLINE_OPT void Vtop_ysyx_25040129_PC___nba_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_PC__0(Vtop_ysyx_25040129_PC* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_PC___nba_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_PC__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__pc = vlSelfRef.__PVT__pc;
    vlSelfRef.__Vdly__pc = ((IData)(vlSelfRef.__PVT__rst)
                             ? 0x80000000U : vlSelfRef.__PVT__next_pc);
    vlSelfRef.__PVT__pc = vlSelfRef.__Vdly__pc;
}
