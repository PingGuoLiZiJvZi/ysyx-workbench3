// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ysyx_25040129_MEM.h"

VL_INLINE_OPT void Vtop_ysyx_25040129_MEM___nba_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_MEM__0(Vtop_ysyx_25040129_MEM* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_MEM___nba_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_MEM__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__is_avail_read = (3U == (IData)(vlSelfRef.__PVT__opcode));
    vlSelfRef.__PVT__is_avail_write = (0x23U == (IData)(vlSelfRef.__PVT__opcode));
}
