// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"

void Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_list_tests(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_list_tests\n"); );
    // Init
    std::string __Vtask_get_name__4__Vfuncout;
    std::string __Vtemp_1;
    // Body
    IData/*31:0*/ unnamedblk1__DOT__i;
    unnamedblk1__DOT__i = 0;
    VL_WRITEF_NX("%@\n",0,-1,&(Vtestrunner_svunit_pkg__03a__03asvunit_base::__PVT__name));
    unnamedblk1__DOT__i = 0U;
    while (VL_LTS_III(32, unnamedblk1__DOT__i, this->__PVT__tests.size())) {
        __Vtemp_1 = VL_CONCATN_NNN(std::string{"    "}, 
                                   ([&]() {
                    VL_NULL_CHECK(this->__PVT__tests.at(unnamedblk1__DOT__i), "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 113)
                                    ->__VnoInFunc_get_name(vlSymsp, __Vtask_get_name__4__Vfuncout);
                }(), __Vtask_get_name__4__Vfuncout));
        VL_WRITEF_NX("%@\n",0,-1,&(__Vtemp_1));
        unnamedblk1__DOT__i = ((IData)(1U) + unnamedblk1__DOT__i);
    }
}
