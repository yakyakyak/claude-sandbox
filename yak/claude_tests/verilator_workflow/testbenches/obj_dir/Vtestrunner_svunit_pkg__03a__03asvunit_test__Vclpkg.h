// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtestrunner.h for the primary calling header

#ifndef VERILATED_VTESTRUNNER_SVUNIT_PKG__03A__03ASVUNIT_TEST__VCLPKG_H_
#define VERILATED_VTESTRUNNER_SVUNIT_PKG__03A__03ASVUNIT_TEST__VCLPKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtestrunner_svunit_pkg__03a__03asvunit_base;


class Vtestrunner__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtestrunner__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg(Vtestrunner__Syms* symsp, const char* v__name);
    ~Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg();
    VL_UNCOPYABLE(Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

#include "Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg.h"

class Vtestrunner__Syms;

class Vtestrunner_svunit_pkg__03a__03asvunit_test : public Vtestrunner_svunit_pkg__03a__03asvunit_base {
  public:
    virtual VlCoroutine __VnoInFunc_run(Vtestrunner__Syms* __restrict vlSymsp);
    virtual VlCoroutine __VnoInFunc_unit_test_setup(Vtestrunner__Syms* __restrict vlSymsp);
    virtual void __VnoInFunc_unit_test_teardown(Vtestrunner__Syms* __restrict vlSymsp) {}
  private:
    void _ctor_var_reset(Vtestrunner__Syms* __restrict vlSymsp);
  public:
    Vtestrunner_svunit_pkg__03a__03asvunit_test(Vtestrunner__Syms* __restrict vlSymsp, std::string name);
    std::string to_string() const;
    std::string to_string_middle() const;
    virtual ~Vtestrunner_svunit_pkg__03a__03asvunit_test() {}
};

std::string VL_TO_STRING(const VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test>& obj);

#endif  // guard
