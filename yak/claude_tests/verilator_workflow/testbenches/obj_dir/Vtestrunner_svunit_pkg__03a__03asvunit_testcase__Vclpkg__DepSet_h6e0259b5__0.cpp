// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner__Syms.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"

Vtestrunner_svunit_pkg__03a__03asvunit_testcase::Vtestrunner_svunit_pkg__03a__03asvunit_testcase(Vtestrunner__Syms* __restrict vlSymsp, std::string name)
    : Vtestrunner_svunit_pkg__03a__03asvunit_base(vlSymsp, name) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::new\n"); );
    // Init
    _ctor_var_reset(vlSymsp);
    // Body
    this->__PVT__actually_ran_tests = 0U;
    this->__PVT__running = 0U;
    this->__PVT__error_count = 0U;
    this->__PVT__test_count = 0U;
    ;
}

VlCoroutine Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_wait_for_error(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_wait_for_error\n"); );
    // Init
    VL_KEEP_THIS;
    IData/*31:0*/ __Vtrigprevexpr___TOP__svunit_pkg__03a__03asvunit_testcase____PVT__error_count__0;
    __Vtrigprevexpr___TOP__svunit_pkg__03a__03asvunit_testcase____PVT__error_count__0 = 0;
    // Body
    CData/*0:0*/ __VdynTrigger_hbbabdeb7__0;
    __VdynTrigger_hbbabdeb7__0 = 0;
    __VdynTrigger_hbbabdeb7__0 = 0U;
    __Vtrigprevexpr___TOP__svunit_pkg__03a__03asvunit_testcase____PVT__error_count__0 
        = this->__PVT__error_count;
    while ((1U & (~ (IData)(__VdynTrigger_hbbabdeb7__0)))) {
        co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                     nullptr, 
                                                     "@( svunit_pkg::svunit_testcase.error_count)", 
                                                     "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 
                                                     196);
        __VdynTrigger_hbbabdeb7__0 = (this->__PVT__error_count 
                                      != __Vtrigprevexpr___TOP__svunit_pkg__03a__03asvunit_testcase____PVT__error_count__0);
        vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_hbbabdeb7__0);
        __Vtrigprevexpr___TOP__svunit_pkg__03a__03asvunit_testcase____PVT__error_count__0 
            = this->__PVT__error_count;
    }
    co_await vlSymsp->TOP.__VdynSched.resumption(nullptr, 
                                                 "@( svunit_pkg::svunit_testcase.error_count)", 
                                                 "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 
                                                 196);
}

VlCoroutine Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_give_up(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_give_up\n"); );
    // Init
    VL_KEEP_THIS;
    // Body
    CData/*0:0*/ never_true;
    never_true = 0;
    never_true = 0U;
    CData/*0:0*/ __VdynTrigger_h4751e146__0;
    __VdynTrigger_h4751e146__0 = 0;
    __VdynTrigger_h4751e146__0 = 0U;
    while ((1U & (~ (IData)(__VdynTrigger_h4751e146__0)))) {
        co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                     nullptr, 
                                                     "@([true] svunit_pkg::svunit_testcase.never_true)", 
                                                     "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 
                                                     219);
        __VdynTrigger_h4751e146__0 = never_true;
        vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_h4751e146__0);
    }
    co_await vlSymsp->TOP.__VdynSched.resumption(nullptr, 
                                                 "@([true] svunit_pkg::svunit_testcase.never_true)", 
                                                 "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 
                                                 219);
}

VlCoroutine Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc____05Fwait_until_started(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc____05Fwait_until_started\n"); );
    // Init
    VL_KEEP_THIS;
    // Body
    if ((1U & (~ (IData)(this->__PVT__running)))) {
        CData/*0:0*/ __VdynTrigger_hbb27b578__0;
        __VdynTrigger_hbb27b578__0 = 0;
        __VdynTrigger_hbb27b578__0 = 0U;
        while ((1U & (~ (IData)(__VdynTrigger_hbb27b578__0)))) {
            co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                         nullptr, 
                                                         "@([true] svunit_pkg::svunit_testcase.running)", 
                                                         "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 
                                                         288);
            __VdynTrigger_hbb27b578__0 = this->__PVT__running;
            vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_hbb27b578__0);
        }
        co_await vlSymsp->TOP.__VdynSched.resumption(
                                                     nullptr, 
                                                     "@([true] svunit_pkg::svunit_testcase.running)", 
                                                     "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 
                                                     288);
    }
}

void Vtestrunner_svunit_pkg__03a__03asvunit_testcase::_ctor_var_reset(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::_ctor_var_reset\n"); );
    // Body
    (void)vlSymsp;  // Prevent unused variable warning
    __PVT__test_count = 0;
    __PVT__error_count = 0;
    __PVT__running = 0;
    __PVT__actually_ran_tests = 0;
    }
