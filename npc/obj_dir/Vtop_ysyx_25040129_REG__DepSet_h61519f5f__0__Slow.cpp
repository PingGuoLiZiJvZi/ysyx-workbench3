// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ysyx_25040129_REG.h"

VL_ATTR_COLD void Vtop_ysyx_25040129_REG___stl_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_REG__0(Vtop_ysyx_25040129_REG* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_REG___stl_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_REG__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_ASSIGN_W(512,vlSelfRef.__PVT__regs_out, vlSelfRef.__PVT__regs);
}

VL_ATTR_COLD void Vtop_ysyx_25040129_REG___stl_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_REG__1(Vtop_ysyx_25040129_REG* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_REG___stl_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_REG__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__src2 = VL_SEL_IWII(512, vlSelfRef.__PVT__regs, 
                                        (0x1ffU & VL_SEL_IIII(32, 
                                                              VL_SHIFTL_III(32,32,32, 
                                                                            VL_EXTEND_II(32,5, (IData)(vlSelfRef.__PVT__src2_id)), 5U), 0U, 9U)), 0x20U);
    vlSelfRef.__PVT__src1 = VL_SEL_IWII(512, vlSelfRef.__PVT__regs, 
                                        (0x1ffU & VL_SEL_IIII(32, 
                                                              VL_SHIFTL_III(32,32,32, 
                                                                            VL_EXTEND_II(32,5, (IData)(vlSelfRef.__PVT__src1_id)), 5U), 0U, 9U)), 0x20U);
}

VL_ATTR_COLD void Vtop_ysyx_25040129_REG___ctor_var_reset(Vtop_ysyx_25040129_REG* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_REG___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__clk = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rd = VL_RAND_RESET_I(5);
    vlSelf->__PVT__reg_write = VL_RAND_RESET_I(1);
    vlSelf->__PVT__result = VL_RAND_RESET_I(32);
    vlSelf->__PVT__src1_id = VL_RAND_RESET_I(5);
    vlSelf->__PVT__src2_id = VL_RAND_RESET_I(5);
    vlSelf->__PVT__src1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__src2 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(512, vlSelf->__PVT__regs_out);
    VL_RAND_RESET_W(512, vlSelf->__PVT__regs);
    VL_RAND_RESET_W(512, vlSelf->__Vdly__regs);
}
