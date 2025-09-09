// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg.h"

VlCoroutine Vtestrunner_svunit_pkg__03a__03asvunit_test::__VnoInFunc_unit_test_setup(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_test::__VnoInFunc_unit_test_setup\n"); );
    // Init
    VL_KEEP_THIS;
    // Body
    co_return;
}

VlCoroutine Vtestrunner_svunit_pkg__03a__03asvunit_test::__VnoInFunc_run(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_test::__VnoInFunc_run\n"); );
    // Init
    VL_KEEP_THIS;
    // Body
    co_return;
}

std::string VL_TO_STRING(const VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test>& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_test::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->to_string() : "null");
}

std::string Vtestrunner_svunit_pkg__03a__03asvunit_test::to_string() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_test::to_string\n"); );
    // Body
    return ("'{"s + to_string_middle() + "}");
}

std::string Vtestrunner_svunit_pkg__03a__03asvunit_test::to_string_middle() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_test::to_string_middle\n"); );
    // Body
    std::string out;
    out += Vtestrunner_svunit_pkg__03a__03asvunit_base::to_string_middle();
    return out;
}
