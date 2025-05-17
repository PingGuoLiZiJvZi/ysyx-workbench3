// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ysyx_25040129_MEM.h"

VL_ATTR_COLD void Vtop_ysyx_25040129_MEM___stl_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_MEM__0(Vtop_ysyx_25040129_MEM* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_MEM___stl_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_MEM__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__is_avail_read = (3U == (IData)(vlSelfRef.__PVT__opcode));
    vlSelfRef.__PVT__is_avail_write = (0x23U == (IData)(vlSelfRef.__PVT__opcode));
}

VL_ATTR_COLD void Vtop_ysyx_25040129_MEM___ctor_var_reset(Vtop_ysyx_25040129_MEM* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_MEM___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__opcode = VL_RAND_RESET_I(7);
    vlSelf->__PVT__imm = VL_RAND_RESET_I(32);
    vlSelf->__PVT__src1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__src2 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->__PVT__read_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__write_len = VL_RAND_RESET_I(3);
    vlSelf->__PVT__is_avail_read = VL_RAND_RESET_I(1);
    vlSelf->__PVT__is_avail_write = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_paddr_read__0__Vfuncout = 0;
}
