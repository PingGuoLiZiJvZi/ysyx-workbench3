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

extern const VlUnpacked<CData/*2:0*/, 32> Vtop__ConstPool__TABLE_hf33715c7_0;
extern const VlUnpacked<CData/*2:0*/, 128> Vtop__ConstPool__TABLE_hdd74e3d6_0;
void Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(IData/*31:0*/ inst);
void Vtop___024unit____Vdpiimwrap_ebreak_trigger_TOP____024unit();
extern const VlUnpacked<CData/*2:0*/, 1024> Vtop__ConstPool__TABLE_h3215e74e_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc = vlSelfRef.ysyx_25040129_top__DOT__pc_from_ifu;
    vlSelfRef.inst = vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu;
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
    vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_IDU__DOT__next_state 
        = ((0U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_IDU__DOT__state))
            ? ((3U == (IData)(vlSelfRef.ifu_state))
                ? 1U : 0U) : ((1U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_IDU__DOT__state))
                               ? ((0U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__state))
                                   ? 0U : 1U) : 0U));
    vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__next_state 
        = ((0U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__state))
            ? ((1U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_IDU__DOT__state))
                ? 1U : 0U) : ((1U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__state))
                               ? ((0U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state))
                                   ? 0U : 1U) : 0U));
    vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_WBU__DOT__next_state 
        = ((0U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_WBU__DOT__state))
            ? ((5U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state))
                ? 1U : 0U) : ((1U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_WBU__DOT__state))
                               ? ((0U == (IData)(vlSelfRef.ifu_state))
                                   ? 0U : 1U) : 0U));
    vlSelfRef.__Vtableidx1 = (((2U == (IData)(vlSelfRef.ifu_state)) 
                               << 4U) | (((1U == (IData)(vlSelfRef.ifu_state)) 
                                          << 3U) | (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_IFU__DOT__state)));
    vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_IFU__DOT__next_state 
        = Vtop__ConstPool__TABLE_hf33715c7_0[vlSelfRef.__Vtableidx1];
    vlSelfRef.ysyx_25040129_top__DOT__is_rsp_valid_from_mmem_to_lsu 
        = ((1U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_LSU__DOT__state)) 
           | (2U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_LSU__DOT__state)));
    vlSelfRef.ysyx_25040129_top__DOT__is_rsp_valid_from_mmem_to_ifu 
        = ((1U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_IFU__DOT__state)) 
           | (2U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_IFU__DOT__state)));
    vlSelfRef.ysyx_25040129_top__DOT__is_req_valid_from_lsu_to_mmem 
        = ((1U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state)) 
           | (2U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state)));
    vlSelfRef.ysyx_25040129_top__DOT__src2_in_idu = 
        (((0U == (0x1fU & VL_SHIFTL_III(9,9,32, (0x1fU 
                                                 & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                    >> 0x14U)), 5U)))
           ? 0U : (vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[
                   (((IData)(0x1fU) + (0x1ffU & VL_SHIFTL_III(9,9,32, 
                                                              (0x1fU 
                                                               & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                                  >> 0x14U)), 5U))) 
                    >> 5U)] << ((IData)(0x20U) - (0x1fU 
                                                  & VL_SHIFTL_III(9,9,32, 
                                                                  (0x1fU 
                                                                   & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                                      >> 0x14U)), 5U))))) 
         | (vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[
            (0xfU & (VL_SHIFTL_III(9,9,32, (0x1fU & 
                                            (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                             >> 0x14U)), 5U) 
                     >> 5U))] >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                        (0x1fU 
                                                         & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                            >> 0x14U)), 5U))));
    vlSelfRef.__Vtableidx2 = ((((1U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_WBU__DOT__state)) 
                                << 6U) | ((0U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_IFU__DOT__state)) 
                                          << 5U)) | 
                              (((IData)(vlSelfRef.ysyx_25040129_top__DOT__is_rsp_valid_from_mmem_to_ifu) 
                                << 4U) | (((0U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_IDU__DOT__state)) 
                                           << 3U) | (IData)(vlSelfRef.ifu_state))));
    vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_IFU__DOT__next_state 
        = Vtop__ConstPool__TABLE_hdd74e3d6_0[vlSelfRef.__Vtableidx2];
    vlSelfRef.ysyx_25040129_top__DOT__reg_write_out_idu = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__is_jump_out_idu = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__ecall_out_idu = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__ebreak_out_idu = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__mret_out_idu = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__is_jalr_out_idu = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__csr_write_out_idu = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__lsu_write_out_idu = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__lsu_read_out_idu = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
        = (((0U == (0x1fU & VL_SHIFTL_III(9,9,32, (0x1fU 
                                                   & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                      >> 0xfU)), 5U)))
             ? 0U : (vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[
                     (((IData)(0x1fU) + (0x1ffU & VL_SHIFTL_III(9,9,32, 
                                                                (0x1fU 
                                                                 & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                                    >> 0xfU)), 5U))) 
                      >> 5U)] << ((IData)(0x20U) - 
                                  (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                         (0x1fU 
                                                          & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                             >> 0xfU)), 5U))))) 
           | (vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs[
              (0xfU & (VL_SHIFTL_III(9,9,32, (0x1fU 
                                              & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                 >> 0xfU)), 5U) 
                       >> 5U))] >> (0x1fU & VL_SHIFTL_III(9,9,32, 
                                                          (0x1fU 
                                                           & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                              >> 0xfU)), 5U))));
    vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu 
        = vlSelfRef.ysyx_25040129_top__DOT__src2_in_idu;
    if ((0x40U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
        if ((0x20U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
            if ((0x10U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                if ((8U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                } else if ((4U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                } else if ((2U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                    if ((1U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                        vlSelfRef.ysyx_25040129_top__DOT__imm 
                            = (((- (IData)((vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                            >> 0x14U));
                        if ((0U == (7U & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                          >> 0xcU)))) {
                            if ((1U == (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                        >> 0x14U))) {
                                vlSelfRef.ysyx_25040129_top__DOT__ebreak_out_idu = 1U;
                            } else if ((0x302U == (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                   >> 0x14U))) {
                                vlSelfRef.ysyx_25040129_top__DOT__mret_out_idu = 1U;
                            } else if ((0U == (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                               >> 0x14U))) {
                                vlSelfRef.ysyx_25040129_top__DOT__ecall_out_idu = 1U;
                            } else {
                                Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                            }
                        } else if ((1U == (7U & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                 >> 0xcU)))) {
                            vlSelfRef.ysyx_25040129_top__DOT__csr_write_out_idu = 1U;
                            vlSelfRef.ysyx_25040129_top__DOT__reg_write_out_idu = 0U;
                            vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu = 0U;
                            vlSelfRef.ysyx_25040129_top__DOT__alu_opcode = 0U;
                        } else if ((2U == (7U & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                 >> 0xcU)))) {
                            vlSelfRef.ysyx_25040129_top__DOT__reg_write_out_idu = 1U;
                            vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu 
                                = ((0x300U == (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                               >> 0x14U))
                                    ? vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus
                                    : ((0x305U == (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                   >> 0x14U))
                                        ? vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mtvec
                                        : ((0x341U 
                                            == (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                >> 0x14U))
                                            ? vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mepc
                                            : ((0x342U 
                                                == 
                                                (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                 >> 0x14U))
                                                ? vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mcause
                                                : 0U))));
                            vlSelfRef.ysyx_25040129_top__DOT__alu_opcode = 6U;
                        } else {
                            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                            vlSelfRef.ysyx_25040129_top__DOT__alu_opcode = 0U;
                        }
                    } else {
                        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    }
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                }
            } else if ((8U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                if ((4U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                    if ((2U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                        if ((1U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                            vlSelfRef.ysyx_25040129_top__DOT__imm 
                                = (((- (IData)((vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                >> 0x1fU))) 
                                    << 0x14U) | (((0xff000U 
                                                   & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu) 
                                                  | (0x800U 
                                                     & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                        >> 9U))) 
                                                 | (0x7feU 
                                                    & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                       >> 0x14U))));
                            vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                                = vlSelfRef.ysyx_25040129_top__DOT__pc_from_ifu;
                            vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu 
                                = vlSelfRef.ysyx_25040129_top__DOT__imm;
                            vlSelfRef.ysyx_25040129_top__DOT__alu_opcode = 0U;
                            vlSelfRef.ysyx_25040129_top__DOT__is_jump_out_idu = 1U;
                            vlSelfRef.ysyx_25040129_top__DOT__is_jalr_out_idu = 1U;
                            vlSelfRef.ysyx_25040129_top__DOT__reg_write_out_idu = 1U;
                        } else {
                            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                        }
                    } else {
                        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    }
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                }
            } else if ((4U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                if ((2U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                    if ((1U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                        vlSelfRef.ysyx_25040129_top__DOT__imm 
                            = (((- (IData)((vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                            >> 0x14U));
                        vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu 
                            = vlSelfRef.ysyx_25040129_top__DOT__imm;
                        vlSelfRef.ysyx_25040129_top__DOT__alu_opcode = 0U;
                        vlSelfRef.ysyx_25040129_top__DOT__is_jump_out_idu = 1U;
                        vlSelfRef.ysyx_25040129_top__DOT__is_jalr_out_idu = 1U;
                        vlSelfRef.ysyx_25040129_top__DOT__reg_write_out_idu = 1U;
                    } else {
                        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    }
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                }
            } else if ((2U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                if ((1U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                    vlSelfRef.ysyx_25040129_top__DOT__imm 
                        = (((- (IData)((vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                        >> 0x1fU))) 
                            << 0xcU) | ((0x800U & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                   << 4U)) 
                                        | ((0x7e0U 
                                            & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                               >> 0x14U)) 
                                           | (0x1eU 
                                              & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                 >> 7U)))));
                    if ((0x4000U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                        vlSelfRef.ysyx_25040129_top__DOT__alu_opcode 
                            = ((0x2000U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)
                                ? ((0x1000U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)
                                    ? 0xfU : 0xeU) : 
                               ((0x1000U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)
                                 ? 0xcU : 0xbU));
                    } else if ((0x2000U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                        vlSelfRef.ysyx_25040129_top__DOT__alu_opcode = 0U;
                    } else {
                        vlSelfRef.ysyx_25040129_top__DOT__alu_opcode 
                            = ((0x1000U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)
                                ? 0xaU : 9U);
                    }
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                }
            } else {
                Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
            }
        } else {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
        }
    } else if ((0x20U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
        if ((0x10U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
            if ((8U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
            } else if ((4U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                if ((2U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                    if ((1U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                        vlSelfRef.ysyx_25040129_top__DOT__imm 
                            = (0xfffff000U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                        vlSelfRef.ysyx_25040129_top__DOT__reg_write_out_idu = 1U;
                        vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu = 0U;
                        vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu 
                            = vlSelfRef.ysyx_25040129_top__DOT__imm;
                        vlSelfRef.ysyx_25040129_top__DOT__alu_opcode = 0U;
                    } else {
                        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    }
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                }
            } else if ((2U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                if ((1U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write_out_idu = 1U;
                    vlSelfRef.ysyx_25040129_top__DOT__alu_opcode 
                        = ((8U & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                  >> 0x1bU)) | (7U 
                                                & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                   >> 0xcU)));
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                }
            } else {
                Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
            }
        } else if ((8U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
        } else if ((4U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
        } else if ((2U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
            if ((1U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                vlSelfRef.ysyx_25040129_top__DOT__imm 
                    = (((- (IData)((vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                                      >> 7U))));
                vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu 
                    = vlSelfRef.ysyx_25040129_top__DOT__imm;
                vlSelfRef.ysyx_25040129_top__DOT__alu_opcode = 0U;
                if ((0U == (7U & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                  >> 0xcU)))) {
                    vlSelfRef.ysyx_25040129_top__DOT__lsu_write_out_idu = 1U;
                } else if ((1U == (7U & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                         >> 0xcU)))) {
                    vlSelfRef.ysyx_25040129_top__DOT__lsu_write_out_idu = 2U;
                } else if ((2U == (7U & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                         >> 0xcU)))) {
                    vlSelfRef.ysyx_25040129_top__DOT__lsu_write_out_idu = 3U;
                }
            } else {
                Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
            }
        } else {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
        }
    } else if ((0x10U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
        if ((8U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
        } else if ((4U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
            if ((2U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                if ((1U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                    vlSelfRef.ysyx_25040129_top__DOT__imm 
                        = (0xfffff000U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                    vlSelfRef.ysyx_25040129_top__DOT__reg_write_out_idu = 1U;
                    vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                        = vlSelfRef.ysyx_25040129_top__DOT__pc_from_ifu;
                    vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu 
                        = vlSelfRef.ysyx_25040129_top__DOT__imm;
                    vlSelfRef.ysyx_25040129_top__DOT__alu_opcode = 0U;
                } else {
                    Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                    vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
                }
            } else {
                Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
            }
        } else if ((2U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
            if ((1U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                vlSelfRef.ysyx_25040129_top__DOT__imm 
                    = (((- (IData)((vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                          >> 0x14U));
                vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu 
                    = vlSelfRef.ysyx_25040129_top__DOT__imm;
                vlSelfRef.ysyx_25040129_top__DOT__reg_write_out_idu = 1U;
                vlSelfRef.ysyx_25040129_top__DOT__alu_opcode 
                    = (((IData)((0x40005000U == (0x40007000U 
                                                 & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu))) 
                        << 3U) | (7U & (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                                        >> 0xcU)));
            } else {
                Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
                vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
            }
        } else {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
        }
    } else if ((8U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
    } else if ((4U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
    } else if ((2U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
        if ((1U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
            vlSelfRef.ysyx_25040129_top__DOT__imm = 
                (((- (IData)((vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                              >> 0x1fU))) << 0xcU) 
                 | (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                    >> 0x14U));
            vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu 
                = vlSelfRef.ysyx_25040129_top__DOT__imm;
            vlSelfRef.ysyx_25040129_top__DOT__reg_write_out_idu = 1U;
            vlSelfRef.ysyx_25040129_top__DOT__alu_opcode = 0U;
            if ((0x4000U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                if ((1U & (~ (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                              >> 0xdU)))) {
                    vlSelfRef.ysyx_25040129_top__DOT__lsu_read_out_idu 
                        = ((0x1000U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)
                            ? 5U : 4U);
                }
            } else if ((0x2000U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)) {
                if ((1U & (~ (vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu 
                              >> 0xcU)))) {
                    vlSelfRef.ysyx_25040129_top__DOT__lsu_read_out_idu = 3U;
                }
            } else {
                vlSelfRef.ysyx_25040129_top__DOT__lsu_read_out_idu 
                    = ((0x1000U & vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu)
                        ? 2U : 1U);
            }
        } else {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
            vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
        }
    } else {
        Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(vlSelfRef.ysyx_25040129_top__DOT__inst_to_idu);
        vlSelfRef.ysyx_25040129_top__DOT__imm = 0U;
    }
    if (vlSelfRef.ysyx_25040129_top__DOT__ebreak_out_idu) {
        Vtop___024unit____Vdpiimwrap_ebreak_trigger_TOP____024unit();
    }
    vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_WBU__DOT____VdfgRegularize_h4ef58c57_2_0 
        = ((IData)(vlSelfRef.ysyx_25040129_top__DOT__ecall_out_idu) 
           | (IData)(vlSelfRef.ysyx_25040129_top__DOT__mret_out_idu));
    vlSelfRef.ysyx_25040129_top__DOT__csr_write_out_wbu 
        = ((IData)(vlSelfRef.ysyx_25040129_top__DOT__csr_write_out_idu) 
           & (5U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state)));
    vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__next_state 
        = ((4U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state))
            ? ((2U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state))
                ? 0U : ((1U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state))
                         ? ((0U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_WBU__DOT__state))
                             ? 0U : 5U) : ((IData)(vlSelfRef.ysyx_25040129_top__DOT__is_rsp_valid_from_mmem_to_lsu)
                                            ? 5U : 4U)))
            : ((2U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state))
                ? ((1U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state))
                    ? ((IData)(vlSelfRef.ysyx_25040129_top__DOT__is_rsp_valid_from_mmem_to_lsu)
                        ? 5U : 3U) : ((0U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_LSU__DOT__state))
                                       ? 4U : 2U)) : 
               ((1U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state))
                 ? ((0U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_LSU__DOT__state))
                     ? 3U : 1U) : ((1U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__state))
                                    ? ((0U != (IData)(vlSelfRef.ysyx_25040129_top__DOT__lsu_read_out_idu))
                                        ? 1U : ((0U 
                                                 != (IData)(vlSelfRef.ysyx_25040129_top__DOT__lsu_write_out_idu))
                                                 ? 2U
                                                 : 5U))
                                    : 0U))));
    vlSelfRef.__Vtableidx3 = (((((3U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state)) 
                                 | (4U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state))) 
                                << 9U) | ((IData)(vlSelfRef.ysyx_25040129_top__DOT__lsu_write_out_idu) 
                                          << 7U)) | 
                              (((IData)(vlSelfRef.ysyx_25040129_top__DOT__lsu_read_out_idu) 
                                << 4U) | (((IData)(vlSelfRef.ysyx_25040129_top__DOT__is_req_valid_from_lsu_to_mmem) 
                                           << 3U) | (IData)(vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_LSU__DOT__state))));
    vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_LSU__DOT__next_state 
        = Vtop__ConstPool__TABLE_h3215e74e_0[vlSelfRef.__Vtableidx3];
    vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__is_branch = 0U;
    vlSelfRef.ysyx_25040129_top__DOT__branch_target_out_exu 
        = ((IData)(vlSelfRef.ysyx_25040129_top__DOT__is_jalr_out_idu)
            ? (vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
               + vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu)
            : (vlSelfRef.ysyx_25040129_top__DOT__imm 
               + vlSelfRef.ysyx_25040129_top__DOT__pc_from_ifu));
    vlSelfRef.ysyx_25040129_top__DOT__result_out_exu = 0U;
    if ((8U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))) {
        if ((4U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))) {
            if ((2U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))) {
                vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__is_branch 
                    = ((1U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))
                        ? (vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                           >= vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu)
                        : (vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                           < vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu));
            } else if ((1U & (~ (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode)))) {
                vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__is_branch 
                    = VL_GTES_III(32, vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu, vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu);
            }
            if ((1U & (~ ((IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))) {
                    vlSelfRef.ysyx_25040129_top__DOT__result_out_exu 
                        = VL_SHIFTRS_III(32,32,5, vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu, 
                                         (0x1fU & vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu));
                }
            }
        } else {
            if ((2U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))) {
                vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__is_branch 
                    = ((1U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))
                        ? VL_LTS_III(32, vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu, vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu)
                        : (vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                           != vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu));
            } else if ((1U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))) {
                vlSelfRef.ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__is_branch 
                    = (vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                       == vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu);
            }
            if ((1U & (~ ((IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode)))) {
                    vlSelfRef.ysyx_25040129_top__DOT__result_out_exu 
                        = (vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                           - vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu);
                }
            }
        }
    } else {
        vlSelfRef.ysyx_25040129_top__DOT__result_out_exu 
            = ((4U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))
                ? ((2U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))
                    ? ((1U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))
                        ? (vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                           & vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu)
                        : (vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                           | vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu))
                    : ((1U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))
                        ? (vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                           >> (0x1fU & vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu))
                        : (vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                           ^ vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu)))
                : ((2U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))
                    ? ((1U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))
                        ? ((vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                            < vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu)
                            ? 1U : 0U) : (VL_LTS_III(32, vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu, vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu)
                                           ? 1U : 0U))
                    : ((1U & (IData)(vlSelfRef.ysyx_25040129_top__DOT__alu_opcode))
                        ? (vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                           << (0x1fU & vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu))
                        : ((IData)(vlSelfRef.ysyx_25040129_top__DOT__is_jalr_out_idu)
                            ? ((IData)(4U) + vlSelfRef.ysyx_25040129_top__DOT__pc_from_ifu)
                            : (vlSelfRef.ysyx_25040129_top__DOT__src1_out_idu 
                               + vlSelfRef.ysyx_25040129_top__DOT__src2_out_idu)))));
    }
    vlSelfRef.ysyx_25040129_top__DOT__result_out_lsu 
        = ((0U == (IData)(vlSelfRef.ysyx_25040129_top__DOT__lsu_read_out_idu))
            ? vlSelfRef.ysyx_25040129_top__DOT__result_out_exu
            : vlSelfRef.ysyx_25040129_top__DOT__mmem_read_data_in_lsu);
}
