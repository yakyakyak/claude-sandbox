// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_svunit_pkg__03a__03a__VDynScope_12__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"

VL_INLINE_OPT VlCoroutine Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_run_test____Vfork_1__0____Vfork_2__1(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_svunit_pkg__03a__03a__VDynScope_12> __VDynScope_run_test_0, VlForkSync __Vfork_2__sync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_run_test____Vfork_1__0____Vfork_2__1\n"); );
    // Init
    VL_KEEP_THIS;
    VlClassRef<Vtestrunner_svunit_pkg__03a__03a__VDynScope_12> __Vtask___Vfork_begin__1__17____VDynScope_run_test_0;
    IData/*31:0*/ __Vfunc_get_error_count__18__Vfuncout;
    __Vfunc_get_error_count__18__Vfuncout = 0;
    // Body
    __Vtask___Vfork_begin__1__17____VDynScope_run_test_0 
        = __VDynScope_run_test_0;
    if ((([&]() {
                    this->__VnoInFunc_get_error_count(vlSymsp, __Vfunc_get_error_count__18__Vfuncout);
                }(), __Vfunc_get_error_count__18__Vfuncout) 
         == VL_NULL_CHECK(__Vtask___Vfork_begin__1__17____VDynScope_run_test_0, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 155)
         ->__PVT__local_error_count)) {
        co_await this->__VnoInFunc_wait_for_error(vlSymsp);
    }
    __Vfork_2__sync.done("/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 
                         154);
}
