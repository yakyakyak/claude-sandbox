// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"

void Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_add_test(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test> test) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_add_test\n"); );
    // Body
    this->__PVT__tests.push_back(test);
}

void Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_get_tests(Vtestrunner__Syms* __restrict vlSymsp, VlQueue<VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test>> &get_tests__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_get_tests\n"); );
    // Body
    get_tests__Vfuncrtn = this->__PVT__tests;
}

void Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_as_junit_test_cases(Vtestrunner__Syms* __restrict vlSymsp, VlQueue<VlClassRef<Vtestrunner_junit_xml__03a__03aTestCase>> &as_junit_test_cases__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_as_junit_test_cases\n"); );
    // Body
    as_junit_test_cases__Vfuncrtn = this->__PVT__junit_test_cases;
}

VlCoroutine Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_run(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_run\n"); );
    // Init
    VL_KEEP_THIS;
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    {
        __Vtemp_1[0U] = 0x45535453U;
        __Vtemp_1[1U] = 0x53545f54U;
        __Vtemp_1[2U] = 0x545f4c49U;
        __Vtemp_1[3U] = 0x56554e49U;
        __Vtemp_1[4U] = 0x53U;
        if (VL_TESTPLUSARGS_I(VL_CVT_PACK_STR_NW(5, __Vtemp_1))) {
            this->__VnoInFunc_list_tests(vlSymsp);
            goto __Vlabel3;
        }
        co_await this->__VnoInFunc_run_tests(vlSymsp);
        __Vlabel3: ;
    }
}

VL_INLINE_OPT VlCoroutine Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_run_test____Vfork_1__0(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test> &test, VlClassRef<Vtestrunner_svunit_pkg__03a__03a__VDynScope_12> &__VDynScope_run_test_0, VlForkSync __Vfork_1__sync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_run_test____Vfork_1__0\n"); );
    // Init
    VL_KEEP_THIS;
    // Body
    VlForkSync __Vfork_2__sync;
    __Vfork_2__sync.init(1U, nullptr);
    this->__VnoInFunc_run_test____Vfork_1__0____Vfork_2__0(vlSymsp, test, __Vfork_2__sync);
    this->__VnoInFunc_run_test____Vfork_1__0____Vfork_2__1(vlSymsp, __VDynScope_run_test_0, __Vfork_2__sync);
    co_await __Vfork_2__sync.join(nullptr, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 
                                  152);
    __Vfork_1__sync.done("/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 
                         151);
    co_return;
}

void Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_get_error_count(Vtestrunner__Syms* __restrict vlSymsp, IData/*31:0*/ &get_error_count__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_get_error_count\n"); );
    // Body
    get_error_count__Vfuncrtn = this->__PVT__error_count;
}

void Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_start(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_start\n"); );
    // Body
    this->__PVT__running = 1U;
    this->__PVT__test_count = ((IData)(1U) + this->__PVT__test_count);
}

void Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_stop(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_stop\n"); );
    // Body
    this->__PVT__running = 0U;
}

void Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_is_running(Vtestrunner__Syms* __restrict vlSymsp, CData/*0:0*/ &is_running__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_is_running\n"); );
    // Body
    is_running__Vfuncrtn = this->__PVT__running;
}

std::string VL_TO_STRING(const VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_testcase>& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->to_string() : "null");
}

std::string Vtestrunner_svunit_pkg__03a__03asvunit_testcase::to_string() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::to_string\n"); );
    // Body
    return ("'{"s + to_string_middle() + "}");
}

std::string Vtestrunner_svunit_pkg__03a__03asvunit_testcase::to_string_middle() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::to_string_middle\n"); );
    // Body
    std::string out;
    out += "test_count:" + VL_TO_STRING(__PVT__test_count);
    out += ", error_count:" + VL_TO_STRING(__PVT__error_count);
    out += ", running:" + VL_TO_STRING(__PVT__running);
    out += ", actually_ran_tests:" + VL_TO_STRING(__PVT__actually_ran_tests);
    out += ", tests:" + VL_TO_STRING(__PVT__tests);
    out += ", current_junit_test_case:" + VL_TO_STRING(__PVT__current_junit_test_case);
    out += ", junit_test_cases:" + VL_TO_STRING(__PVT__junit_test_cases);
    out += ", "+ Vtestrunner_svunit_pkg__03a__03asvunit_base::to_string_middle();
    return out;
}
