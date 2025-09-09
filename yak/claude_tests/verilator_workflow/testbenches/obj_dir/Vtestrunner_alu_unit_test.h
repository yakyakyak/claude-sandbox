// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtestrunner.h for the primary calling header

#ifndef VERILATED_VTESTRUNNER_ALU_UNIT_TEST_H_
#define VERILATED_VTESTRUNNER_ALU_UNIT_TEST_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtestrunner_alu_unit_test__03a__03atest_add_basic;
class Vtestrunner_alu_unit_test__03a__03atest_add_carry;
class Vtestrunner_alu_unit_test__03a__03atest_add_overflow;
class Vtestrunner_alu_unit_test__03a__03atest_and;
class Vtestrunner_alu_unit_test__03a__03atest_or;
class Vtestrunner_alu_unit_test__03a__03atest_sll;
class Vtestrunner_alu_unit_test__03a__03atest_slt_false;
class Vtestrunner_alu_unit_test__03a__03atest_slt_true;
class Vtestrunner_alu_unit_test__03a__03atest_srl;
class Vtestrunner_alu_unit_test__03a__03atest_sub_basic;
class Vtestrunner_alu_unit_test__03a__03atest_sub_zero;
class Vtestrunner_alu_unit_test__03a__03atest_xor;
class Vtestrunner_svunit_pkg__03a__03asvunit_test;
class Vtestrunner_svunit_pkg__03a__03asvunit_testcase;


class Vtestrunner__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtestrunner_alu_unit_test final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*3:0*/ __PVT__op;
    CData/*0:0*/ __PVT__overflow;
    CData/*0:0*/ __PVT__carry_out;
    IData/*31:0*/ __PVT__a;
    IData/*31:0*/ __PVT__b;
    IData/*31:0*/ __PVT__result;
    VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_testcase> svunit_ut;
    VlQueue<VlClassRef<Vtestrunner_svunit_pkg__03a__03asvunit_test>> ___05Ftests;

    // INTERNAL VARIABLES
    Vtestrunner__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtestrunner_alu_unit_test(Vtestrunner__Syms* symsp, const char* v__name);
    ~Vtestrunner_alu_unit_test();
    VL_UNCOPYABLE(Vtestrunner_alu_unit_test);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
