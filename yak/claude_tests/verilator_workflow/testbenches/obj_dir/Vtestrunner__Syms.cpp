// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtestrunner__pch.h"
#include "Vtestrunner.h"
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

// FUNCTIONS
Vtestrunner__Syms::~Vtestrunner__Syms()
{
#ifdef VM_TRACE
    if (__Vm_dumping) _traceDumpClose();
#endif  // VM_TRACE
}

void Vtestrunner__Syms::_traceDump() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vtestrunner__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vtestrunner__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}

Vtestrunner__Syms::Vtestrunner__Syms(VerilatedContext* contextp, const char* namep, Vtestrunner* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__junit_xml{this, Verilated::catName(namep, "junit_xml")}
    , TOP__svunit_pkg{this, Verilated::catName(namep, "svunit_pkg")}
    , TOP__testrunner__DOT_____05Fts__DOT__alu_ut{this, Verilated::catName(namep, "testrunner.__ts.alu_ut")}
    , TOP__alu_unit_test__03a__03atest_add_basic__Vclpkg{this, Verilated::catName(namep, "alu_unit_test::test_add_basic__Vclpkg")}
    , TOP__alu_unit_test__03a__03atest_add_carry__Vclpkg{this, Verilated::catName(namep, "alu_unit_test::test_add_carry__Vclpkg")}
    , TOP__alu_unit_test__03a__03atest_add_overflow__Vclpkg{this, Verilated::catName(namep, "alu_unit_test::test_add_overflow__Vclpkg")}
    , TOP__alu_unit_test__03a__03atest_and__Vclpkg{this, Verilated::catName(namep, "alu_unit_test::test_and__Vclpkg")}
    , TOP__alu_unit_test__03a__03atest_or__Vclpkg{this, Verilated::catName(namep, "alu_unit_test::test_or__Vclpkg")}
    , TOP__alu_unit_test__03a__03atest_sll__Vclpkg{this, Verilated::catName(namep, "alu_unit_test::test_sll__Vclpkg")}
    , TOP__alu_unit_test__03a__03atest_slt_false__Vclpkg{this, Verilated::catName(namep, "alu_unit_test::test_slt_false__Vclpkg")}
    , TOP__alu_unit_test__03a__03atest_slt_true__Vclpkg{this, Verilated::catName(namep, "alu_unit_test::test_slt_true__Vclpkg")}
    , TOP__alu_unit_test__03a__03atest_srl__Vclpkg{this, Verilated::catName(namep, "alu_unit_test::test_srl__Vclpkg")}
    , TOP__alu_unit_test__03a__03atest_sub_basic__Vclpkg{this, Verilated::catName(namep, "alu_unit_test::test_sub_basic__Vclpkg")}
    , TOP__alu_unit_test__03a__03atest_sub_zero__Vclpkg{this, Verilated::catName(namep, "alu_unit_test::test_sub_zero__Vclpkg")}
    , TOP__alu_unit_test__03a__03atest_xor__Vclpkg{this, Verilated::catName(namep, "alu_unit_test::test_xor__Vclpkg")}
    , TOP__junit_xml__03a__03aTestCase__Vclpkg{this, Verilated::catName(namep, "junit_xml::TestCase__Vclpkg")}
    , TOP__junit_xml__03a__03aTestSuite__Vclpkg{this, Verilated::catName(namep, "junit_xml::TestSuite__Vclpkg")}
    , TOP__junit_xml__03a__03aXmlElement__Vclpkg{this, Verilated::catName(namep, "junit_xml::XmlElement__Vclpkg")}
    , TOP__svunit_pkg__03a__03a__VDynScope_12__Vclpkg{this, Verilated::catName(namep, "svunit_pkg::__VDynScope_12__Vclpkg")}
    , TOP__svunit_pkg__03a__03afilter__Vclpkg{this, Verilated::catName(namep, "svunit_pkg::filter__Vclpkg")}
    , TOP__svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg{this, Verilated::catName(namep, "svunit_pkg::filter_for_single_pattern__Vclpkg")}
    , TOP__svunit_pkg__03a__03astring_utils__Vclpkg{this, Verilated::catName(namep, "svunit_pkg::string_utils__Vclpkg")}
    , TOP__svunit_pkg__03a__03asvunit_base__Vclpkg{this, Verilated::catName(namep, "svunit_pkg::svunit_base__Vclpkg")}
    , TOP__svunit_pkg__03a__03asvunit_test__Vclpkg{this, Verilated::catName(namep, "svunit_pkg::svunit_test__Vclpkg")}
    , TOP__svunit_pkg__03a__03asvunit_testcase__Vclpkg{this, Verilated::catName(namep, "svunit_pkg::svunit_testcase__Vclpkg")}
    , TOP__svunit_pkg__03a__03asvunit_testrunner__Vclpkg{this, Verilated::catName(namep, "svunit_pkg::svunit_testrunner__Vclpkg")}
    , TOP__svunit_pkg__03a__03asvunit_testsuite__Vclpkg{this, Verilated::catName(namep, "svunit_pkg::svunit_testsuite__Vclpkg")}
{
        // Check resources
        Verilated::stackCheck(4043);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__junit_xml = &TOP__junit_xml;
    TOP.__PVT__svunit_pkg = &TOP__svunit_pkg;
    TOP.__PVT__testrunner__DOT_____05Fts__DOT__alu_ut = &TOP__testrunner__DOT_____05Fts__DOT__alu_ut;
    TOP.alu_unit_test__03a__03atest_add_basic__Vclpkg = &TOP__alu_unit_test__03a__03atest_add_basic__Vclpkg;
    TOP.alu_unit_test__03a__03atest_add_carry__Vclpkg = &TOP__alu_unit_test__03a__03atest_add_carry__Vclpkg;
    TOP.alu_unit_test__03a__03atest_add_overflow__Vclpkg = &TOP__alu_unit_test__03a__03atest_add_overflow__Vclpkg;
    TOP.alu_unit_test__03a__03atest_and__Vclpkg = &TOP__alu_unit_test__03a__03atest_and__Vclpkg;
    TOP.alu_unit_test__03a__03atest_or__Vclpkg = &TOP__alu_unit_test__03a__03atest_or__Vclpkg;
    TOP.alu_unit_test__03a__03atest_sll__Vclpkg = &TOP__alu_unit_test__03a__03atest_sll__Vclpkg;
    TOP.alu_unit_test__03a__03atest_slt_false__Vclpkg = &TOP__alu_unit_test__03a__03atest_slt_false__Vclpkg;
    TOP.alu_unit_test__03a__03atest_slt_true__Vclpkg = &TOP__alu_unit_test__03a__03atest_slt_true__Vclpkg;
    TOP.alu_unit_test__03a__03atest_srl__Vclpkg = &TOP__alu_unit_test__03a__03atest_srl__Vclpkg;
    TOP.alu_unit_test__03a__03atest_sub_basic__Vclpkg = &TOP__alu_unit_test__03a__03atest_sub_basic__Vclpkg;
    TOP.alu_unit_test__03a__03atest_sub_zero__Vclpkg = &TOP__alu_unit_test__03a__03atest_sub_zero__Vclpkg;
    TOP.alu_unit_test__03a__03atest_xor__Vclpkg = &TOP__alu_unit_test__03a__03atest_xor__Vclpkg;
    TOP.junit_xml__03a__03aTestCase__Vclpkg = &TOP__junit_xml__03a__03aTestCase__Vclpkg;
    TOP.junit_xml__03a__03aTestSuite__Vclpkg = &TOP__junit_xml__03a__03aTestSuite__Vclpkg;
    TOP.junit_xml__03a__03aXmlElement__Vclpkg = &TOP__junit_xml__03a__03aXmlElement__Vclpkg;
    TOP.svunit_pkg__03a__03a__VDynScope_12__Vclpkg = &TOP__svunit_pkg__03a__03a__VDynScope_12__Vclpkg;
    TOP.svunit_pkg__03a__03afilter__Vclpkg = &TOP__svunit_pkg__03a__03afilter__Vclpkg;
    TOP.svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg = &TOP__svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg;
    TOP.svunit_pkg__03a__03astring_utils__Vclpkg = &TOP__svunit_pkg__03a__03astring_utils__Vclpkg;
    TOP.svunit_pkg__03a__03asvunit_base__Vclpkg = &TOP__svunit_pkg__03a__03asvunit_base__Vclpkg;
    TOP.svunit_pkg__03a__03asvunit_test__Vclpkg = &TOP__svunit_pkg__03a__03asvunit_test__Vclpkg;
    TOP.svunit_pkg__03a__03asvunit_testcase__Vclpkg = &TOP__svunit_pkg__03a__03asvunit_testcase__Vclpkg;
    TOP.svunit_pkg__03a__03asvunit_testrunner__Vclpkg = &TOP__svunit_pkg__03a__03asvunit_testrunner__Vclpkg;
    TOP.svunit_pkg__03a__03asvunit_testsuite__Vclpkg = &TOP__svunit_pkg__03a__03asvunit_testsuite__Vclpkg;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__junit_xml.__Vconfigure(true);
    TOP__svunit_pkg.__Vconfigure(true);
    TOP__testrunner__DOT_____05Fts__DOT__alu_ut.__Vconfigure(true);
    TOP__alu_unit_test__03a__03atest_add_basic__Vclpkg.__Vconfigure(true);
    TOP__alu_unit_test__03a__03atest_add_carry__Vclpkg.__Vconfigure(true);
    TOP__alu_unit_test__03a__03atest_add_overflow__Vclpkg.__Vconfigure(true);
    TOP__alu_unit_test__03a__03atest_and__Vclpkg.__Vconfigure(true);
    TOP__alu_unit_test__03a__03atest_or__Vclpkg.__Vconfigure(true);
    TOP__alu_unit_test__03a__03atest_sll__Vclpkg.__Vconfigure(true);
    TOP__alu_unit_test__03a__03atest_slt_false__Vclpkg.__Vconfigure(true);
    TOP__alu_unit_test__03a__03atest_slt_true__Vclpkg.__Vconfigure(true);
    TOP__alu_unit_test__03a__03atest_srl__Vclpkg.__Vconfigure(true);
    TOP__alu_unit_test__03a__03atest_sub_basic__Vclpkg.__Vconfigure(true);
    TOP__alu_unit_test__03a__03atest_sub_zero__Vclpkg.__Vconfigure(true);
    TOP__alu_unit_test__03a__03atest_xor__Vclpkg.__Vconfigure(true);
    TOP__junit_xml__03a__03aTestCase__Vclpkg.__Vconfigure(true);
    TOP__junit_xml__03a__03aTestSuite__Vclpkg.__Vconfigure(true);
    TOP__junit_xml__03a__03aXmlElement__Vclpkg.__Vconfigure(true);
    TOP__svunit_pkg__03a__03a__VDynScope_12__Vclpkg.__Vconfigure(true);
    TOP__svunit_pkg__03a__03afilter__Vclpkg.__Vconfigure(true);
    TOP__svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg.__Vconfigure(true);
    TOP__svunit_pkg__03a__03astring_utils__Vclpkg.__Vconfigure(true);
    TOP__svunit_pkg__03a__03asvunit_base__Vclpkg.__Vconfigure(true);
    TOP__svunit_pkg__03a__03asvunit_test__Vclpkg.__Vconfigure(true);
    TOP__svunit_pkg__03a__03asvunit_testcase__Vclpkg.__Vconfigure(true);
    TOP__svunit_pkg__03a__03asvunit_testrunner__Vclpkg.__Vconfigure(true);
    TOP__svunit_pkg__03a__03asvunit_testsuite__Vclpkg.__Vconfigure(true);
}
