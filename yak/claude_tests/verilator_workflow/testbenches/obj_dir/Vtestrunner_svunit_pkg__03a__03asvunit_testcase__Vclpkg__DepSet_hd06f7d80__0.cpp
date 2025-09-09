// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"

VlCoroutine Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_run_tests(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_run_tests\n"); );
    // Init
    VL_KEEP_THIS;
    VlQueue<VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test>> __Vfunc_get_selected_tests__5__Vfuncout;
    // Body
    IData/*31:0*/ unnamedblk2__DOT__i;
    unnamedblk2__DOT__i = 0;
    VlQueue<VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test>> selected_tests;
    {
        this->__VnoInFunc_get_selected_tests(vlSymsp, __Vfunc_get_selected_tests__5__Vfuncout);
        selected_tests = __Vfunc_get_selected_tests__5__Vfuncout;
        if ((0U == selected_tests.size())) {
            goto __Vlabel1;
        }
        VL_WRITEF_NX("INFO:  [%0t][%0@]: RUNNING\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,-1,
                     &(Vtestrunner_svunit_pkg__03a__03asvunit_base::__PVT__name));
        unnamedblk2__DOT__i = 0U;
        while (VL_LTS_III(32, unnamedblk2__DOT__i, selected_tests.size())) {
            co_await this->__VnoInFunc_run_test(vlSymsp, selected_tests.at(unnamedblk2__DOT__i));
            unnamedblk2__DOT__i = ((IData)(1U) + unnamedblk2__DOT__i);
        }
        this->__PVT__actually_ran_tests = 1U;
        __Vlabel1: ;
    }
}

void Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_update_exit_status(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_update_exit_status\n"); );
    // Body
    Vtestrunner_svunit_pkg__03a__03asvunit_base::__PVT__success 
        = (0U == this->__PVT__error_count);
}

void Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_report(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_report\n"); );
    // Init
    std::string __Vtemp_1;
    // Body
    std::string success_str;
    {
        success_str = VL_CVT_PACK_STR_NQ(((IData)(Vtestrunner_svunit_pkg__03a__03asvunit_base::__PVT__success)
                                           ? 0x504153534544ULL
                                           : 0x4641494c4544ULL));
        if ((1U & (~ (IData)(this->__PVT__actually_ran_tests)))) {
            goto __Vlabel2;
        }
        __Vtemp_1 = VL_SFORMATF_N_NX("%0@ (%0# of %0# tests passing)",0,
                                     -1,&(success_str),
                                     32,(this->__PVT__test_count 
                                         - this->__PVT__error_count),
                                     32,this->__PVT__test_count) ;
        VL_WRITEF_NX("INFO:  [%0t][%0@]: %@\n",0,64,
                     VL_TIME_UNITED_Q(1),-12,-1,&(Vtestrunner_svunit_pkg__03a__03asvunit_base::__PVT__name),
                     -1,&(__Vtemp_1));
        __Vlabel2: ;
    }
}
