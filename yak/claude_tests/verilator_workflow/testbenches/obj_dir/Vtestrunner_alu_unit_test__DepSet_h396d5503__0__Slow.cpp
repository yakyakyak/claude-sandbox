// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner__Syms.h"
#include "Vtestrunner_alu_unit_test.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_add_basic__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_add_carry__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_add_overflow__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_and__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_or__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_sll__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_slt_false__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_slt_true__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_srl__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_sub_basic__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_sub_zero__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_xor__Vclpkg.h"

VL_ATTR_COLD void Vtestrunner_alu_unit_test___eval_static__TOP__testrunner__DOT_____05Fts__DOT__alu_ut(Vtestrunner_alu_unit_test* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtestrunner_alu_unit_test___eval_static__TOP__testrunner__DOT_____05Fts__DOT__alu_ut\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_add_basic> __Vfunc____05Fregister_test_add_basic__0__test;
    VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_add_overflow> __Vfunc____05Fregister_test_add_overflow__2__test;
    VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_add_carry> __Vfunc____05Fregister_test_add_carry__4__test;
    VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_sub_basic> __Vfunc____05Fregister_test_sub_basic__6__test;
    VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_sub_zero> __Vfunc____05Fregister_test_sub_zero__8__test;
    VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_and> __Vfunc____05Fregister_test_and__10__test;
    VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_or> __Vfunc____05Fregister_test_or__12__test;
    VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_xor> __Vfunc____05Fregister_test_xor__14__test;
    VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_sll> __Vfunc____05Fregister_test_sll__16__test;
    VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_srl> __Vfunc____05Fregister_test_srl__18__test;
    VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_slt_true> __Vfunc____05Fregister_test_slt_true__20__test;
    VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_slt_false> __Vfunc____05Fregister_test_slt_false__22__test;
    // Body
    __Vfunc____05Fregister_test_add_basic__0__test 
        = VL_NEW(Vtestrunner_alu_unit_test__03a__03atest_add_basic, vlSymsp);
    vlSelfRef.___05Ftests.push_back(__Vfunc____05Fregister_test_add_basic__0__test);
    __Vfunc____05Fregister_test_add_overflow__2__test 
        = VL_NEW(Vtestrunner_alu_unit_test__03a__03atest_add_overflow, vlSymsp);
    vlSelfRef.___05Ftests.push_back(__Vfunc____05Fregister_test_add_overflow__2__test);
    __Vfunc____05Fregister_test_add_carry__4__test 
        = VL_NEW(Vtestrunner_alu_unit_test__03a__03atest_add_carry, vlSymsp);
    vlSelfRef.___05Ftests.push_back(__Vfunc____05Fregister_test_add_carry__4__test);
    __Vfunc____05Fregister_test_sub_basic__6__test 
        = VL_NEW(Vtestrunner_alu_unit_test__03a__03atest_sub_basic, vlSymsp);
    vlSelfRef.___05Ftests.push_back(__Vfunc____05Fregister_test_sub_basic__6__test);
    __Vfunc____05Fregister_test_sub_zero__8__test = VL_NEW(Vtestrunner_alu_unit_test__03a__03atest_sub_zero, vlSymsp);
    vlSelfRef.___05Ftests.push_back(__Vfunc____05Fregister_test_sub_zero__8__test);
    __Vfunc____05Fregister_test_and__10__test = VL_NEW(Vtestrunner_alu_unit_test__03a__03atest_and, vlSymsp);
    vlSelfRef.___05Ftests.push_back(__Vfunc____05Fregister_test_and__10__test);
    __Vfunc____05Fregister_test_or__12__test = VL_NEW(Vtestrunner_alu_unit_test__03a__03atest_or, vlSymsp);
    vlSelfRef.___05Ftests.push_back(__Vfunc____05Fregister_test_or__12__test);
    __Vfunc____05Fregister_test_xor__14__test = VL_NEW(Vtestrunner_alu_unit_test__03a__03atest_xor, vlSymsp);
    vlSelfRef.___05Ftests.push_back(__Vfunc____05Fregister_test_xor__14__test);
    __Vfunc____05Fregister_test_sll__16__test = VL_NEW(Vtestrunner_alu_unit_test__03a__03atest_sll, vlSymsp);
    vlSelfRef.___05Ftests.push_back(__Vfunc____05Fregister_test_sll__16__test);
    __Vfunc____05Fregister_test_srl__18__test = VL_NEW(Vtestrunner_alu_unit_test__03a__03atest_srl, vlSymsp);
    vlSelfRef.___05Ftests.push_back(__Vfunc____05Fregister_test_srl__18__test);
    __Vfunc____05Fregister_test_slt_true__20__test 
        = VL_NEW(Vtestrunner_alu_unit_test__03a__03atest_slt_true, vlSymsp);
    vlSelfRef.___05Ftests.push_back(__Vfunc____05Fregister_test_slt_true__20__test);
    __Vfunc____05Fregister_test_slt_false__22__test 
        = VL_NEW(Vtestrunner_alu_unit_test__03a__03atest_slt_false, vlSymsp);
    vlSelfRef.___05Ftests.push_back(__Vfunc____05Fregister_test_slt_false__22__test);
}
