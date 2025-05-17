// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_ysyx_25040129_top.h"

void Vtop_ysyx_25040129_top___ctor_var_reset(Vtop_ysyx_25040129_top* vlSelf);

Vtop_ysyx_25040129_top::Vtop_ysyx_25040129_top(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_ysyx_25040129_top___ctor_var_reset(this);
}

void Vtop_ysyx_25040129_top::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_ysyx_25040129_top::~Vtop_ysyx_25040129_top() {
}
