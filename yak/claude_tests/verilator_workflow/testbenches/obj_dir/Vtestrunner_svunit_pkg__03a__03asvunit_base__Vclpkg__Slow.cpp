// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner__Syms.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg.h"

void Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg___ctor_var_reset(Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg* vlSelf);

Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg::Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg(Vtestrunner__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg___ctor_var_reset(this);
}

void Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg::~Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg() {
}
