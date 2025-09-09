// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner__Syms.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"

void Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_get_selected_tests(Vtestrunner__Syms* __restrict vlSymsp, VlQueue<VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test>> &get_selected_tests__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_get_selected_tests\n"); );
    // Init
    CData/*0:0*/ __Vtask_is_selected__7__Vfuncout;
    __Vtask_is_selected__7__Vfuncout = 0;
    std::string __Vtask_get_name__8__Vfuncout;
    // Body
    IData/*31:0*/ unnamedblk3__DOT__i;
    unnamedblk3__DOT__i = 0;
    VlQueue<VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test>> selected_tests;
    unnamedblk3__DOT__i = 0U;
    while (VL_LTS_III(32, unnamedblk3__DOT__i, this->__PVT__tests.size())) {
        if (([&]() {
                    VL_NULL_CHECK(vlSymsp->TOP__svunit_pkg.__PVT___filter, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 133)
             ->__VnoInFunc_is_selected(vlSymsp, VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_testcase>{this}, 
                                       VL_CVT_PACK_STR_NN(
                                                          ([&]() {
                                    VL_NULL_CHECK(this->__PVT__tests.at(unnamedblk3__DOT__i), "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 133)
                                                           ->__VnoInFunc_get_name(vlSymsp, __Vtask_get_name__8__Vfuncout);
                                }(), __Vtask_get_name__8__Vfuncout)), __Vtask_is_selected__7__Vfuncout);
                }(), (IData)(__Vtask_is_selected__7__Vfuncout))) {
            selected_tests.push_back(this->__PVT__tests.at(unnamedblk3__DOT__i));
        }
        unnamedblk3__DOT__i = ((IData)(1U) + unnamedblk3__DOT__i);
    }
    get_selected_tests__Vfuncrtn = selected_tests;
}
