// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtestrunner.h for the primary calling header

#ifndef VERILATED_VTESTRUNNER___024ROOT_H_
#define VERILATED_VTESTRUNNER___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtestrunner_alu_unit_test;
class Vtestrunner_alu_unit_test__03a__03atest_add_basic__Vclpkg;
class Vtestrunner_alu_unit_test__03a__03atest_add_carry__Vclpkg;
class Vtestrunner_alu_unit_test__03a__03atest_add_overflow__Vclpkg;
class Vtestrunner_alu_unit_test__03a__03atest_and__Vclpkg;
class Vtestrunner_alu_unit_test__03a__03atest_or__Vclpkg;
class Vtestrunner_alu_unit_test__03a__03atest_sll__Vclpkg;
class Vtestrunner_alu_unit_test__03a__03atest_slt_false__Vclpkg;
class Vtestrunner_alu_unit_test__03a__03atest_slt_true__Vclpkg;
class Vtestrunner_alu_unit_test__03a__03atest_srl__Vclpkg;
class Vtestrunner_alu_unit_test__03a__03atest_sub_basic__Vclpkg;
class Vtestrunner_alu_unit_test__03a__03atest_sub_zero__Vclpkg;
class Vtestrunner_alu_unit_test__03a__03atest_xor__Vclpkg;
class Vtestrunner_junit_xml;
class Vtestrunner_junit_xml__03a__03aTestCase__Vclpkg;
class Vtestrunner_junit_xml__03a__03aTestSuite__Vclpkg;
class Vtestrunner_junit_xml__03a__03aXmlElement__Vclpkg;
class Vtestrunner_svunit_pkg;
class Vtestrunner_svunit_pkg__03a__03a__VDynScope_12__Vclpkg;
class Vtestrunner_svunit_pkg__03a__03afilter__Vclpkg;
class Vtestrunner_svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg;
class Vtestrunner_svunit_pkg__03a__03astring_utils__Vclpkg;
class Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg;
class Vtestrunner_svunit_pkg__03a__03asvunit_test;
class Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg;
class Vtestrunner_svunit_pkg__03a__03asvunit_testcase;
class Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg;
class Vtestrunner_svunit_pkg__03a__03asvunit_testrunner;
class Vtestrunner_svunit_pkg__03a__03asvunit_testrunner__Vclpkg;
class Vtestrunner_svunit_pkg__03a__03asvunit_testsuite;
class Vtestrunner_svunit_pkg__03a__03asvunit_testsuite__Vclpkg;


class Vtestrunner__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtestrunner___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtestrunner_junit_xml* __PVT__junit_xml;
    Vtestrunner_svunit_pkg* __PVT__svunit_pkg;
    Vtestrunner_alu_unit_test* __PVT__testrunner__DOT_____05Fts__DOT__alu_ut;
    Vtestrunner_junit_xml__03a__03aXmlElement__Vclpkg* junit_xml__03a__03aXmlElement__Vclpkg;
    Vtestrunner_junit_xml__03a__03aTestCase__Vclpkg* junit_xml__03a__03aTestCase__Vclpkg;
    Vtestrunner_junit_xml__03a__03aTestSuite__Vclpkg* junit_xml__03a__03aTestSuite__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_add_basic__Vclpkg* alu_unit_test__03a__03atest_add_basic__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_add_overflow__Vclpkg* alu_unit_test__03a__03atest_add_overflow__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_add_carry__Vclpkg* alu_unit_test__03a__03atest_add_carry__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_sub_basic__Vclpkg* alu_unit_test__03a__03atest_sub_basic__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_sub_zero__Vclpkg* alu_unit_test__03a__03atest_sub_zero__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_and__Vclpkg* alu_unit_test__03a__03atest_and__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_or__Vclpkg* alu_unit_test__03a__03atest_or__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_xor__Vclpkg* alu_unit_test__03a__03atest_xor__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_sll__Vclpkg* alu_unit_test__03a__03atest_sll__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_srl__Vclpkg* alu_unit_test__03a__03atest_srl__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_slt_true__Vclpkg* alu_unit_test__03a__03atest_slt_true__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_slt_false__Vclpkg* alu_unit_test__03a__03atest_slt_false__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03astring_utils__Vclpkg* svunit_pkg__03a__03astring_utils__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg* svunit_pkg__03a__03asvunit_base__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg* svunit_pkg__03a__03asvunit_test__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg* svunit_pkg__03a__03asvunit_testcase__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_testsuite__Vclpkg* svunit_pkg__03a__03asvunit_testsuite__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_testrunner__Vclpkg* svunit_pkg__03a__03asvunit_testrunner__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg* svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03afilter__Vclpkg* svunit_pkg__03a__03afilter__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03a__VDynScope_12__Vclpkg* svunit_pkg__03a__03a__VDynScope_12__Vclpkg;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlDynamicTriggerScheduler __VdynSched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtestrunner__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtestrunner___024root(Vtestrunner__Syms* symsp, const char* v__name);
    ~Vtestrunner___024root();
    VL_UNCOPYABLE(Vtestrunner___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
