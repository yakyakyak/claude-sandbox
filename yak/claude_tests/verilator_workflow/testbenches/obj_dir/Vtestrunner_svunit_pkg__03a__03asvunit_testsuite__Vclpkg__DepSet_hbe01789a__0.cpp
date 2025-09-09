// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testsuite__Vclpkg.h"

void Vtestrunner_svunit_pkg__03a__03asvunit_testsuite::__VnoInFunc_run(Vtestrunner__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtestrunner_svunit_pkg__03a__03asvunit_testsuite::__VnoInFunc_run\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    {
        __Vtemp_1[0U] = 0x45535453U;
        __Vtemp_1[1U] = 0x53545f54U;
        __Vtemp_1[2U] = 0x545f4c49U;
        __Vtemp_1[3U] = 0x56554e49U;
        __Vtemp_1[4U] = 0x53U;
        if (VL_TESTPLUSARGS_I(VL_CVT_PACK_STR_NW(5, __Vtemp_1))) {
            goto __Vlabel2;
        }
        VL_WRITEF_NX("INFO:  [%0t][%0@]: RUNNING\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,-1,
                     &(Vtestrunner_svunit_pkg__03a__03asvunit_base::__PVT__name));
        __Vlabel2: ;
    }
}
