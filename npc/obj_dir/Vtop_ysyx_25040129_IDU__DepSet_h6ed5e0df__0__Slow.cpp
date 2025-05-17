// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_ysyx_25040129_IDU.h"

void Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(IData/*31:0*/ inst);

VL_ATTR_COLD void Vtop_ysyx_25040129_IDU___stl_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_IDU__0(Vtop_ysyx_25040129_IDU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_IDU___stl_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_IDU__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rd = (0x1fU & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 7U, 5U));
    vlSelfRef.__PVT__funct7 = (0x7fU & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0x19U, 7U));
    vlSelfRef.__PVT__funct3 = (7U & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0xcU, 3U));
    vlSelfRef.__PVT__src2_id = (0x1fU & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0x14U, 5U));
    vlSelfRef.__PVT__src1_id = (0x1fU & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0xfU, 5U));
    vlSelfRef.__PVT__opcode = (0x7fU & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0U, 7U));
    if (((((((((0x13U == (IData)(vlSelfRef.__PVT__opcode)) 
               | (0x63U == (IData)(vlSelfRef.__PVT__opcode))) 
              | (3U == (IData)(vlSelfRef.__PVT__opcode))) 
             | (0x23U == (IData)(vlSelfRef.__PVT__opcode))) 
            | (0x6fU == (IData)(vlSelfRef.__PVT__opcode))) 
           | (0x67U == (IData)(vlSelfRef.__PVT__opcode))) 
          | (0x73U == (IData)(vlSelfRef.__PVT__opcode))) 
         | (0x33U == (IData)(vlSelfRef.__PVT__opcode)))) {
        if ((0x13U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__imm = VL_CONCAT_III(32,20,12, 
                                                 (0xfffffU 
                                                  & VL_REPLICATE_IOI(1,
                                                                     (1U 
                                                                      & VL_BITSEL_IIII(32, vlSelfRef.__PVT__inst, 0x1fU)), 0x14U)), 
                                                 (0xfffU 
                                                  & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0x14U, 0xcU)));
            vlSelfRef.__PVT__reg_write = 1U;
        } else if ((0x63U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__imm = VL_CONCAT_III(32,20,12, 
                                                 (0xfffffU 
                                                  & VL_REPLICATE_IOI(1,
                                                                     (1U 
                                                                      & VL_BITSEL_IIII(32, vlSelfRef.__PVT__inst, 0x1fU)), 0x14U)), 
                                                 VL_CONCAT_III(12,1,11, 
                                                               (1U 
                                                                & VL_BITSEL_IIII(32, vlSelfRef.__PVT__inst, 7U)), 
                                                               VL_CONCAT_III(11,6,5, 
                                                                             (0x3fU 
                                                                              & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0x19U, 6U)), 
                                                                             VL_CONCAT_III(5,4,1, 
                                                                                (0xfU 
                                                                                & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 8U, 4U)), 0U))));
            vlSelfRef.__PVT__reg_write = 0U;
        } else if ((3U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__imm = VL_CONCAT_III(32,20,12, 
                                                 (0xfffffU 
                                                  & VL_REPLICATE_IOI(1,
                                                                     (1U 
                                                                      & VL_BITSEL_IIII(32, vlSelfRef.__PVT__inst, 0x1fU)), 0x14U)), 
                                                 (0xfffU 
                                                  & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0x14U, 0xcU)));
            vlSelfRef.__PVT__reg_write = 1U;
        } else if ((0x23U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__imm = VL_CONCAT_III(32,20,12, 
                                                 (0xfffffU 
                                                  & VL_REPLICATE_IOI(1,
                                                                     (1U 
                                                                      & VL_BITSEL_IIII(32, vlSelfRef.__PVT__inst, 0x1fU)), 0x14U)), 
                                                 VL_CONCAT_III(12,7,5, 
                                                               (0x7fU 
                                                                & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0x19U, 7U)), 
                                                               (0x1fU 
                                                                & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 7U, 5U))));
            vlSelfRef.__PVT__reg_write = 0U;
        } else if ((0x6fU == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__imm = VL_CONCAT_III(32,12,20, 
                                                 (0xfffU 
                                                  & VL_REPLICATE_IOI(1,
                                                                     (1U 
                                                                      & VL_BITSEL_IIII(32, vlSelfRef.__PVT__inst, 0x1fU)), 0xcU)), 
                                                 VL_CONCAT_III(20,9,11, 
                                                               VL_CONCAT_III(9,8,1, 
                                                                             (0xffU 
                                                                              & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0xcU, 8U)), 
                                                                             (1U 
                                                                              & VL_BITSEL_IIII(32, vlSelfRef.__PVT__inst, 0x14U))), 
                                                               VL_CONCAT_III(11,10,1, 
                                                                             (0x3ffU 
                                                                              & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0x15U, 0xaU)), 0U)));
            vlSelfRef.__PVT__reg_write = 1U;
        } else if ((0x67U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__imm = VL_CONCAT_III(32,20,12, 
                                                 (0xfffffU 
                                                  & VL_REPLICATE_IOI(1,
                                                                     (1U 
                                                                      & VL_BITSEL_IIII(32, vlSelfRef.__PVT__inst, 0x1fU)), 0x14U)), 
                                                 (0xfffU 
                                                  & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0x14U, 0xcU)));
            vlSelfRef.__PVT__reg_write = 1U;
        } else if ((0x73U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__imm = VL_CONCAT_III(32,20,12, 
                                                 (0xfffffU 
                                                  & VL_REPLICATE_IOI(1,
                                                                     (1U 
                                                                      & VL_BITSEL_IIII(32, vlSelfRef.__PVT__inst, 0x1fU)), 0x14U)), 
                                                 (0xfffU 
                                                  & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0x14U, 0xcU)));
            vlSelfRef.__PVT__reg_write = 0U;
        } else {
            vlSelfRef.__PVT__imm = 0U;
            vlSelfRef.__PVT__reg_write = 1U;
        }
    } else if ((0x37U == (IData)(vlSelfRef.__PVT__opcode))) {
        vlSelfRef.__PVT__imm = VL_CONCAT_III(32,20,12, 
                                             (0xfffffU 
                                              & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0xcU, 0x14U)), 0U);
        vlSelfRef.__PVT__reg_write = 1U;
    } else if ((0x17U == (IData)(vlSelfRef.__PVT__opcode))) {
        vlSelfRef.__PVT__imm = VL_CONCAT_III(32,20,12, 
                                             (0xfffffU 
                                              & VL_SEL_IIII(32, vlSelfRef.__PVT__inst, 0xcU, 0x14U)), 0U);
        vlSelfRef.__PVT__reg_write = 1U;
    } else {
        vlSelfRef.__PVT__imm = 0U;
        vlSelfRef.__PVT__reg_write = 0U;
        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.__PVT__inst);
    }
}
