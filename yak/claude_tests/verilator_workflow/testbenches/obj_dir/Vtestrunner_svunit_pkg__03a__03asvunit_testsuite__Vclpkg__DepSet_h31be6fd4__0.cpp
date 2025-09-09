// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testsuite__Vclpkg.h"

void Vtestrunner_svunit_pkg__03a__03asvunit_testsuite::__VnoInFunc_get_num_passing_testcases(Vtestrunner__Syms* __restrict vlSymsp, IData/*31:0*/ &get_num_passing_testcases__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testsuite::__VnoInFunc_get_num_passing_testcases\n"); );
    // Init
    CData/*0:0*/ __Vtask_get_results__0__Vfuncout;
    __Vtask_get_results__0__Vfuncout = 0;
    // Body
    IData/*31:0*/ unnamedblk1__DOT__i;
    unnamedblk1__DOT__i = 0;
    IData/*31:0*/ result;
    result = 0;
    unnamedblk1__DOT__i = 0U;
    while (VL_LTS_III(32, unnamedblk1__DOT__i, this->__PVT__list_of_testcases.size())) {
        if (([&]() {
                    VL_NULL_CHECK(this->__PVT__list_of_testcases.at(unnamedblk1__DOT__i), "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testsuite.sv", 45)
             ->__VnoInFunc_get_results(vlSymsp, __Vtask_get_results__0__Vfuncout);
                }(), (IData)(__Vtask_get_results__0__Vfuncout))) {
            result = ((IData)(1U) + result);
        }
        unnamedblk1__DOT__i = ((IData)(1U) + unnamedblk1__DOT__i);
    }
    get_num_passing_testcases__Vfuncrtn = result;
}
