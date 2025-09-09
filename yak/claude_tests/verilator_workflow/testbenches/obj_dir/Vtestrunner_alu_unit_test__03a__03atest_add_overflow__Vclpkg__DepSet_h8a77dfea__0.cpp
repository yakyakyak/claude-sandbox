// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner__Syms.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_add_overflow__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"

VL_INLINE_OPT VlCoroutine Vtestrunner_alu_unit_test__03a__03atest_add_overflow::__VnoInFunc_run____Vfork_1__0(Vtestrunner__Syms* __restrict vlSymsp, VlForkSync __Vfork_1__sync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtestrunner_alu_unit_test__03a__03atest_add_overflow::__VnoInFunc_run____Vfork_1__0\n"); );
    // Init
    VL_KEEP_THIS;
    CData/*0:0*/ __Vtask_fail__2__Vfuncout;
    __Vtask_fail__2__Vfuncout = 0;
    CData/*0:0*/ __Vtask_is_running__3__Vfuncout;
    __Vtask_is_running__3__Vfuncout = 0;
    CData/*0:0*/ __Vtask_fail__5__Vfuncout;
    __Vtask_fail__5__Vfuncout = 0;
    CData/*0:0*/ __Vtask_is_running__6__Vfuncout;
    __Vtask_is_running__6__Vfuncout = 0;
    CData/*0:0*/ __Vtask_fail__8__Vfuncout;
    __Vtask_fail__8__Vfuncout = 0;
    CData/*0:0*/ __Vtask_is_running__9__Vfuncout;
    __Vtask_is_running__9__Vfuncout = 0;
    CData/*0:0*/ __Vtask_fail__11__Vfuncout;
    __Vtask_fail__11__Vfuncout = 0;
    CData/*0:0*/ __Vtask_is_running__12__Vfuncout;
    __Vtask_is_running__12__Vfuncout = 0;
    // Body
    vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__a = 0x7fffffffU;
    vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__b = 1U;
    vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__op = 0U;
    co_await vlSymsp->TOP.__VdlySched.delay(1ULL, nullptr, 
                                            "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 
                                            123);
    if (([&]() {
                VL_NULL_CHECK(vlSymsp->TOP__svunit_pkg.__PVT__current_tc, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 124)
         ->__VnoInFunc_fail(vlSymsp, std::string{"fail_unless_equal"}, 
                            (0x80000000U != vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__result), 
                            std::string{"(result) !== (32'h80000000)"}, 
                            std::string{"/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv"}, 0x7cU, 
                            std::string{}, __Vtask_fail__2__Vfuncout);
            }(), (IData)(__Vtask_fail__2__Vfuncout))) {
        if (([&]() {
                    VL_NULL_CHECK(vlSymsp->TOP__svunit_pkg.__PVT__current_tc, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 124)
             ->__VnoInFunc_is_running(vlSymsp, __Vtask_is_running__3__Vfuncout);
                }(), (IData)(__Vtask_is_running__3__Vfuncout))) {
            co_await VL_NULL_CHECK(vlSymsp->TOP__svunit_pkg.__PVT__current_tc, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 124)->__VnoInFunc_give_up(vlSymsp);
        }
    }
    if (([&]() {
                VL_NULL_CHECK(vlSymsp->TOP__svunit_pkg.__PVT__current_tc, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 125)
         ->__VnoInFunc_fail(vlSymsp, std::string{"fail_unless_equal"}, 
                            (0U == vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__result), 
                            std::string{"(zero) !== (1'b0)"}, 
                            std::string{"/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv"}, 0x7dU, 
                            std::string{}, __Vtask_fail__5__Vfuncout);
            }(), (IData)(__Vtask_fail__5__Vfuncout))) {
        if (([&]() {
                    VL_NULL_CHECK(vlSymsp->TOP__svunit_pkg.__PVT__current_tc, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 125)
             ->__VnoInFunc_is_running(vlSymsp, __Vtask_is_running__6__Vfuncout);
                }(), (IData)(__Vtask_is_running__6__Vfuncout))) {
            co_await VL_NULL_CHECK(vlSymsp->TOP__svunit_pkg.__PVT__current_tc, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 125)->__VnoInFunc_give_up(vlSymsp);
        }
    }
    if (([&]() {
                VL_NULL_CHECK(vlSymsp->TOP__svunit_pkg.__PVT__current_tc, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 126)
         ->__VnoInFunc_fail(vlSymsp, std::string{"fail_unless_equal"}, 
                            (1U & (~ (IData)(vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__overflow))), 
                            std::string{"(overflow) !== (1'b1)"}, 
                            std::string{"/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv"}, 0x7eU, 
                            std::string{}, __Vtask_fail__8__Vfuncout);
            }(), (IData)(__Vtask_fail__8__Vfuncout))) {
        if (([&]() {
                    VL_NULL_CHECK(vlSymsp->TOP__svunit_pkg.__PVT__current_tc, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 126)
             ->__VnoInFunc_is_running(vlSymsp, __Vtask_is_running__9__Vfuncout);
                }(), (IData)(__Vtask_is_running__9__Vfuncout))) {
            co_await VL_NULL_CHECK(vlSymsp->TOP__svunit_pkg.__PVT__current_tc, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 126)->__VnoInFunc_give_up(vlSymsp);
        }
    }
    if (([&]() {
                VL_NULL_CHECK(vlSymsp->TOP__svunit_pkg.__PVT__current_tc, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 127)
         ->__VnoInFunc_fail(vlSymsp, std::string{"fail_unless_equal"}, (IData)(vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__carry_out), 
                            std::string{"(carry_out) !== (1'b0)"}, 
                            std::string{"/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv"}, 0x7fU, 
                            std::string{}, __Vtask_fail__11__Vfuncout);
            }(), (IData)(__Vtask_fail__11__Vfuncout))) {
        if (([&]() {
                    VL_NULL_CHECK(vlSymsp->TOP__svunit_pkg.__PVT__current_tc, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 127)
             ->__VnoInFunc_is_running(vlSymsp, __Vtask_is_running__12__Vfuncout);
                }(), (IData)(__Vtask_is_running__12__Vfuncout))) {
            co_await VL_NULL_CHECK(vlSymsp->TOP__svunit_pkg.__PVT__current_tc, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 127)->__VnoInFunc_give_up(vlSymsp);
        }
    }
    __Vfork_1__sync.done("/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 
                         119);
}

VlCoroutine Vtestrunner_alu_unit_test__03a__03atest_add_overflow::__VnoInFunc_unit_test_setup(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtestrunner_alu_unit_test__03a__03atest_add_overflow::__VnoInFunc_unit_test_setup\n"); );
    // Init
    VL_KEEP_THIS;
    // Body
    VL_NULL_CHECK(vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.svunit_ut, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 68)->__VnoInFunc_setup(vlSymsp);
    vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__a = 0U;
    vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__b = 0U;
    vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__op = 0U;
    co_await vlSymsp->TOP.__VdlySched.delay(1ULL, nullptr, 
                                            "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 
                                            73);
    VL_WRITEF_NX("DEBUG SETUP: a=%x, b=%x, op=%x, result=%x\n",0,
                 32,vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__a,
                 32,vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__b,
                 4,(IData)(vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__op),
                 32,vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__PVT__result);
}

void Vtestrunner_alu_unit_test__03a__03atest_add_overflow::__VnoInFunc_unit_test_teardown(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtestrunner_alu_unit_test__03a__03atest_add_overflow::__VnoInFunc_unit_test_teardown\n"); );
    // Body
    VL_NULL_CHECK(vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut.svunit_ut, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/./alu_unit_test.sv", 85)->__VnoInFunc_teardown(vlSymsp);
}
