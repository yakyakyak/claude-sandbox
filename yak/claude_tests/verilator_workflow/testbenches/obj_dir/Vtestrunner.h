// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTESTRUNNER_H_
#define VERILATED_VTESTRUNNER_H_  // guard

#include "verilated.h"

class Vtestrunner__Syms;
class Vtestrunner___024root;
class VerilatedVcdC;
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


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vtestrunner VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtestrunner__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = true;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vtestrunner_junit_xml* const __PVT__junit_xml;
    Vtestrunner_svunit_pkg* const __PVT__svunit_pkg;
    Vtestrunner_alu_unit_test* const __PVT__testrunner__DOT_____05Fts__DOT__alu_ut;
    Vtestrunner_junit_xml__03a__03aXmlElement__Vclpkg* const junit_xml__03a__03aXmlElement__Vclpkg;
    Vtestrunner_junit_xml__03a__03aTestCase__Vclpkg* const junit_xml__03a__03aTestCase__Vclpkg;
    Vtestrunner_junit_xml__03a__03aTestSuite__Vclpkg* const junit_xml__03a__03aTestSuite__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_add_basic__Vclpkg* const alu_unit_test__03a__03atest_add_basic__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_add_overflow__Vclpkg* const alu_unit_test__03a__03atest_add_overflow__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_add_carry__Vclpkg* const alu_unit_test__03a__03atest_add_carry__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_sub_basic__Vclpkg* const alu_unit_test__03a__03atest_sub_basic__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_sub_zero__Vclpkg* const alu_unit_test__03a__03atest_sub_zero__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_and__Vclpkg* const alu_unit_test__03a__03atest_and__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_or__Vclpkg* const alu_unit_test__03a__03atest_or__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_xor__Vclpkg* const alu_unit_test__03a__03atest_xor__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_sll__Vclpkg* const alu_unit_test__03a__03atest_sll__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_srl__Vclpkg* const alu_unit_test__03a__03atest_srl__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_slt_true__Vclpkg* const alu_unit_test__03a__03atest_slt_true__Vclpkg;
    Vtestrunner_alu_unit_test__03a__03atest_slt_false__Vclpkg* const alu_unit_test__03a__03atest_slt_false__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03astring_utils__Vclpkg* const svunit_pkg__03a__03astring_utils__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_base__Vclpkg* const svunit_pkg__03a__03asvunit_base__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_test__Vclpkg* const svunit_pkg__03a__03asvunit_test__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_testcase__Vclpkg* const svunit_pkg__03a__03asvunit_testcase__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_testsuite__Vclpkg* const svunit_pkg__03a__03asvunit_testsuite__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03asvunit_testrunner__Vclpkg* const svunit_pkg__03a__03asvunit_testrunner__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg* const svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03afilter__Vclpkg* const svunit_pkg__03a__03afilter__Vclpkg;
    Vtestrunner_svunit_pkg__03a__03a__VDynScope_12__Vclpkg* const svunit_pkg__03a__03a__VDynScope_12__Vclpkg;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtestrunner___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtestrunner(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtestrunner(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtestrunner();
  private:
    VL_UNCOPYABLE(Vtestrunner);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); eval_end_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
