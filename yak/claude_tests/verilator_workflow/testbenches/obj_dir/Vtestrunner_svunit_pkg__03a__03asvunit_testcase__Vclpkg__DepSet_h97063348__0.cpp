// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"

VL_INLINE_OPT VlCoroutine Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_run_test____Vfork_1__0____Vfork_2__0(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test> test, VlForkSync __Vfork_2__sync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_run_test____Vfork_1__0____Vfork_2__0\n"); );
    // Init
    VL_KEEP_THIS;
    VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test> __Vtask___Vfork_stmt__0__15__test;
    // Body
    __Vtask___Vfork_stmt__0__15__test = test;
    co_await VL_NULL_CHECK(__Vtask___Vfork_stmt__0__15__test, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 153)->__VnoInFunc_run(vlSymsp);
    __Vfork_2__sync.done("/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 
                         153);
}
