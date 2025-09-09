// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_junit_xml__03a__03aTestCase__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"

void Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_fail(Vtestrunner__Syms* __restrict vlSymsp, std::string c, CData/*0:0*/ b, std::string s, std::string f, IData/*31:0*/ l, std::string d, CData/*0:0*/ &fail__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testcase::__VnoInFunc_fail\n"); );
    // Init
    std::string __Vtemp_2;
    // Body
    std::string _d;
    if (VL_UNLIKELY((b))) {
        this->__PVT__error_count = ((IData)(1U) + this->__PVT__error_count);
        if ((std::string{} != d)) {
            VL_SFORMAT_NX(64,_d,"[ %@ ] ",0,-1,&(d));
        }
        VL_NULL_CHECK(this->__PVT__current_junit_test_case, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/svunit_testcase.sv", 246)->__VnoInFunc_add_failure(vlSymsp, VL_SFORMATF_N_NX("%@: %@ %@(at %@ line:%0d)",0,
                                                                                -1,
                                                                                &(c),
                                                                                -1,
                                                                                &(s),
                                                                                -1,
                                                                                &(_d),
                                                                                -1,
                                                                                &(f),
                                                                                32,
                                                                                l) );
        __Vtemp_2 = VL_SFORMATF_N_NX("%@: %@ %@(at %@ line:%0d)",0,
                                     -1,&(c),-1,&(s),
                                     -1,&(_d),-1,&(f),
                                     32,l) ;
        VL_WRITEF_NX("ERROR: [%0t][%0@]: %@\n",0,64,
                     VL_TIME_UNITED_Q(1),-12,-1,&(Vtestrunner_svunit_pkg__03a__03asvunit_base::__PVT__name),
                     -1,&(__Vtemp_2));
        fail__Vfuncrtn = 1U;
    } else {
        fail__Vfuncrtn = 0U;
    }
}
