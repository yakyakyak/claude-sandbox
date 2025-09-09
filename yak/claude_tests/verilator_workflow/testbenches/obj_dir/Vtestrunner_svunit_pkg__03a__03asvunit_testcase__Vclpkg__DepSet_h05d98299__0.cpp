// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner__Syms.h"
#include "Vtestrunner_svunit_pkg__03a__03a__VDynScope_12__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"

VlCoroutine Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_run_test(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test> test) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_run_test\n"); );
    // Init
    VL_KEEP_THIS;
    std::string __Vtask_get_name__10__Vfuncout;
    IData/*31:0*/ __Vfunc_get_error_count__11__Vfuncout;
    __Vfunc_get_error_count__11__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_get_error_count__22__Vfuncout;
    __Vfunc_get_error_count__22__Vfuncout = 0;
    std::string __Vtemp_1;
    std::string __Vtemp_2;
    std::string __Vtemp_3;
    // Body
    VlClassRef<Vtestrunner_svunit_pkg__03a__03a__VDynScope_12> __VDynScope_run_test_0;
    std::string _testName;
    __VDynScope_run_test_0 = VL_NEW(Vtestrunner_svunit_pkg__03a__03a__VDynScope_12, vlSymsp);
    VL_NULL_CHECK(test, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 140)->__VnoInFunc_get_name(vlSymsp, __Vtask_get_name__10__Vfuncout);
    _testName = __Vtask_get_name__10__Vfuncout;
    this->__VnoInFunc_get_error_count(vlSymsp, __Vfunc_get_error_count__11__Vfuncout);
    VL_NULL_CHECK(__VDynScope_run_test_0, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 141)->__PVT__local_error_count 
        = __Vfunc_get_error_count__11__Vfuncout;
    std::string fileName;
    IData/*31:0*/ lineNumber;
    lineNumber = 0;
    __Vtemp_1 = VL_SFORMATF_N_NX("%@::RUNNING",0,-1,
                                 &(_testName)) ;
    VL_WRITEF_NX("INFO:  [%0t][%0@]: %@\n",0,64,VL_TIME_UNITED_Q(1),
                 -12,-1,&(Vtestrunner_svunit_pkg__03a__03asvunit_base::__PVT__name),
                 -1,&(__Vtemp_1));
    vlSymsp->TOP__svunit_pkg.__PVT__current_tc = VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_testcase>{this};
    this->__VnoInFunc_add_junit_test_case(vlSymsp, _testName);
    this->__VnoInFunc_start(vlSymsp);
    co_await VL_NULL_CHECK(test, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 149)->__VnoInFunc_unit_test_setup(vlSymsp);
    VlForkSync __Vfork_1__sync;
    __Vfork_1__sync.init(1U, nullptr);
    this->__VnoInFunc_run_test____Vfork_1__0(vlSymsp, test, __VDynScope_run_test_0, __Vfork_1__sync);
    co_await __Vfork_1__sync.join(nullptr, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 
                                  150);
    this->__VnoInFunc_stop(vlSymsp);
    VL_NULL_CHECK(test, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 167)->__VnoInFunc_unit_test_teardown(vlSymsp);
    if ((([&]() {
                    this->__VnoInFunc_get_error_count(vlSymsp, __Vfunc_get_error_count__22__Vfuncout);
                }(), __Vfunc_get_error_count__22__Vfuncout) 
         == VL_NULL_CHECK(__VDynScope_run_test_0, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 168)
         ->__PVT__local_error_count)) {
        __Vtemp_2 = VL_SFORMATF_N_NX("%@::PASSED",0,
                                     -1,&(_testName)) ;
        VL_WRITEF_NX("INFO:  [%0t][%0@]: %@\n",0,64,
                     VL_TIME_UNITED_Q(1),-12,-1,&(Vtestrunner_svunit_pkg__03a__03asvunit_base::__PVT__name),
                     -1,&(__Vtemp_2));
    } else {
        __Vtemp_3 = VL_SFORMATF_N_NX("%@::FAILED",0,
                                     -1,&(_testName)) ;
        VL_WRITEF_NX("INFO:  [%0t][%0@]: %@\n",0,64,
                     VL_TIME_UNITED_Q(1),-12,-1,&(Vtestrunner_svunit_pkg__03a__03asvunit_base::__PVT__name),
                     -1,&(__Vtemp_3));
    }
    this->__VnoInFunc_update_exit_status(vlSymsp);
    co_return;
}
