// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ysyx_25040129_IFU.h"

VL_ATTR_COLD void Vtop_ysyx_25040129_IFU___stl_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_IFU__1(Vtop_ysyx_25040129_IFU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_IFU___stl_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_IFU__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__next_pc = ((IData)(vlSelfRef.__PVT__ecall)
                                 ? vlSelfRef.__PVT__mtvec
                                 : ((IData)(vlSelfRef.__PVT__mret)
                                     ? vlSelfRef.__PVT__mepc
                                     : ((IData)(vlSelfRef.__PVT__is_branch)
                                         ? vlSelfRef.__PVT__jump_target
                                         : ((0U == vlSelfRef.__PVT__pc)
                                             ? 0x80000000U
                                             : ((IData)(4U) 
                                                + vlSelfRef.__PVT__pc)))));
}

VL_ATTR_COLD void Vtop_ysyx_25040129_IFU___ctor_var_reset(Vtop_ysyx_25040129_IFU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_IFU___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__is_branch = VL_RAND_RESET_I(1);
    vlSelf->__PVT__mret = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ecall = VL_RAND_RESET_I(1);
    vlSelf->__PVT__jump_target = VL_RAND_RESET_I(32);
    vlSelf->__PVT__mepc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__mtvec = VL_RAND_RESET_I(32);
    vlSelf->__PVT__inst = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_paddr_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_paddr_read__1__Vfuncout = 0;
}
