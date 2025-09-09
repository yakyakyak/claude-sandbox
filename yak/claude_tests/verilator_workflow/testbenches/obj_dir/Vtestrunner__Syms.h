// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTESTRUNNER__SYMS_H_
#define VERILATED_VTESTRUNNER__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_vcd_c.h"

// INCLUDE MODEL CLASS

#include "Vtestrunner.h"

// INCLUDE MODULE CLASSES
#include "Vtestrunner___024root.h"
#include "Vtestrunner_junit_xml.h"
#include "Vtestrunner_alu_unit_test.h"
#include "Vtestrunner_svunit_pkg.h"
#include "Vtestrunner_junit_xml__03a__03aXmlElement__Vclpkg.h"
#include "Vtestrunner_junit_xml__03a__03aTestCase__Vclpkg.h"
#include "Vtestrunner_junit_xml__03a__03aTestSuite__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_add_basic__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_add_overflow__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_add_carry__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_sub_basic__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_sub_zero__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_and__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_or__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_xor__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_sll__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_srl__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_slt_true__Vclpkg.h"
#include "Vtestrunner_alu_unit_test__03a__03atest_slt_false__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03astring_utils__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testsuite__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03asvunit_testrunner__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03afilter__Vclpkg.h"
#include "Vtestrunner_svunit_pkg__03a__03a__VDynScope_12__Vclpkg.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtestrunner__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtestrunner* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedVcdC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtestrunner___024root          TOP;
    Vtestrunner_junit_xml          TOP__junit_xml;
    Vtestrunner_svunit_pkg         TOP__svunit_pkg;
    Vtestrunner_alu_unit_test      TOP__testrunner__DOT_____05Fts__DOT__alu_ut;
    Vtestrunner_alu_unit_test__03a__03atest_add_basic__Vclpkg TOP__alu_unit_test__03a__03atest_add_basic__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_add_carry__Vclpkg TOP__alu_unit_test__03a__03atest_add_carry__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_add_overflow__Vclpkg TOP__alu_unit_test__03a__03atest_add_overflow__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_and__Vclpkg TOP__alu_unit_test__03a__03atest_and__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_or__Vclpkg TOP__alu_unit_test__03a__03atest_or__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_sll__Vclpkg TOP__alu_unit_test__03a__03atest_sll__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_slt_false__Vclpkg TOP__alu_unit_test__03a__03atest_slt_false__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_slt_true__Vclpkg TOP__alu_unit_test__03a__03atest_slt_true__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_srl__Vclpkg TOP__alu_unit_test__03a__03atest_srl__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_sub_basic__Vclpkg TOP__alu_unit_test__03a__03atest_sub_basic__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_sub_zero__Vclpkg TOP__alu_unit_test__03a__03atest_sub_zero__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_xor__Vclpkg TOP__alu_unit_test__03a__03atest_xor__Vclpkg;
    Vtestrunner_junit_xml__03a__03aTestCase__Vclpkg TOP__junit_xml__03a__03aTestCase__Vclpkg;
    Vtestrunner_junit_xml__03a__03aTestSuite__Vclpkg TOP__junit_xml__03a__03aTestSuite__Vclpkg;
    Vtestrunner_junit_xml__03a__03aXmlElement__Vclpkg TOP__junit_xml__03a__03aXmlElement__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03a__VDynScope_12__Vclpkg TOP__svunit_pkg__03a__03a__VDynScope_12__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03afilter__Vclpkg TOP__svunit_pkg__03a__03afilter__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg TOP__svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03astring_utils__Vclpkg TOP__svunit_pkg__03a__03astring_utils__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg TOP__svunit_pkg__03a__03asvunit_base__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg TOP__svunit_pkg__03a__03asvunit_test__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg TOP__svunit_pkg__03a__03asvunit_testcase__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_testrunner__Vclpkg TOP__svunit_pkg__03a__03asvunit_testrunner__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_testsuite__Vclpkg TOP__svunit_pkg__03a__03asvunit_testsuite__Vclpkg;

    // CONSTRUCTORS
    Vtestrunner__Syms(VerilatedContext* contextp, const char* namep, Vtestrunner* modelp);
    ~Vtestrunner__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard
