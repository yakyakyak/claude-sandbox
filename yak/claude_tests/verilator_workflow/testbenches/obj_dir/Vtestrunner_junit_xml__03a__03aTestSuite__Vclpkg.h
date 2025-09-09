// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtestrunner.h for the primary calling header

#ifndef VERILATED_VTESTRUNNER_JUNIT_XML__03A__03ATESTSUITE__VCLPKG_H_
#define VERILATED_VTESTRUNNER_JUNIT_XML__03A__03ATESTSUITE__VCLPKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtestrunner_junit_xml__03a__03aTestCase;
class Vtestrunner_junit_xml__03a__03aXmlElement;


class Vtestrunner__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtestrunner_junit_xml__03a__03aTestSuite__Vclpkg final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtestrunner__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtestrunner_junit_xml__03a__03aTestSuite__Vclpkg(Vtestrunner__Syms* symsp, const char* v__name);
    ~Vtestrunner_junit_xml__03a__03aTestSuite__Vclpkg();
    VL_UNCOPYABLE(Vtestrunner_junit_xml__03a__03aTestSuite__Vclpkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


class Vtestrunner__Syms;

class Vtestrunner_junit_xml__03a__03aTestSuite : public VlClass {
  public:

    // DESIGN SPECIFIC STATE
    std::string __PVT__name;
    VlQueue<VlClassRef<Vtestrunner_junit_xml__03a__03aTestCase>> __PVT__test_cases;
    void __VnoInFunc_add_test_case(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_junit_xml__03a__03aTestCase> test_case);
    void __VnoInFunc_as_xml_element(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_junit_xml__03a__03aXmlElement> &as_xml_element__Vfuncrtn);
    void __VnoInFunc_get_name(Vtestrunner__Syms* __restrict vlSymsp, std::string &get_name__Vfuncrtn);
  private:
    void _ctor_var_reset(Vtestrunner__Syms* __restrict vlSymsp);
  public:
    Vtestrunner_junit_xml__03a__03aTestSuite(Vtestrunner__Syms* __restrict vlSymsp, std::string name);
    std::string to_string() const;
    std::string to_string_middle() const;
    ~Vtestrunner_junit_xml__03a__03aTestSuite() {}
};

std::string VL_TO_STRING(const VlClassRef<Vtestrunner_junit_xml__03a__03aTestSuite>& obj);

#endif  // guard
