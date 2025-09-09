// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtestrunner.h for the primary calling header

#ifndef VERILATED_VTESTRUNNER_SVUNIT_PKG__03A__03ASVUNIT_TESTCASE__VCLPKG_H_
#define VERILATED_VTESTRUNNER_SVUNIT_PKG__03A__03ASVUNIT_TESTCASE__VCLPKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtestrunner_junit_xml__03a__03aTestCase;
class Vtestrunner_svunit_pkg__03a__03a__VDynScope_12;
class Vtestrunner_svunit_pkg__03a__03afilter;
class Vtestrunner_svunit_pkg__03a__03asvunit_base;
class Vtestrunner_svunit_pkg__03a__03asvunit_test;
class Vtestrunner_svunit_pkg__03a__03asvunit_testcase;


class Vtestrunner__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtestrunner__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg(Vtestrunner__Syms* symsp, const char* v__name);
    ~Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg();
    VL_UNCOPYABLE(Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

#include "Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg.h"

class Vtestrunner__Syms;

class Vtestrunner_svunit_pkg__03a__03asvunit_testcase : public Vtestrunner_svunit_pkg__03a__03asvunit_base {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __PVT__running;
    CData/*0:0*/ __PVT__actually_ran_tests;
    IData/*31:0*/ __PVT__test_count;
    IData/*31:0*/ __PVT__error_count;
    VlQueue<VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test>> __PVT__tests;
    VlClassRef<Vtestrunner_junit_xml__03a__03aTestCase> __PVT__current_junit_test_case;
    VlQueue<VlClassRef<Vtestrunner_junit_xml__03a__03aTestCase>> __PVT__junit_test_cases;
    VlCoroutine __VnoInFunc____05Fwait_until_started(Vtestrunner__Syms* __restrict vlSymsp);
    void __VnoInFunc_add_junit_test_case(Vtestrunner__Syms* __restrict vlSymsp, std::string name);
    void __VnoInFunc_add_test(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test> test);
    void __VnoInFunc_as_junit_test_cases(Vtestrunner__Syms* __restrict vlSymsp, VlQueue<VlClassRef<Vtestrunner_junit_xml__03a__03aTestCase>> &as_junit_test_cases__Vfuncrtn);
    void __VnoInFunc_fail(Vtestrunner__Syms* __restrict vlSymsp, std::string c, CData/*0:0*/ b, std::string s, std::string f, IData/*31:0*/ l, std::string d, CData/*0:0*/ &fail__Vfuncrtn);
    void __VnoInFunc_get_error_count(Vtestrunner__Syms* __restrict vlSymsp, IData/*31:0*/ &get_error_count__Vfuncrtn);
    void __VnoInFunc_get_selected_tests(Vtestrunner__Syms* __restrict vlSymsp, VlQueue<VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test>> &get_selected_tests__Vfuncrtn);
    void __VnoInFunc_get_tests(Vtestrunner__Syms* __restrict vlSymsp, VlQueue<VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test>> &get_tests__Vfuncrtn);
    VlCoroutine __VnoInFunc_give_up(Vtestrunner__Syms* __restrict vlSymsp);
    void __VnoInFunc_is_running(Vtestrunner__Syms* __restrict vlSymsp, CData/*0:0*/ &is_running__Vfuncrtn);
    void __VnoInFunc_list_tests(Vtestrunner__Syms* __restrict vlSymsp);
    void __VnoInFunc_report(Vtestrunner__Syms* __restrict vlSymsp);
    VlCoroutine __VnoInFunc_run(Vtestrunner__Syms* __restrict vlSymsp);
    VlCoroutine __VnoInFunc_run_test(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test> test);
  private:
    VlCoroutine __VnoInFunc_run_test____Vfork_1__0(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test> &test, VlClassRef<Vtestrunner_svunit_pkg__03a__03a__VDynScope_12> &__VDynScope_run_test_0, VlForkSync __Vfork_1__sync);
    VlCoroutine __VnoInFunc_run_test____Vfork_1__0____Vfork_2__0(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test> test, VlForkSync __Vfork_2__sync);
    VlCoroutine __VnoInFunc_run_test____Vfork_1__0____Vfork_2__1(Vtestrunner__Syms* __restrict vlSymsp, VlClassRef<Vtestrunner_svunit_pkg__03a__03a__VDynScope_12> __VDynScope_run_test_0, VlForkSync __Vfork_2__sync);
  public:
    VlCoroutine __VnoInFunc_run_tests(Vtestrunner__Syms* __restrict vlSymsp);
    virtual void __VnoInFunc_setup(Vtestrunner__Syms* __restrict vlSymsp) {}
    void __VnoInFunc_start(Vtestrunner__Syms* __restrict vlSymsp);
    void __VnoInFunc_stop(Vtestrunner__Syms* __restrict vlSymsp);
    virtual void __VnoInFunc_teardown(Vtestrunner__Syms* __restrict vlSymsp) {}
    void __VnoInFunc_update_exit_status(Vtestrunner__Syms* __restrict vlSymsp);
    VlCoroutine __VnoInFunc_wait_for_error(Vtestrunner__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset(Vtestrunner__Syms* __restrict vlSymsp);
  public:
    Vtestrunner_svunit_pkg__03a__03asvunit_testcase(Vtestrunner__Syms* __restrict vlSymsp, std::string name);
    std::string to_string() const;
    std::string to_string_middle() const;
    virtual ~Vtestrunner_svunit_pkg__03a__03asvunit_testcase() {}
};

std::string VL_TO_STRING(const VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_testcase>& obj);

#endif  // guard
