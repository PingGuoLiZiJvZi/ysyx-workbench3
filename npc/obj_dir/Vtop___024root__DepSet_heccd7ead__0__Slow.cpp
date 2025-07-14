// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/pglzjz/ysyx-workbench/npc/vsrc/top.v", 5, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vm_traceActivitySetAll\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->ifu_state = VL_RAND_RESET_I(3);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->inst = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(512, vlSelf->regs);
    vlSelf->ysyx_25040129_top__DOT__inst_from_mmem = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__pc_from_ifu = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__inst_to_idu = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__is_rsp_valid_from_mmem_to_ifu = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040129_top__DOT__is_jalr_out_idu = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040129_top__DOT__src2_in_idu = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__src1_out_idu = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__src2_out_idu = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__alu_opcode = VL_RAND_RESET_I(4);
    vlSelf->ysyx_25040129_top__DOT__reg_write_out_idu = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040129_top__DOT__lsu_write_out_idu = VL_RAND_RESET_I(2);
    vlSelf->ysyx_25040129_top__DOT__lsu_read_out_idu = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25040129_top__DOT__ecall_out_idu = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040129_top__DOT__is_jump_out_idu = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040129_top__DOT__ebreak_out_idu = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040129_top__DOT__mret_out_idu = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040129_top__DOT__csr_write_out_idu = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040129_top__DOT__result_out_exu = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__branch_target_out_exu = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__result_out_lsu = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__mmem_read_data_in_lsu = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__is_req_valid_from_lsu_to_mmem = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040129_top__DOT__is_rsp_valid_from_mmem_to_lsu = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040129_top__DOT__target_from_csr_to_wbu = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__csr_write_out_wbu = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_IFU__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_IFU__DOT__next_state = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_IFU__DOT__next_state = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_IDU__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_IDU__DOT__next_state = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(512, vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_REG__DOT__regs);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mepc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mstatus = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mcause = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_CSR__DOT__mtvec = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__next_state = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_EXU__DOT__is_branch = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_LSU__DOT__next_state = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_LSU__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_MMEM_LSU__DOT__next_state = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_WBU__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_WBU__DOT__next_state = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25040129_top__DOT__u_ysyx_25040129_WBU__DOT____VdfgRegularize_h4ef58c57_2_0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vtableidx2 = 0;
    vlSelf->__Vtableidx3 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
