// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_ysyx_25040129_IFU.h"

void Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ is_fetch, IData/*31:0*/ is_avail, IData/*31:0*/ &paddr_read__Vfuncrtn);

VL_INLINE_OPT void Vtop_ysyx_25040129_IFU___nba_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_IFU__0(Vtop_ysyx_25040129_IFU* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_IFU___nba_sequent__TOP__ysyx_25040129_top__u_ysyx_25040129_IFU__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__inst = ((0U == vlSelfRef.__PVT__pc)
                              ? ([&]() {
                Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(0x80000000U, 4U, 1U, 1U, vlSelfRef.__Vfunc_paddr_read__0__Vfuncout);
            }(), vlSelfRef.__Vfunc_paddr_read__0__Vfuncout)
                              : ([&]() {
                Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.__PVT__pc, 4U, 1U, 1U, vlSelfRef.__Vfunc_paddr_read__1__Vfuncout);
            }(), vlSelfRef.__Vfunc_paddr_read__1__Vfuncout));
}
