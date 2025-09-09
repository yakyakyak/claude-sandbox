// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner__Syms.h"
#include "Vtestrunner_svunit_pkg__03a__03a__VDynScope_12__Vclpkg.h"

Vtestrunner_svunit_pkg__03a__03a__VDynScope_12::Vtestrunner_svunit_pkg__03a__03a__VDynScope_12(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vtestrunner_svunit_pkg__03a__03a__VDynScope_12::new\n"); );
    // Init
    _ctor_var_reset(vlSymsp);
}

void Vtestrunner_svunit_pkg__03a__03a__VDynScope_12::_ctor_var_reset(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vtestrunner_svunit_pkg__03a__03a__VDynScope_12::_ctor_var_reset\n"); );
    // Body
    (void)vlSymsp;  // Prevent unused variable warning
    __PVT__local_error_count = VL_SCOPED_RAND_RESET_I(32, 11245092038757658566ULL, 9266969362111581158ull);
}
