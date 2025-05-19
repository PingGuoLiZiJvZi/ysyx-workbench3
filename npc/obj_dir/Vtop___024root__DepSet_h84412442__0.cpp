// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

extern const VlWide<16>/*511:0*/ Vtop__ConstPool__CONST_h93e1b771_0;
void Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ is_fetch, IData/*31:0*/ is_avail, IData/*31:0*/ &paddr_read__Vfuncrtn);
void Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(IData/*31:0*/ inst);
void Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ data, IData/*31:0*/ is_avail);
void Vtop___024unit____Vdpiimwrap_ebreak_trigger_TOP____024unit();

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus;
    __Vdly__ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus = 0;
    // Body
    __Vdly__ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus 
        = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus;
    if ((1U & (~ (IData)(vlSelfRef.ysyx_25040129_top__DOT__ecall)))) {
        if (vlSelfRef.ysyx_25040129_top__DOT__csr_write) {
            if ((0x300U != (0xfffU & vlSelfRef.ysyx_25040129_top__DOT__imm))) {
                if ((0x305U == (0xfffU & vlSelfRef.ysyx_25040129_top__DOT__imm))) {
                    vlSelfRef.ysyx_25040129_top__DOT__mtvec 
                        = vlSelfRef.ysyx_25040129_top__DOT__src1;
                }
            }
        }
    }
    if (vlSelfRef.rst) {
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0U];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[1U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[1U];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[2U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[2U];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[3U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[3U];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[4U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[4U];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[5U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[5U];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[6U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[6U];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[7U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[7U];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[8U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[8U];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[9U] 
            = Vtop__ConstPool__CONST_h93e1b771_0[9U];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0xaU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xaU];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0xbU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xbU];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0xcU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xcU];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0xdU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xdU];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0xeU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xeU];
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[0xfU] 
            = Vtop__ConstPool__CONST_h93e1b771_0[0xfU];
    } else if (((0U != (0x1fU & (vlSelfRef.inst >> 7U))) 
                & (IData)(vlSelfRef.ysyx_25040129_top__DOT__reg_write))) {
        VL_ASSIGNSEL_WI(512,32,(0x1ffU & VL_SHIFTL_III(9,32,32, 
                                                       (0x1fU 
                                                        & (vlSelfRef.inst 
                                                           >> 7U)), 5U)), vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs, vlSelfRef.ysyx_25040129_top__DOT__result);
    }
    if (vlSelfRef.ysyx_25040129_top__DOT__ecall) {
        __Vdly__ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus = 0U;
        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mcause = 0xbU;
        vlSelfRef.ysyx_25040129_top__DOT__mepc = vlSelfRef.pc;
    } else if (vlSelfRef.ysyx_25040129_top__DOT__csr_write) {
        if ((0x300U == (0xfffU & vlSelfRef.ysyx_25040129_top__DOT__imm))) {
            __Vdly__ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus 
                = vlSelfRef.ysyx_25040129_top__DOT__src1;
        } else if ((0x305U != (0xfffU & vlSelfRef.ysyx_25040129_top__DOT__imm))) {
            if ((0x341U != (0xfffU & vlSelfRef.ysyx_25040129_top__DOT__imm))) {
                if ((0x342U != (0xfffU & vlSelfRef.ysyx_25040129_top__DOT__imm))) {
                    __Vdly__ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus 
                        = vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus;
                }
            }
        }
        if ((0x300U != (0xfffU & vlSelfRef.ysyx_25040129_top__DOT__imm))) {
            if ((0x305U != (0xfffU & vlSelfRef.ysyx_25040129_top__DOT__imm))) {
                if ((0x341U != (0xfffU & vlSelfRef.ysyx_25040129_top__DOT__imm))) {
                    if ((0x342U == (0xfffU & vlSelfRef.ysyx_25040129_top__DOT__imm))) {
                        vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mcause 
                            = vlSelfRef.ysyx_25040129_top__DOT__src1;
                    }
                }
                if ((0x341U == (0xfffU & vlSelfRef.ysyx_25040129_top__DOT__imm))) {
                    vlSelfRef.ysyx_25040129_top__DOT__mepc 
                        = vlSelfRef.ysyx_25040129_top__DOT__src1;
                }
            }
        }
    }
    vlSelfRef.pc = ((IData)(vlSelfRef.rst) ? 0x80000000U
                     : vlSelfRef.ysyx_25040129_top__DOT__next_pc);
    vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus 
        = __Vdly__ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus;
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
    vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__ecall = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__ebreak = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__mret = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__csr_write = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__csr_read = 0U;
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
                        if ((0U == (7U & (vlSelfRef.inst 
                                          >> 0xcU)))) {
                            if ((1U == (vlSelfRef.inst 
                                        >> 0x14U))) {
                                vlSelfRef.ysyx_25040129_top__DOT__ebreak = 1U;
                            } else if ((0x302U == (vlSelfRef.inst 
                                                   >> 0x14U))) {
                                vlSelfRef.ysyx_25040129_top__DOT__mret = 1U;
                            } else {
                                vlSelfRef.ysyx_25040129_top__DOT__ecall = 1U;
                            }
                            vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                        } else if ((1U == (7U & (vlSelfRef.inst 
                                                 >> 0xcU)))) {
                            vlSelfRef.ysyx_25040129_top__DOT__csr_write = 1U;
                            vlSelfRef.ysyx_25040129_top__DOT__reg_write = 0U;
                        } else if ((2U == (7U & (vlSelfRef.inst 
                                                 >> 0xcU)))) {
                            vlSelfRef.ysyx_25040129_top__DOT__csr_read = 1U;
                            vlSelfRef.ysyx_25040129_top__DOT__reg_write = 1U;
                        } else {
                            vlSelfRef.ysyx_25040129_top__DOT__mret = 0U;
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
    vlSelfRef.ysyx_25040129_top__DOT__next_pc = ((IData)(vlSelfRef.ysyx_25040129_top__DOT__ecall)
                                                  ? vlSelfRef.ysyx_25040129_top__DOT__mtvec
                                                  : 
                                                 ((IData)(vlSelfRef.ysyx_25040129_top__DOT__mret)
                                                   ? vlSelfRef.ysyx_25040129_top__DOT__mepc
                                                   : 
                                                  (((0x63U 
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
                                                   ((0U 
                                                     == vlSelfRef.pc)
                                                     ? 0x80000000U
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlSelfRef.pc)))));
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
                        if (vlSelfRef.ysyx_25040129_top__DOT__ebreak) {
                            Vtop___024unit____Vdpiimwrap_ebreak_trigger_TOP____024unit();
                        }
                        vlSelfRef.ysyx_25040129_top__DOT__result 
                            = ((IData)(vlSelfRef.ysyx_25040129_top__DOT__csr_read)
                                ? ((0x300U == (0xfffU 
                                               & vlSelfRef.ysyx_25040129_top__DOT__imm))
                                    ? vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus
                                    : ((0x305U == (0xfffU 
                                                   & vlSelfRef.ysyx_25040129_top__DOT__imm))
                                        ? vlSelfRef.ysyx_25040129_top__DOT__mtvec
                                        : ((0x341U 
                                            == (0xfffU 
                                                & vlSelfRef.ysyx_25040129_top__DOT__imm))
                                            ? vlSelfRef.ysyx_25040129_top__DOT__mepc
                                            : ((0x342U 
                                                == 
                                                (0xfffU 
                                                 & vlSelfRef.ysyx_25040129_top__DOT__imm))
                                                ? vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mcause
                                                : 0U))))
                                : 0U);
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
