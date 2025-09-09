// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner__Syms.h"
#include "Vtestrunner_junit_xml__03a__03aTestSuite__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testsuite__Vclpkg.h"

void Vtestrunner_svunit_pkg__03a__03asvunit_testsuite::__VnoInFunc_as_junit_test_suite(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_junit_xml__03a__03aTestSuite> &as_junit_test_suite__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testsuite::__VnoInFunc_as_junit_test_suite\n"); );
    // Init
    std::string __Vfunc_get_name__2__Vfuncout;
    VlQueue<VlClassRef<Vtestrunner_junit_xml__03a__03aTestCase>> __Vtask_as_junit_test_cases__3__Vfuncout;
    // Body
    IData/*31:0*/ unnamedblk2__DOT__i;
    unnamedblk2__DOT__i = 0;
    VlQueue<VlClassRef<Vtestrunner_junit_xml__03a__03aTestCase>> unnamedblk2__DOT__unnamedblk3__DOT__junit_test_cases;
    IData/*31:0*/ unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i;
    unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i = 0;
    VlClassRef<Vtestrunner_junit_xml__03a__03aTestSuite> result;
    result = VL_NEW(Vtestrunner_junit_xml__03a__03aTestSuite, vlSymsp, 
                    VL_CVT_PACK_STR_NN(([&]() {
                    this->__VnoInFunc_get_name(vlSymsp, __Vfunc_get_name__2__Vfuncout);
                }(), __Vfunc_get_name__2__Vfuncout)));
    unnamedblk2__DOT__i = 0U;
    while (VL_LTS_III(32, unnamedblk2__DOT__i, this->__PVT__list_of_testcases.size())) {
        VL_NULL_CHECK(this->__PVT__list_of_testcases.at(unnamedblk2__DOT__i), "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testsuite.sv", 54)->__VnoInFunc_as_junit_test_cases(vlSymsp, __Vtask_as_junit_test_cases__3__Vfuncout);
        unnamedblk2__DOT__unnamedblk3__DOT__junit_test_cases 
            = __Vtask_as_junit_test_cases__3__Vfuncout;
        unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i = 0U;
        while (VL_LTS_III(32, unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i, unnamedblk2__DOT__unnamedblk3__DOT__junit_test_cases.size())) {
            VL_NULL_CHECK(result, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testsuite.sv", 56)->__VnoInFunc_add_test_case(vlSymsp, unnamedblk2__DOT__unnamedblk3__DOT__junit_test_cases.at(unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i));
            unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i 
                = ((IData)(1U) + unnamedblk2__DOT__unnamedblk3__DOT__unnamedblk4__DOT__i);
        }
        unnamedblk2__DOT__i = ((IData)(1U) + unnamedblk2__DOT__i);
    }
    as_junit_test_suite__Vfuncrtn = result;
}
