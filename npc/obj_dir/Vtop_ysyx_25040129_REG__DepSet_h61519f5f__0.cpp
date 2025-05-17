// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ysyx_25040129_REG.h"

extern const VlWide<16>/*511:0*/ Vtop__ConstPool__CONST_h93e1b771_0;

VL_INLINE_OPT void Vtop_ysyx_25040129_REG___nba_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_REG__0(Vtop_ysyx_25040129_REG* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_REG___nba_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_REG__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_ASSIGN_W(512,vlSelfRef.__Vdly__regs, vlSelfRef.__PVT__regs);
    if (vlSelfRef.__PVT__rst) {
        VL_ASSIGN_W(512,vlSelfRef.__Vdly__regs, Vtop__ConstPool__CONST_h93e1b771_0);
    } else if (((0U != (IData)(vlSelfRef.__PVT__rd)) 
                & (IData)(vlSelfRef.__PVT__reg_write))) {
        VL_ASSIGNSEL_WI(512,32,(0x1ffU & VL_SEL_IIII(32, 
                                                     VL_SHIFTL_III(32,32,32, 
                                                                   VL_EXTEND_II(32,5, (IData)(vlSelfRef.__PVT__rd)), 5U), 0U, 9U)), vlSelfRef.__Vdly__regs, vlSelfRef.__PVT__result);
    }
    VL_ASSIGN_W(512,vlSelfRef.__PVT__regs, vlSelfRef.__Vdly__regs);
    VL_ASSIGN_W(512,vlSelfRef.__PVT__regs_out, vlSelfRef.__PVT__regs);
}

VL_INLINE_OPT void Vtop_ysyx_25040129_REG___nba_comb__TOP__ysyx_25040129_top__u_ysyx_25040129_REG__0(Vtop_ysyx_25040129_REG* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_REG___nba_comb__TOP__ysyx_25040129_top__u_ysyx_25040129_REG__0\n"); );
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
