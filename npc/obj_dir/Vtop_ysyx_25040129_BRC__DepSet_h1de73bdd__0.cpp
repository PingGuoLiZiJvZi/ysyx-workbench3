// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ysyx_25040129_BRC.h"

VL_INLINE_OPT void Vtop_ysyx_25040129_BRC___nba_comb__TOP__ysyx_25040129_top__u_ysyx_25040129_BRC__0(Vtop_ysyx_25040129_BRC* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_BRC___nba_comb__TOP__ysyx_25040129_top__u_ysyx_25040129_BRC__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x63U == (IData)(vlSelfRef.__PVT__opcode))) {
        vlSelfRef.__PVT__is_branch = ((0U == (IData)(vlSelfRef.__PVT__funct3))
                                       ? (vlSelfRef.__PVT__src1 
                                          == vlSelfRef.__PVT__src2)
                                       : ((1U == (IData)(vlSelfRef.__PVT__funct3))
                                           ? (vlSelfRef.__PVT__src1 
                                              != vlSelfRef.__PVT__src2)
                                           : ((4U == (IData)(vlSelfRef.__PVT__funct3))
                                               ? VL_LTS_III(32, vlSelfRef.__PVT__src1, vlSelfRef.__PVT__src2)
                                               : ((5U 
                                                   == (IData)(vlSelfRef.__PVT__funct3))
                                                   ? 
                                                  VL_GTES_III(32, vlSelfRef.__PVT__src1, vlSelfRef.__PVT__src2)
                                                   : 
                                                  ((6U 
                                                    == (IData)(vlSelfRef.__PVT__funct3))
                                                    ? 
                                                   (vlSelfRef.__PVT__src1 
                                                    < vlSelfRef.__PVT__src2)
                                                    : 
                                                   ((7U 
                                                     == (IData)(vlSelfRef.__PVT__funct3)) 
                                                    && (vlSelfRef.__PVT__src1 
                                                        >= vlSelfRef.__PVT__src2)))))));
        vlSelfRef.__PVT__branch_target = (vlSelfRef.__PVT__imm 
                                          + vlSelfRef.__PVT__pc);
    } else if ((0x6fU == (IData)(vlSelfRef.__PVT__opcode))) {
        vlSelfRef.__PVT__is_branch = 1U;
        vlSelfRef.__PVT__branch_target = (vlSelfRef.__PVT__imm 
                                          + vlSelfRef.__PVT__pc);
    } else if ((0x67U == (IData)(vlSelfRef.__PVT__opcode))) {
        vlSelfRef.__PVT__is_branch = 1U;
        vlSelfRef.__PVT__branch_target = (0xfffffffeU 
                                          & (vlSelfRef.__PVT__src1 
                                             + vlSelfRef.__PVT__imm));
    } else {
        vlSelfRef.__PVT__is_branch = 0U;
        vlSelfRef.__PVT__branch_target = 0U;
    }
}
