// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_ysyx_25040129_IDU.h"

void Vtop_ysyx_25040129_IDU___ctor_var_reset(Vtop_ysyx_25040129_IDU* vlSelf);

Vtop_ysyx_25040129_IDU::Vtop_ysyx_25040129_IDU(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_ysyx_25040129_IDU___ctor_var_reset(this);
}

void Vtop_ysyx_25040129_IDU::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_ysyx_25040129_IDU::~Vtop_ysyx_25040129_IDU() {
}
