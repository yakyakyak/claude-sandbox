// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner__Syms.h"
#include "Vtestrunner___024root.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testrunner__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testsuite__Vclpkg.h"

VL_INLINE_OPT VlCoroutine Vtestrunner___024root___eval_initial__TOP__Vtiming__0(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_testrunner> testrunner__DOT__svunit_tr;
    VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_testsuite> testrunner__DOT_____05Fts__DOT__svunit_ts;
    IData/*31:0*/ __Vtask____05Fregister_tests__5__unnamedblk1__DOT__i;
    __Vtask____05Fregister_tests__5__unnamedblk1__DOT__i = 0;
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    testrunner__DOT__svunit_tr = VL_NEW(Vtestrunner_svunit_pkg__03a__03asvunit_testrunner, vlSymsp, 
                                        std::string{"testrunner"});
    vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.svunit_ut 
        = VL_NEW(Vtestrunner_svunit_pkg__03a__03asvunit_testcase, vlSymsp, 
                 std::string{"alu_ut"});
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x74657374U;
    __Vtemp_1[2U] = 0x616c755fU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSymsp->_traceDumpOpen();
    __Vtask____05Fregister_tests__5__unnamedblk1__DOT__i = 0;
    __Vtask____05Fregister_tests__5__unnamedblk1__DOT__i = 0U;
    while (VL_LTS_III(32, __Vtask____05Fregister_tests__5__unnamedblk1__DOT__i, vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.___05Ftests.size())) {
        VL_NULL_CHECK(vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.svunit_ut, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 230)->__VnoInFunc_add_test(vlSymsp, vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.___05Ftests.at(__Vtask____05Fregister_tests__5__unnamedblk1__DOT__i));
        __Vtask____05Fregister_tests__5__unnamedblk1__DOT__i 
            = ((IData)(1U) + __Vtask____05Fregister_tests__5__unnamedblk1__DOT__i);
    }
    testrunner__DOT_____05Fts__DOT__svunit_ts = VL_NEW(Vtestrunner_svunit_pkg__03a__03asvunit_testsuite, vlSymsp, 
                                                       std::string{"__ts"});
    VL_NULL_CHECK(testrunner__DOT_____05Fts__DOT__svunit_ts, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/.__testsuite.sv", 22)->__VnoInFunc_add_testcase(vlSymsp, vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.svunit_ut);
    VL_NULL_CHECK(testrunner__DOT__svunit_tr, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/.testrunner.sv", 48)->__VnoInFunc_add_testsuite(vlSymsp, testrunner__DOT_____05Fts__DOT__svunit_ts);
    VL_NULL_CHECK(testrunner__DOT_____05Fts__DOT__svunit_ts, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/.__testsuite.sv", 30)->__VnoInFunc_run(vlSymsp);
    co_await VL_NULL_CHECK(vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.svunit_ut, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 104)->__VnoInFunc_run(vlSymsp);
    VL_NULL_CHECK(testrunner__DOT_____05Fts__DOT__svunit_ts, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/.__testsuite.sv", 32)->__VnoInFunc_report(vlSymsp);
    VL_NULL_CHECK(testrunner__DOT__svunit_tr, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/.testrunner.sv", 57)->__VnoInFunc_report(vlSymsp);
    VL_FINISH_MT("/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/.testrunner.sv", 38, "");
}
