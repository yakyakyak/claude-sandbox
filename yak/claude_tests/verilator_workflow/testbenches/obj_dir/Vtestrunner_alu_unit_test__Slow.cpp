// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner__Syms.h"
#include "Vtestrunner_alu_unit_test.h"

void Vtestrunner_alu_unit_test___ctor_var_reset(Vtestrunner_alu_unit_test* vlSelf);

Vtestrunner_alu_unit_test::Vtestrunner_alu_unit_test(Vtestrunner__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtestrunner_alu_unit_test___ctor_var_reset(this);
}

void Vtestrunner_alu_unit_test::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtestrunner_alu_unit_test::~Vtestrunner_alu_unit_test() {
}
