// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_srl__Vclpkg.h"

VlCoroutine Vtestrunner_alu_unit_test__03a__03atest_srl::__VnoInFunc_run(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtestrunner_alu_unit_test__03a__03atest_srl::__VnoInFunc_run\n"); );
    // Init
    VL_KEEP_THIS;
    // Body
    VlForkSync __Vfork_1__sync;
    __Vfork_1__sync.init(1U, nullptr);
    this->__VnoInFunc_run____Vfork_1__0(vlSymsp, __Vfork_1__sync);
    co_await __Vfork_1__sync.join(nullptr, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 
                                  202);
    co_return;
}

std::string VL_TO_STRING(const VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_srl>& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtestrunner_alu_unit_test__03a__03atest_srl::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->to_string() : "null");
}

std::string Vtestrunner_alu_unit_test__03a__03atest_srl::to_string() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtestrunner_alu_unit_test__03a__03atest_srl::to_string\n"); );
    // Body
    return ("'{"s + to_string_middle() + "}");
}

std::string Vtestrunner_alu_unit_test__03a__03atest_srl::to_string_middle() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtestrunner_alu_unit_test__03a__03atest_srl::to_string_middle\n"); );
    // Body
    std::string out;
    out += Vtestrunner_svunit_pkg__03a__03asvunit_test::to_string_middle();
    return out;
}
