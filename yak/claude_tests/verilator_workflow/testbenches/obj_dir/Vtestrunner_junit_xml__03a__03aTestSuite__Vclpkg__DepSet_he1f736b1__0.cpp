// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner__Syms.h"
#include "Vtestrunner_junit_xml__03a__03aTestCase__Vclpkg.h"
#include "Vtestrunner_junit_xml__03a__03aTestSuite__Vclpkg.h"
#include "Vtestrunner_junit_xml__03a__03aXmlElement__Vclpkg.h"

void Vtestrunner_junit_xml__03a__03aTestSuite::__VnoInFunc_as_xml_element(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_junit_xml__03a__03aXmlElement> &as_xml_element__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtestrunner_junit_xml__03a__03aTestSuite::__VnoInFunc_as_xml_element\n"); );
    // Init
    VlClassRef<Vtestrunner_junit_xml__03a__03aXmlElement> __Vtask_as_xml_element__3__Vfuncout;
    // Body
    IData/*31:0*/ unnamedblk1__DOT__i;
    unnamedblk1__DOT__i = 0;
    VlClassRef<Vtestrunner_junit_xml__03a__03aXmlElement> result;
    result = VL_NEW(Vtestrunner_junit_xml__03a__03aXmlElement, vlSymsp, 
                    std::string{"testsuite"});
    VL_NULL_CHECK(result, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/junit-xml/TestSuite.svh", 48)->__VnoInFunc_set_attribute(vlSymsp, 
                                                                                std::string{"name"}, this->__PVT__name);
    unnamedblk1__DOT__i = 0U;
    while (VL_LTS_III(32, unnamedblk1__DOT__i, this->__PVT__test_cases.size())) {
        VL_NULL_CHECK(result, "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/junit-xml/TestSuite.svh", 50)->__VnoInFunc_add_child(vlSymsp, 
                                                                                ([&]() {
                    VL_NULL_CHECK(this->__PVT__test_cases.at(unnamedblk1__DOT__i), "/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/../svunit/svunit_base/junit-xml/TestSuite.svh", 50)
                                                                                ->__VnoInFunc_as_xml_element(vlSymsp, __Vtask_as_xml_element__3__Vfuncout);
                }(), __Vtask_as_xml_element__3__Vfuncout));
        unnamedblk1__DOT__i = ((IData)(1U) + unnamedblk1__DOT__i);
    }
    as_xml_element__Vfuncrtn = result;
}
