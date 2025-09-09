// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testrunner__Vclpkg.h"

void Vtestrunner_svunit_pkg__03a__03asvunit_testrunner::__VnoInFunc_report(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testrunner::__VnoInFunc_report\n"); );
    // Init
    IData/*31:0*/ __Vfunc_get_num_passing_testsuites__9__Vfuncout;
    __Vfunc_get_num_passing_testsuites__9__Vfuncout = 0;
    VlWide<5>/*159:0*/ __Vtemp_1;
    std::string __Vtemp_2;
    // Body
    IData/*31:0*/ pass_cnt;
    pass_cnt = 0;
    std::string success_str;
    {
        __Vtemp_1[0U] = 0x45535453U;
        __Vtemp_1[1U] = 0x53545f54U;
        __Vtemp_1[2U] = 0x545f4c49U;
        __Vtemp_1[3U] = 0x56554e49U;
        __Vtemp_1[4U] = 0x53U;
        if (VL_TESTPLUSARGS_I(VL_CVT_PACK_STR_NW(5, __Vtemp_1))) {
            goto __Vlabel1;
        }
        this->__VnoInFunc_get_num_passing_testsuites(vlSymsp, __Vfunc_get_num_passing_testsuites__9__Vfuncout);
        pass_cnt = __Vfunc_get_num_passing_testsuites__9__Vfuncout;
        if ((pass_cnt == this->__PVT__list_of_suites.size())) {
            success_str = std::string{"PASSED"};
            Vtestrunner_svunit_pkg__03a__03asvunit_base::__PVT__success = 1U;
        } else {
            success_str = std::string{"FAILED"};
            Vtestrunner_svunit_pkg__03a__03asvunit_base::__PVT__success = 0U;
        }
        VL_WRITEF_NX("\n",0);
        __Vtemp_2 = VL_SFORMATF_N_NX("%0@ (%0d of %0d suites passing) [SVUnit Unreleased]",0,
                                     -1,&(success_str),
                                     32,pass_cnt,32,
                                     this->__PVT__list_of_suites.size()) ;
        VL_WRITEF_NX("INFO:  [%0t][%0@]: %@\n",0,64,
                     VL_TIME_UNITED_Q(1),-12,-1,&(Vtestrunner_svunit_pkg__03a__03asvunit_base::__PVT__name),
                     -1,&(__Vtemp_2));
        this->__VnoInFunc_write_xml(vlSymsp);
        __Vlabel1: ;
    }
}
