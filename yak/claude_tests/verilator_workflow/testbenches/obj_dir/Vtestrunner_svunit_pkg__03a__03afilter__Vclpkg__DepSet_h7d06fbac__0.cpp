// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_svunit_pkg__03a__03afilter__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg.h"

void Vtestrunner_svunit_pkg__03a__03afilter::__VnoInFunc_is_selected(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_testcase> tc, std::string test_name, CData/*0:0*/ &is_selected__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03afilter::__VnoInFunc_is_selected\n"); );
    // Init
    CData/*0:0*/ __Vtask_is_selected__9__Vfuncout;
    __Vtask_is_selected__9__Vfuncout = 0;
    CData/*0:0*/ __Vtask_is_selected__10__Vfuncout;
    __Vtask_is_selected__10__Vfuncout = 0;
    // Body
    IData/*31:0*/ unnamedblk3__DOT__i;
    unnamedblk3__DOT__i = 0;
    IData/*31:0*/ unnamedblk4__DOT__i;
    unnamedblk4__DOT__i = 0;
    {
        unnamedblk3__DOT__i = 0U;
        while (VL_LTS_III(32, unnamedblk3__DOT__i, this->__PVT__negative_subfilters.size())) {
            if (([&]() {
                        VL_NULL_CHECK(this->__PVT__negative_subfilters.at(unnamedblk3__DOT__i), "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_filter.svh", 105)
                 ->__VnoInFunc_is_selected(vlSymsp, tc, test_name, __Vtask_is_selected__9__Vfuncout);
                    }(), (IData)(__Vtask_is_selected__9__Vfuncout))) {
                is_selected__Vfuncrtn = 0U;
                goto __Vlabel3;
            }
            unnamedblk3__DOT__i = ((IData)(1U) + unnamedblk3__DOT__i);
        }
        unnamedblk4__DOT__i = 0U;
        while (VL_LTS_III(32, unnamedblk4__DOT__i, this->__PVT__positive_subfilters.size())) {
            if (([&]() {
                        VL_NULL_CHECK(this->__PVT__positive_subfilters.at(unnamedblk4__DOT__i), "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_filter.svh", 109)
                 ->__VnoInFunc_is_selected(vlSymsp, tc, test_name, __Vtask_is_selected__10__Vfuncout);
                    }(), (IData)(__Vtask_is_selected__10__Vfuncout))) {
                is_selected__Vfuncrtn = 1U;
                goto __Vlabel3;
            }
            unnamedblk4__DOT__i = ((IData)(1U) + unnamedblk4__DOT__i);
        }
        is_selected__Vfuncrtn = 0U;
        __Vlabel3: ;
    }
}
