// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_ysyx_25040129_CSR.h"

void Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(IData/*31:0*/ inst);

VL_INLINE_OPT void Vtop_ysyx_25040129_CSR___nba_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_CSR__0(Vtop_ysyx_25040129_CSR* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_CSR___nba_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_CSR__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__mstatus = vlSelfRef.__PVT__mstatus;
    vlSelfRef.__Vdly__mcause = vlSelfRef.__PVT__mcause;
    vlSelfRef.__Vdly__mepc = vlSelfRef.__PVT__mepc;
    vlSelfRef.__Vdly__mtvec = vlSelfRef.__PVT__mtvec;
    vlSelfRef.__Vdly__csr_out = vlSelfRef.__PVT__csr_out;
    if (vlSelfRef.__PVT__ecall) {
        vlSelfRef.__Vdly__mepc = ((IData)(4U) + vlSelfRef.__PVT__mepc_data);
        vlSelfRef.__Vdly__mstatus = vlSelfRef.__PVT__mstate_data;
        vlSelfRef.__Vdly__mcause = vlSelfRef.__PVT__mcause_data;
    } else if (vlSelfRef.__PVT__csr_write) {
        if ((0x300U == (IData)(vlSelfRef.__PVT__csr_addr))) {
            vlSelfRef.__Vdly__mstatus = vlSelfRef.__PVT__csr_data;
        } else if ((0x305U == (IData)(vlSelfRef.__PVT__csr_addr))) {
            vlSelfRef.__Vdly__mtvec = vlSelfRef.__PVT__csr_data;
        } else if ((0x341U == (IData)(vlSelfRef.__PVT__csr_addr))) {
            vlSelfRef.__Vdly__mepc = vlSelfRef.__PVT__csr_data;
        } else if ((0x342U == (IData)(vlSelfRef.__PVT__csr_addr))) {
            vlSelfRef.__Vdly__mcause = vlSelfRef.__PVT__csr_data;
        } else {
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(
                                                                     VL_EXTEND_II(32,12, (IData)(vlSelfRef.__PVT__csr_addr)));
        }
    } else {
        vlSelfRef.__Vdly__csr_out = ((IData)(vlSelfRef.__PVT__csr_read)
                                      ? ((0x300U == (IData)(vlSelfRef.__PVT__csr_addr))
                                          ? vlSelfRef.__PVT__mstatus
                                          : ((0x305U 
                                              == (IData)(vlSelfRef.__PVT__csr_addr))
                                              ? vlSelfRef.__PVT__mtvec
                                              : ((0x341U 
                                                  == (IData)(vlSelfRef.__PVT__csr_addr))
                                                  ? vlSelfRef.__PVT__mepc
                                                  : 
                                                 ((0x342U 
                                                   == (IData)(vlSelfRef.__PVT__csr_addr))
                                                   ? vlSelfRef.__PVT__mcause
                                                   : 0U))))
                                      : 0U);
    }
    vlSelfRef.__PVT__mstatus = vlSelfRef.__Vdly__mstatus;
    vlSelfRef.__PVT__mcause = vlSelfRef.__Vdly__mcause;
    vlSelfRef.__PVT__mepc = vlSelfRef.__Vdly__mepc;
    vlSelfRef.__PVT__mtvec = vlSelfRef.__Vdly__mtvec;
    vlSelfRef.__PVT__csr_out = vlSelfRef.__Vdly__csr_out;
}
