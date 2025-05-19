// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ysyx_25040129_CSR.h"

VL_ATTR_COLD void Vtop_ysyx_25040129_CSR___ctor_var_reset(Vtop_ysyx_25040129_CSR* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ysyx_25040129_CSR___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__clk = VL_RAND_RESET_I(1);
    vlSelf->__PVT__csr_write = VL_RAND_RESET_I(1);
    vlSelf->__PVT__csr_read = VL_RAND_RESET_I(1);
    vlSelf->__PVT__csr_addr = VL_RAND_RESET_I(12);
    vlSelf->__PVT__csr_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__csr_out = VL_RAND_RESET_I(32);
    vlSelf->__PVT__ecall = VL_RAND_RESET_I(1);
    vlSelf->__PVT__mepc_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__mstate_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__mcause_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__mtvec = VL_RAND_RESET_I(32);
    vlSelf->__PVT__mepc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__mstatus = VL_RAND_RESET_I(32);
    vlSelf->__PVT__mcause = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__mepc = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__mstatus = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__mcause = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__mtvec = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__csr_out = VL_RAND_RESET_I(32);
}
