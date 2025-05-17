// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_ysyx_25040129_MEM.h"

void Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ is_fetch, IData/*31:0*/ is_avail, IData/*31:0*/ &paddr_read__Vfuncrtn);
void Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(IData/*31:0*/ inst);
void Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ data, IData/*31:0*/ is_avail);

VL_INLINE_OPT void Vtop_ysyx_25040129_MEM___nba_comb__TOP__ysyx_25040129_top__u_ysyx_25040129_MEM__0(Vtop_ysyx_25040129_MEM* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_MEM___nba_comb__TOP__ysyx_25040129_top__u_ysyx_25040129_MEM__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__addr = (vlSelfRef.__PVT__src1 
                             + vlSelfRef.__PVT__imm);
    if ((3U == (IData)(vlSelfRef.__PVT__opcode))) {
        Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.__PVT__addr, 4U, 0U, 
                                                               VL_EXTEND_II(32,1, (IData)(vlSelfRef.__PVT__is_avail_read)), vlSelfRef.__Vfunc_paddr_read__0__Vfuncout);
        vlSelfRef.__PVT__read_data = vlSelfRef.__Vfunc_paddr_read__0__Vfuncout;
    } else if ((0x23U == (IData)(vlSelfRef.__PVT__opcode))) {
        if ((0U == (IData)(vlSelfRef.__PVT__funct3))) {
            vlSelfRef.__PVT__write_len = 1U;
        } else if ((1U == (IData)(vlSelfRef.__PVT__funct3))) {
            vlSelfRef.__PVT__write_len = 2U;
        } else if ((2U == (IData)(vlSelfRef.__PVT__funct3))) {
            vlSelfRef.__PVT__write_len = 4U;
        } else {
            vlSelfRef.__PVT__write_len = 0U;
            Vtop___024unit____Vdpiimwrap_unknown_inst_TOP____024unit(0U);
        }
        Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(vlSelfRef.__PVT__addr, 
                                                                VL_EXTEND_II(32,3, (IData)(vlSelfRef.__PVT__write_len)), vlSelfRef.__PVT__src2, 
                                                                VL_EXTEND_II(32,1, (IData)(vlSelfRef.__PVT__is_avail_write)));
    }
}
