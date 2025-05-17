// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

void Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ is_fetch, IData/*31:0*/ is_avail, IData/*31:0*/ &paddr_read__Vfuncrtn);
void Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(IData/*31:0*/ inst);
void Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ data, IData/*31:0*/ is_avail);
void Vtop___024unit____Vdpiimwrap_ebreak_trigger_TOP____024unit();

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.regs[0U] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0U];
    vlSelfRef.regs[1U] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[1U];
    vlSelfRef.regs[2U] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[2U];
    vlSelfRef.regs[3U] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[3U];
    vlSelfRef.regs[4U] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[4U];
    vlSelfRef.regs[5U] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[5U];
    vlSelfRef.regs[6U] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[6U];
    vlSelfRef.regs[7U] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[7U];
    vlSelfRef.regs[8U] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[8U];
    vlSelfRef.regs[9U] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[9U];
    vlSelfRef.regs[0xaU] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0xaU];
    vlSelfRef.regs[0xbU] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0xbU];
    vlSelfRef.regs[0xcU] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0xcU];
    vlSelfRef.regs[0xdU] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0xdU];
    vlSelfRef.regs[0xeU] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0xeU];
    vlSelfRef.regs[0xfU] = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0xfU];
    vlSelfRef.inst = ((0U == vlSelfRef.pc) ? ([&]() {
                Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(0x80000000U, 4U, 1U, 1U, vlSelfRef.__Vfunc_paddr_read__0__Vfuncout);
            }(), vlSelfRef.__Vfunc_paddr_read__0__Vfuncout)
                       : ([&]() {
                Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.pc, 4U, 1U, 1U, vlSelfRef.__Vfunc_paddr_read__1__Vfuncout);
            }(), vlSelfRef.__Vfunc_paddr_read__1__Vfuncout));
    vlSelfRef.ysyx_25040129_top__DOT__src2 = (((0U 
                                                == 
                                                (0x1fU 
                                                 & VL_SHIFTL_III(9,9,32, 
                                                                 (0x1fU 
                                                                  & (vlSelfRef.inst 
                                                                     >> 0x14U)), 5U)))
                                                ? 0U
                                                : (
                                                   vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[
                                                   (((IData)(0x1fU) 
                                                     + 
                                                     (0x1ffU 
                                                      & VL_SHIFTL_III(9,9,32, 
                                                                      (0x1fU 
                                                                       & (vlSelfRef.inst 
                                                                          >> 0x14U)), 5U))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & VL_SHIFTL_III(9,9,32, 
                                                                     (0x1fU 
                                                                      & (vlSelfRef.inst 
                                                                         >> 0x14U)), 5U))))) 
                                              | (vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[
                                                 (0xfU 
                                                  & (VL_SHIFTL_III(9,9,32, 
                                                                   (0x1fU 
                                                                    & (vlSelfRef.inst 
                                                                       >> 0x14U)), 5U) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(9,9,32, 
                                                                  (0x1fU 
                                                                   & (vlSelfRef.inst 
                                                                      >> 0x14U)), 5U))));
    vlSelfRef.ysyx_25040129_top__DOT__src1 = (((0U 
                                                == 
                                                (0x1fU 
                                                 & VL_SHIFTL_III(9,9,32, 
                                                                 (0x1fU 
                                                                  & (vlSelfRef.inst 
                                                                     >> 0xfU)), 5U)))
                                                ? 0U
                                                : (
                                                   vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[
                                                   (((IData)(0x1fU) 
                                                     + 
                                                     (0x1ffU 
                                                      & VL_SHIFTL_III(9,9,32, 
                                                                      (0x1fU 
                                                                       & (vlSelfRef.inst 
                                                                          >> 0xfU)), 5U))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & VL_SHIFTL_III(9,9,32, 
                                                                     (0x1fU 
                                                                      & (vlSelfRef.inst 
                                                                         >> 0xfU)), 5U))))) 
                                              | (vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[
                                                 (0xfU 
                                                  & (VL_SHIFTL_III(9,9,32, 
                                                                   (0x1fU 
                                                                    & (vlSelfRef.inst 
                                                                       >> 0xfU)), 5U) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & VL_SHIFTL_III(9,9,32, 
                                                                  (0x1fU 
                                                                   & (vlSelfRef.inst 
                                                                      >> 0xfU)), 5U))));
    if ((0x40U & vlSelfRef.inst)) {
        if ((0x20U & vlSelfRef.inst)) {
            if ((0x10U & vlSelfRef.inst)) {
                if ((8U & vlSelfRef.inst)) {
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                } else if ((4U & vlSelfRef.inst)) {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                } else if ((2U & vlSelfRef.inst)) {
                    if ((1U & vlSelfRef.inst)) {
                        vlSelfRef.ysyx_25040129_top__DOT__imm 
                            = (((- (IData)((vlSelfRef.inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelfRef.inst 
                                            >> 0x14U));
                        vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                    } else {
                        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                        vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                    }
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                }
            } else if ((8U & vlSelfRef.inst)) {
                if ((4U & vlSelfRef.inst)) {
                    if ((2U & vlSelfRef.inst)) {
                        if ((1U & vlSelfRef.inst)) {
                            vlSelfRef.ysyx_25040129_top__DOT__imm 
                                = (((- (IData)((vlSelfRef.inst 
                                                >> 0x1fU))) 
                                    << 0x14U) | (((0xff000U 
                                                   & vlSelfRef.inst) 
                                                  | (0x800U 
                                                     & (vlSelfRef.inst 
                                                        >> 9U))) 
                                                 | (0x7feU 
                                                    & (vlSelfRef.inst 
                                                       >> 0x14U))));
                            vlSelfRef.ysyx_25040129_top__DOT__reg_write = 1U;
                        } else {
                            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                            vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                        }
                    } else {
                        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                        vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                    }
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                }
            } else if ((4U & vlSelfRef.inst)) {
                if ((2U & vlSelfRef.inst)) {
                    if ((1U & vlSelfRef.inst)) {
                        vlSelfRef.ysyx_25040129_top__DOT__imm 
                            = (((- (IData)((vlSelfRef.inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelfRef.inst 
                                            >> 0x14U));
                        vlSelfRef.ysyx_25040129_top__DOT__reg_write = 1U;
                    } else {
                        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                        vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                    }
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                }
            } else if ((2U & vlSelfRef.inst)) {
                if ((1U & vlSelfRef.inst)) {
                    vlSelfRef.ysyx_25040129_top__DOT__imm 
                        = (((- (IData)((vlSelfRef.inst 
                                        >> 0x1fU))) 
                            << 0xcU) | ((0x800U & (vlSelfRef.inst 
                                                   << 4U)) 
                                        | ((0x7e0U 
                                            & (vlSelfRef.inst 
                                               >> 0x14U)) 
                                           | (0x1eU 
                                              & (vlSelfRef.inst 
                                                 >> 7U)))));
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                }
            } else {
                Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
            }
        } else {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
            vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
        }
    } else if ((0x20U & vlSelfRef.inst)) {
        if ((0x10U & vlSelfRef.inst)) {
            if ((8U & vlSelfRef.inst)) {
                Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
            } else if ((4U & vlSelfRef.inst)) {
                if ((2U & vlSelfRef.inst)) {
                    if ((1U & vlSelfRef.inst)) {
                        vlSelfRef.ysyx_25040129_top__DOT__imm 
                            = (0xfffff000U & vlSelfRef.inst);
                        vlSelfRef.ysyx_25040129_top__DOT__reg_write = 1U;
                    } else {
                        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                        vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                    }
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                }
            } else if ((2U & vlSelfRef.inst)) {
                if ((1U & vlSelfRef.inst)) {
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write = 1U;
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                }
            } else {
                Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
            }
        } else if ((8U & vlSelfRef.inst)) {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
            vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
        } else if ((4U & vlSelfRef.inst)) {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
            vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
        } else if ((2U & vlSelfRef.inst)) {
            if ((1U & vlSelfRef.inst)) {
                vlSelfRef.ysyx_25040129_top__DOT__imm 
                    = (((- (IData)((vlSelfRef.inst 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelfRef.inst 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelfRef.inst 
                                                      >> 7U))));
                vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
            } else {
                Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
            }
        } else {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
            vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
        }
    } else if ((0x10U & vlSelfRef.inst)) {
        if ((8U & vlSelfRef.inst)) {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
            vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
        } else if ((4U & vlSelfRef.inst)) {
            if ((2U & vlSelfRef.inst)) {
                if ((1U & vlSelfRef.inst)) {
                    vlSelfRef.ysyx_25040129_top__DOT__imm 
                        = (0xfffff000U & vlSelfRef.inst);
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write = 1U;
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                }
            } else {
                Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
            }
        } else if ((2U & vlSelfRef.inst)) {
            if ((1U & vlSelfRef.inst)) {
                vlSelfRef.ysyx_25040129_top__DOT__imm 
                    = (((- (IData)((vlSelfRef.inst 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelfRef.inst >> 0x14U));
                vlSelfRef.ysyx_25040129_top__DOT__reg_write = 1U;
            } else {
                Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
                vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
            }
        } else {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
            vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
        }
    } else if ((8U & vlSelfRef.inst)) {
        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
        vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
    } else if ((4U & vlSelfRef.inst)) {
        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
        vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
    } else if ((2U & vlSelfRef.inst)) {
        if ((1U & vlSelfRef.inst)) {
            vlSelfRef.ysyx_25040129_top__DOT__imm = 
                (((- (IData)((vlSelfRef.inst >> 0x1fU))) 
                  << 0xcU) | (vlSelfRef.inst >> 0x14U));
            vlSelfRef.ysyx_25040129_top__DOT__reg_write = 1U;
        } else {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
            vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
        }
    } else {
        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.inst);
        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
        vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
    }
    vlSelfRef.ysyx_25040129_top__DOT__next_pc = (((0x63U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelfRef.inst))
                                                   ? 
                                                  ((0x4000U 
                                                    & vlSelfRef.inst)
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelfRef.inst)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelfRef.inst)
                                                      ? 
                                                     (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                      >= vlSelfRef.ysyx_25040129_top__DOT__src2)
                                                      : 
                                                     (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                      < vlSelfRef.ysyx_25040129_top__DOT__src2))
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelfRef.inst)
                                                      ? 
                                                     VL_GTES_III(32, vlSelfRef.ysyx_25040129_top__DOT__src1, vlSelfRef.ysyx_25040129_top__DOT__src2)
                                                      : 
                                                     VL_LTS_III(32, vlSelfRef.ysyx_25040129_top__DOT__src1, vlSelfRef.ysyx_25040129_top__DOT__src2)))
                                                    : 
                                                   ((1U 
                                                     & (~ 
                                                        (vlSelfRef.inst 
                                                         >> 0xdU))) 
                                                    && ((0x1000U 
                                                         & vlSelfRef.inst)
                                                         ? 
                                                        (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                         != vlSelfRef.ysyx_25040129_top__DOT__src2)
                                                         : 
                                                        (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                         == vlSelfRef.ysyx_25040129_top__DOT__src2))))
                                                   : 
                                                  ((0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst)) 
                                                   || (0x67U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelfRef.inst))))
                                                  ? 
                                                 ((0x63U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelfRef.inst))
                                                   ? 
                                                  (vlSelfRef.ysyx_25040129_top__DOT__imm 
                                                   + vlSelfRef.pc)
                                                   : 
                                                  ((0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.inst))
                                                    ? 
                                                   (vlSelfRef.ysyx_25040129_top__DOT__imm 
                                                    + vlSelfRef.pc)
                                                    : 
                                                   ((0x67U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelfRef.inst))
                                                     ? 
                                                    (0xfffffffeU 
                                                     & (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                        + vlSelfRef.ysyx_25040129_top__DOT__imm))
                                                     : 0U)))
                                                  : 
                                                 ((IData)(4U) 
                                                  + vlSelfRef.pc));
    vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MEM__DOT__addr 
        = (vlSelfRef.ysyx_25040129_top__DOT__imm + vlSelfRef.ysyx_25040129_top__DOT__src1);
    Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MEM__DOT__addr, 4U, 0U, 
                                                           (3U 
                                                            == 
                                                            (0x7fU 
                                                             & vlSelfRef.inst)), vlSelfRef.__Vfunc_paddr_read__35__Vfuncout);
    vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MEM__DOT____VdfgExtracted_haa08dfc0__0 
        = vlSelfRef.__Vfunc_paddr_read__35__Vfuncout;
    if ((3U == (0x7fU & vlSelfRef.inst))) {
        vlSelfRef.ysyx_25040129_top__DOT__read_data 
            = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MEM__DOT____VdfgExtracted_haa08dfc0__0;
    } else if ((0x23U == (0x7fU & vlSelfRef.inst))) {
        if ((0U == (7U & (vlSelfRef.inst >> 0xcU)))) {
            vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MEM__DOT__write_len = 1U;
        } else if ((1U == (7U & (vlSelfRef.inst >> 0xcU)))) {
            vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MEM__DOT__write_len = 2U;
        } else if ((2U == (7U & (vlSelfRef.inst >> 0xcU)))) {
            vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MEM__DOT__write_len = 4U;
        } else {
            vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MEM__DOT__write_len = 0U;
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(0U);
        }
        Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MEM__DOT__addr, (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MEM__DOT__write_len), vlSelfRef.ysyx_25040129_top__DOT__src2, 
                                                                (0x23U 
                                                                 == 
                                                                 (0x7fU 
                                                                  & vlSelfRef.inst)));
    }
    if ((0x40U & vlSelfRef.inst)) {
        if ((0x20U & vlSelfRef.inst)) {
            if ((0x10U & vlSelfRef.inst)) {
                if ((8U & vlSelfRef.inst)) {
                    vlSelfRef.ysyx_25040129_top__DOT__result = 0U;
                } else if ((4U & vlSelfRef.inst)) {
                    vlSelfRef.ysyx_25040129_top__DOT__result = 0U;
                } else if ((2U & vlSelfRef.inst)) {
                    if ((1U & vlSelfRef.inst)) {
                        if ((IData)(((0U == (0x7000U 
                                             & vlSelfRef.inst)) 
                                     & (1U == vlSelfRef.ysyx_25040129_top__DOT__imm)))) {
                            vlSelfRef.ysyx_25040129_top__DOT__result = 0U;
                            Vtop___024unit____Vdpiimwrap_ebreak_trigger_TOP____024unit();
                        } else {
                            vlSelfRef.ysyx_25040129_top__DOT__result = 0U;
                        }
                    } else {
                        vlSelfRef.ysyx_25040129_top__DOT__result = 0U;
                    }
                } else {
                    vlSelfRef.ysyx_25040129_top__DOT__result = 0U;
                }
            } else {
                vlSelfRef.ysyx_25040129_top__DOT__result 
                    = ((8U & vlSelfRef.inst) ? ((4U 
                                                 & vlSelfRef.inst)
                                                 ? 
                                                ((2U 
                                                  & vlSelfRef.inst)
                                                  ? 
                                                 ((1U 
                                                   & vlSelfRef.inst)
                                                   ? 
                                                  ((IData)(4U) 
                                                   + vlSelfRef.pc)
                                                   : 0U)
                                                  : 0U)
                                                 : 0U)
                        : ((4U & vlSelfRef.inst) ? 
                           ((2U & vlSelfRef.inst) ? 
                            ((1U & vlSelfRef.inst) ? 
                             ((IData)(4U) + vlSelfRef.pc)
                              : 0U) : 0U) : 0U));
            }
        } else {
            vlSelfRef.ysyx_25040129_top__DOT__result = 0U;
        }
    } else {
        vlSelfRef.ysyx_25040129_top__DOT__result = 
            ((0x20U & vlSelfRef.inst) ? ((0x10U & vlSelfRef.inst)
                                          ? ((8U & vlSelfRef.inst)
                                              ? 0U : 
                                             ((4U & vlSelfRef.inst)
                                               ? ((2U 
                                                   & vlSelfRef.inst)
                                                   ? 
                                                  ((1U 
                                                    & vlSelfRef.inst)
                                                    ? vlSelfRef.ysyx_25040129_top__DOT__imm
                                                    : 0U)
                                                   : 0U)
                                               : ((2U 
                                                   & vlSelfRef.inst)
                                                   ? 
                                                  ((1U 
                                                    & vlSelfRef.inst)
                                                    ? 
                                                   ((0x4000U 
                                                     & vlSelfRef.inst)
                                                     ? 
                                                    ((0x2000U 
                                                      & vlSelfRef.inst)
                                                      ? 
                                                     ((0x1000U 
                                                       & vlSelfRef.inst)
                                                       ? 
                                                      (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                       & vlSelfRef.ysyx_25040129_top__DOT__src2)
                                                       : 
                                                      (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                       | vlSelfRef.ysyx_25040129_top__DOT__src2))
                                                      : 
                                                     ((0x1000U 
                                                       & vlSelfRef.inst)
                                                       ? 
                                                      ((0x40000000U 
                                                        & vlSelfRef.inst)
                                                        ? 
                                                       VL_SHIFTRS_III(32,32,5, vlSelfRef.ysyx_25040129_top__DOT__src1, 
                                                                      (0x1fU 
                                                                       & vlSelfRef.ysyx_25040129_top__DOT__src2))
                                                        : 
                                                       (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                        >> 
                                                        (0x1fU 
                                                         & vlSelfRef.ysyx_25040129_top__DOT__src2)))
                                                       : 
                                                      (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                       ^ vlSelfRef.ysyx_25040129_top__DOT__src2)))
                                                     : 
                                                    ((0x2000U 
                                                      & vlSelfRef.inst)
                                                      ? 
                                                     ((0x1000U 
                                                       & vlSelfRef.inst)
                                                       ? 
                                                      ((vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                        < vlSelfRef.ysyx_25040129_top__DOT__src2)
                                                        ? 1U
                                                        : 0U)
                                                       : 
                                                      (VL_LTS_III(32, vlSelfRef.ysyx_25040129_top__DOT__src1, vlSelfRef.ysyx_25040129_top__DOT__src2)
                                                        ? 1U
                                                        : 0U))
                                                      : 
                                                     ((0x1000U 
                                                       & vlSelfRef.inst)
                                                       ? 
                                                      (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                       << 
                                                       (0x1fU 
                                                        & vlSelfRef.ysyx_25040129_top__DOT__src2))
                                                       : 
                                                      ((0x40000000U 
                                                        & vlSelfRef.inst)
                                                        ? 
                                                       (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                        - vlSelfRef.ysyx_25040129_top__DOT__src2)
                                                        : 
                                                       (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                        + vlSelfRef.ysyx_25040129_top__DOT__src2)))))
                                                    : 0U)
                                                   : 0U)))
                                          : 0U) : (
                                                   (0x10U 
                                                    & vlSelfRef.inst)
                                                    ? 
                                                   ((8U 
                                                     & vlSelfRef.inst)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlSelfRef.inst)
                                                      ? 
                                                     ((2U 
                                                       & vlSelfRef.inst)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.inst)
                                                        ? 
                                                       (vlSelfRef.ysyx_25040129_top__DOT__imm 
                                                        + vlSelfRef.pc)
                                                        : 0U)
                                                       : 0U)
                                                      : 
                                                     ((2U 
                                                       & vlSelfRef.inst)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.inst)
                                                        ? 
                                                       ((0x4000U 
                                                         & vlSelfRef.inst)
                                                         ? 
                                                        ((0x2000U 
                                                          & vlSelfRef.inst)
                                                          ? 
                                                         ((0x1000U 
                                                           & vlSelfRef.inst)
                                                           ? 
                                                          (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                           & vlSelfRef.ysyx_25040129_top__DOT__imm)
                                                           : 
                                                          (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                           | vlSelfRef.ysyx_25040129_top__DOT__imm))
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.inst)
                                                           ? 
                                                          ((0x40000000U 
                                                            & vlSelfRef.inst)
                                                            ? 
                                                           VL_SHIFTRS_III(32,32,5, vlSelfRef.ysyx_25040129_top__DOT__src1, 
                                                                          (0x1fU 
                                                                           & vlSelfRef.ysyx_25040129_top__DOT__imm))
                                                            : 
                                                           (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                            >> 
                                                            (0x1fU 
                                                             & vlSelfRef.ysyx_25040129_top__DOT__imm)))
                                                           : 
                                                          (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                           ^ vlSelfRef.ysyx_25040129_top__DOT__imm)))
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.inst)
                                                          ? 
                                                         ((0x1000U 
                                                           & vlSelfRef.inst)
                                                           ? 
                                                          ((vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                            < vlSelfRef.ysyx_25040129_top__DOT__imm)
                                                            ? 1U
                                                            : 0U)
                                                           : 
                                                          (VL_LTS_III(32, vlSelfRef.ysyx_25040129_top__DOT__src1, vlSelfRef.ysyx_25040129_top__DOT__imm)
                                                            ? 1U
                                                            : 0U))
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.inst)
                                                           ? 
                                                          (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                           << 
                                                           (0x1fU 
                                                            & vlSelfRef.ysyx_25040129_top__DOT__imm))
                                                           : 
                                                          (vlSelfRef.ysyx_25040129_top__DOT__src1 
                                                           + vlSelfRef.ysyx_25040129_top__DOT__imm))))
                                                        : 0U)
                                                       : 0U)))
                                                    : 
                                                   ((8U 
                                                     & vlSelfRef.inst)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlSelfRef.inst)
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & vlSelfRef.inst)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.inst)
                                                        ? 
                                                       ((0x4000U 
                                                         & vlSelfRef.inst)
                                                         ? 
                                                        ((0x2000U 
                                                          & vlSelfRef.inst)
                                                          ? 0U
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.inst)
                                                           ? 
                                                          (0xffffU 
                                                           & vlSelfRef.ysyx_25040129_top__DOT__read_data)
                                                           : 
                                                          (0xffU 
                                                           & vlSelfRef.ysyx_25040129_top__DOT__read_data)))
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.inst)
                                                          ? 
                                                         ((0x1000U 
                                                           & vlSelfRef.inst)
                                                           ? 0U
                                                           : vlSelfRef.ysyx_25040129_top__DOT__read_data)
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.inst)
                                                           ? 
                                                          (((- (IData)(
                                                                       (1U 
                                                                        & (vlSelfRef.ysyx_25040129_top__DOT__read_data 
                                                                           >> 0xfU)))) 
                                                            << 0x10U) 
                                                           | (0xffffU 
                                                              & vlSelfRef.ysyx_25040129_top__DOT__read_data))
                                                           : 
                                                          (((- (IData)(
                                                                       (1U 
                                                                        & (vlSelfRef.ysyx_25040129_top__DOT__read_data 
                                                                           >> 7U)))) 
                                                            << 8U) 
                                                           | (0xffU 
                                                              & vlSelfRef.ysyx_25040129_top__DOT__read_data)))))
                                                        : 0U)
                                                       : 0U)))));
    }
}
