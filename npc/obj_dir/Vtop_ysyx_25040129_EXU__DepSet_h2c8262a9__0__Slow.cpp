// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_ysyx_25040129_EXU.h"

void Vtop___024unit____Vdpiimwrap_ebreak_trigger_TOP____024unit();

VL_ATTR_COLD void Vtop_ysyx_25040129_EXU___stl_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_EXU__0(Vtop_ysyx_25040129_EXU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_EXU___stl_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_EXU__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((((((((3U == (IData)(vlSelfRef.__PVT__opcode)) 
               | (0x37U == (IData)(vlSelfRef.__PVT__opcode))) 
              | (0x17U == (IData)(vlSelfRef.__PVT__opcode))) 
             | (0x73U == (IData)(vlSelfRef.__PVT__opcode))) 
            | (0x6fU == (IData)(vlSelfRef.__PVT__opcode))) 
           | (0x67U == (IData)(vlSelfRef.__PVT__opcode))) 
          | (0x13U == (IData)(vlSelfRef.__PVT__opcode))) 
         | (0x33U == (IData)(vlSelfRef.__PVT__opcode)))) {
        if ((3U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__result = ((0U == (IData)(vlSelfRef.__PVT__funct3))
                                        ? VL_CONCAT_III(32,24,8, 
                                                        (0xffffffU 
                                                         & VL_REPLICATE_IOI(1,
                                                                            (1U 
                                                                             & VL_BITSEL_IIII(32, vlSelfRef.__PVT__read_data, 7U)), 0x18U)), 
                                                        (0xffU 
                                                         & VL_SEL_IIII(32, vlSelfRef.__PVT__read_data, 0U, 8U)))
                                        : ((1U == (IData)(vlSelfRef.__PVT__funct3))
                                            ? VL_CONCAT_III(32,16,16, 
                                                            (0xffffU 
                                                             & VL_REPLICATE_IOI(1,
                                                                                (1U 
                                                                                & VL_BITSEL_IIII(32, vlSelfRef.__PVT__read_data, 0xfU)), 0x10U)), 
                                                            (0xffffU 
                                                             & VL_SEL_IIII(32, vlSelfRef.__PVT__read_data, 0U, 0x10U)))
                                            : ((2U 
                                                == (IData)(vlSelfRef.__PVT__funct3))
                                                ? vlSelfRef.__PVT__read_data
                                                : (
                                                   (4U 
                                                    == (IData)(vlSelfRef.__PVT__funct3))
                                                    ? 
                                                   VL_EXTEND_II(32,8, 
                                                                (0xffU 
                                                                 & VL_SEL_IIII(32, vlSelfRef.__PVT__read_data, 0U, 8U)))
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlSelfRef.__PVT__funct3))
                                                     ? 
                                                    VL_EXTEND_II(32,16, 
                                                                 (0xffffU 
                                                                  & VL_SEL_IIII(32, vlSelfRef.__PVT__read_data, 0U, 0x10U)))
                                                     : 0U)))));
        } else if ((0x37U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__result = vlSelfRef.__PVT__imm;
        } else if ((0x17U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__result = (vlSelfRef.__PVT__imm 
                                       + vlSelfRef.__PVT__pc);
        } else if ((0x73U == (IData)(vlSelfRef.__PVT__opcode))) {
            if (vlSelfRef.__PVT__ebreak) {
                Vtop___024unit____Vdpiimwrap_ebreak_trigger_TOP____024unit();
            }
            vlSelfRef.__PVT__result = ((IData)(vlSelfRef.__PVT__csr_read)
                                        ? vlSelfRef.__PVT__csr_data
                                        : 0U);
        } else if ((0x6fU == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__result = ((IData)(4U) 
                                       + vlSelfRef.__PVT__pc);
        } else if ((0x67U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__result = ((IData)(4U) 
                                       + vlSelfRef.__PVT__pc);
        } else if ((0x13U == (IData)(vlSelfRef.__PVT__opcode))) {
            if (((((((((0U == (IData)(vlSelfRef.__PVT__funct3)) 
                       | (2U == (IData)(vlSelfRef.__PVT__funct3))) 
                      | (3U == (IData)(vlSelfRef.__PVT__funct3))) 
                     | (4U == (IData)(vlSelfRef.__PVT__funct3))) 
                    | (6U == (IData)(vlSelfRef.__PVT__funct3))) 
                   | (7U == (IData)(vlSelfRef.__PVT__funct3))) 
                  | (1U == (IData)(vlSelfRef.__PVT__funct3))) 
                 | (5U == (IData)(vlSelfRef.__PVT__funct3)))) {
                vlSelfRef.__PVT__result = ((0U == (IData)(vlSelfRef.__PVT__funct3))
                                            ? (vlSelfRef.__PVT__src1 
                                               + vlSelfRef.__PVT__imm)
                                            : ((2U 
                                                == (IData)(vlSelfRef.__PVT__funct3))
                                                ? (
                                                   VL_LTS_III(32, vlSelfRef.__PVT__src1, vlSelfRef.__PVT__imm)
                                                    ? 1U
                                                    : 0U)
                                                : (
                                                   (3U 
                                                    == (IData)(vlSelfRef.__PVT__funct3))
                                                    ? 
                                                   ((vlSelfRef.__PVT__src1 
                                                     < vlSelfRef.__PVT__imm)
                                                     ? 1U
                                                     : 0U)
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelfRef.__PVT__funct3))
                                                     ? 
                                                    (vlSelfRef.__PVT__src1 
                                                     ^ vlSelfRef.__PVT__imm)
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelfRef.__PVT__funct3))
                                                      ? 
                                                     (vlSelfRef.__PVT__src1 
                                                      | vlSelfRef.__PVT__imm)
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelfRef.__PVT__funct3))
                                                       ? 
                                                      (vlSelfRef.__PVT__src1 
                                                       & vlSelfRef.__PVT__imm)
                                                       : 
                                                      ((1U 
                                                        == (IData)(vlSelfRef.__PVT__funct3))
                                                        ? 
                                                       (vlSelfRef.__PVT__src1 
                                                        << 
                                                        (0x1fU 
                                                         & VL_SEL_IIII(32, vlSelfRef.__PVT__imm, 0U, 5U)))
                                                        : 
                                                       ((1U 
                                                         & VL_BITSEL_IIII(7, (IData)(vlSelfRef.__PVT__funct7), 5U))
                                                         ? 
                                                        VL_SHIFTRS_III(32,32,5, vlSelfRef.__PVT__src1, 
                                                                       (0x1fU 
                                                                        & VL_SEL_IIII(32, vlSelfRef.__PVT__imm, 0U, 5U)))
                                                         : 
                                                        (vlSelfRef.__PVT__src1 
                                                         >> 
                                                         (0x1fU 
                                                          & VL_SEL_IIII(32, vlSelfRef.__PVT__imm, 0U, 5U)))))))))));
            }
        } else if (((((((((0U == (IData)(vlSelfRef.__PVT__funct3)) 
                          | (1U == (IData)(vlSelfRef.__PVT__funct3))) 
                         | (2U == (IData)(vlSelfRef.__PVT__funct3))) 
                        | (3U == (IData)(vlSelfRef.__PVT__funct3))) 
                       | (4U == (IData)(vlSelfRef.__PVT__funct3))) 
                      | (5U == (IData)(vlSelfRef.__PVT__funct3))) 
                     | (6U == (IData)(vlSelfRef.__PVT__funct3))) 
                    | (7U == (IData)(vlSelfRef.__PVT__funct3)))) {
            vlSelfRef.__PVT__result = ((0U == (IData)(vlSelfRef.__PVT__funct3))
                                        ? ((1U & VL_BITSEL_IIII(7, (IData)(vlSelfRef.__PVT__funct7), 5U))
                                            ? (vlSelfRef.__PVT__src1 
                                               - vlSelfRef.__PVT__src2)
                                            : (vlSelfRef.__PVT__src1 
                                               + vlSelfRef.__PVT__src2))
                                        : ((1U == (IData)(vlSelfRef.__PVT__funct3))
                                            ? (vlSelfRef.__PVT__src1 
                                               << (0x1fU 
                                                   & VL_SEL_IIII(32, vlSelfRef.__PVT__src2, 0U, 5U)))
                                            : ((2U 
                                                == (IData)(vlSelfRef.__PVT__funct3))
                                                ? (
                                                   VL_LTS_III(32, vlSelfRef.__PVT__src1, vlSelfRef.__PVT__src2)
                                                    ? 1U
                                                    : 0U)
                                                : (
                                                   (3U 
                                                    == (IData)(vlSelfRef.__PVT__funct3))
                                                    ? 
                                                   ((vlSelfRef.__PVT__src1 
                                                     < vlSelfRef.__PVT__src2)
                                                     ? 1U
                                                     : 0U)
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelfRef.__PVT__funct3))
                                                     ? 
                                                    (vlSelfRef.__PVT__src1 
                                                     ^ vlSelfRef.__PVT__src2)
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlSelfRef.__PVT__funct3))
                                                      ? 
                                                     ((1U 
                                                       & VL_BITSEL_IIII(7, (IData)(vlSelfRef.__PVT__funct7), 5U))
                                                       ? 
                                                      VL_SHIFTRS_III(32,32,5, vlSelfRef.__PVT__src1, 
                                                                     (0x1fU 
                                                                      & VL_SEL_IIII(32, vlSelfRef.__PVT__src2, 0U, 5U)))
                                                       : 
                                                      (vlSelfRef.__PVT__src1 
                                                       >> 
                                                       (0x1fU 
                                                        & VL_SEL_IIII(32, vlSelfRef.__PVT__src2, 0U, 5U))))
                                                      : 
                                                     ((6U 
                                                       == (IData)(vlSelfRef.__PVT__funct3))
                                                       ? 
                                                      (vlSelfRef.__PVT__src1 
                                                       | vlSelfRef.__PVT__src2)
                                                       : 
                                                      (vlSelfRef.__PVT__src1 
                                                       & vlSelfRef.__PVT__src2))))))));
        }
    } else {
        vlSelfRef.__PVT__result = 0U;
    }
}
