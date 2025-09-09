// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtestrunner.h for the primary calling header

#ifndef VERILATED_VTESTRUNNER_ALU_UNIT_TEST__03A__03ATEST_SUB_BASIC__VCLPKG_H_
#define VERILATED_VTESTRUNNER_ALU_UNIT_TEST__03A__03ATEST_SUB_BASIC__VCLPKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtestrunner_svunit_pkg__03a__03asvunit_test;
class Vtestrunner_svunit_pkg__03a__03asvunit_testcase;


class Vtestrunner__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtestrunner_alu_unit_test__03a__03atest_sub_basic__Vclpkg final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtestrunner__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtestrunner_alu_unit_test__03a__03atest_sub_basic__Vclpkg(Vtestrunner__Syms* symsp, const char* v__name);
    ~Vtestrunner_alu_unit_test__03a__03atest_sub_basic__Vclpkg();
    VL_UNCOPYABLE(Vtestrunner_alu_unit_test__03a__03atest_sub_basic__Vclpkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

#include "Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg.h"

class Vtestrunner__Syms;

class Vtestrunner_alu_unit_test__03a__03atest_sub_basic : public Vtestrunner_svunit_pkg__03a__03asvunit_test {
  public:
    virtual VlCoroutine __VnoInFunc_run(Vtestrunner__Syms* __restrict vlSymsp);
  private:
    VlCoroutine __VnoInFunc_run____Vfork_1__0(Vtestrunner__Syms* __restrict vlSymsp, VlForkSync __Vfork_1__sync);
  public:
    virtual VlCoroutine __VnoInFunc_unit_test_setup(Vtestrunner__Syms* __restrict vlSymsp);
    virtual void __VnoInFunc_unit_test_teardown(Vtestrunner__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset(Vtestrunner__Syms* __restrict vlSymsp);
  public:
    Vtestrunner_alu_unit_test__03a__03atest_sub_basic(Vtestrunner__Syms* __restrict vlSymsp);
    std::string to_string() const;
    std::string to_string_middle() const;
    virtual ~Vtestrunner_alu_unit_test__03a__03atest_sub_basic() {}
};

std::string VL_TO_STRING(const VlClassRef<Vtestrunner_alu_unit_test__03a__03atest_sub_basic>& obj);

#endif  // guard
