// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtestrunner__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtestrunner::Vtestrunner(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtestrunner__Syms(contextp(), _vcname__, this)}
    , __PVT__junit_xml{vlSymsp->TOP.__PVT__junit_xml}
    , __PVT__svunit_pkg{vlSymsp->TOP.__PVT__svunit_pkg}
    , __PVT__testrunner__DOT_____05Fts__DOT__alu_ut{vlSymsp->TOP.__PVT__testrunner__DOT_____05Fts__DOT__alu_ut}
    , junit_xml__03a__03aXmlElement__Vclpkg{vlSymsp->TOP.junit_xml__03a__03aXmlElement__Vclpkg}
    , junit_xml__03a__03aTestCase__Vclpkg{vlSymsp->TOP.junit_xml__03a__03aTestCase__Vclpkg}
    , junit_xml__03a__03aTestSuite__Vclpkg{vlSymsp->TOP.junit_xml__03a__03aTestSuite__Vclpkg}
    , alu_unit_test__03a__03atest_add_basic__Vclpkg{vlSymsp->TOP.alu_unit_test__03a__03atest_add_basic__Vclpkg}
    , alu_unit_test__03a__03atest_add_overflow__Vclpkg{vlSymsp->TOP.alu_unit_test__03a__03atest_add_overflow__Vclpkg}
    , alu_unit_test__03a__03atest_add_carry__Vclpkg{vlSymsp->TOP.alu_unit_test__03a__03atest_add_carry__Vclpkg}
    , alu_unit_test__03a__03atest_sub_basic__Vclpkg{vlSymsp->TOP.alu_unit_test__03a__03atest_sub_basic__Vclpkg}
    , alu_unit_test__03a__03atest_sub_zero__Vclpkg{vlSymsp->TOP.alu_unit_test__03a__03atest_sub_zero__Vclpkg}
    , alu_unit_test__03a__03atest_and__Vclpkg{vlSymsp->TOP.alu_unit_test__03a__03atest_and__Vclpkg}
    , alu_unit_test__03a__03atest_or__Vclpkg{vlSymsp->TOP.alu_unit_test__03a__03atest_or__Vclpkg}
    , alu_unit_test__03a__03atest_xor__Vclpkg{vlSymsp->TOP.alu_unit_test__03a__03atest_xor__Vclpkg}
    , alu_unit_test__03a__03atest_sll__Vclpkg{vlSymsp->TOP.alu_unit_test__03a__03atest_sll__Vclpkg}
    , alu_unit_test__03a__03atest_srl__Vclpkg{vlSymsp->TOP.alu_unit_test__03a__03atest_srl__Vclpkg}
    , alu_unit_test__03a__03atest_slt_true__Vclpkg{vlSymsp->TOP.alu_unit_test__03a__03atest_slt_true__Vclpkg}
    , alu_unit_test__03a__03atest_slt_false__Vclpkg{vlSymsp->TOP.alu_unit_test__03a__03atest_slt_false__Vclpkg}
    , svunit_pkg__03a__03astring_utils__Vclpkg{vlSymsp->TOP.svunit_pkg__03a__03astring_utils__Vclpkg}
    , svunit_pkg__03a__03asvunit_base__Vclpkg{vlSymsp->TOP.svunit_pkg__03a__03asvunit_base__Vclpkg}
    , svunit_pkg__03a__03asvunit_test__Vclpkg{vlSymsp->TOP.svunit_pkg__03a__03asvunit_test__Vclpkg}
    , svunit_pkg__03a__03asvunit_testcase__Vclpkg{vlSymsp->TOP.svunit_pkg__03a__03asvunit_testcase__Vclpkg}
    , svunit_pkg__03a__03asvunit_testsuite__Vclpkg{vlSymsp->TOP.svunit_pkg__03a__03asvunit_testsuite__Vclpkg}
    , svunit_pkg__03a__03asvunit_testrunner__Vclpkg{vlSymsp->TOP.svunit_pkg__03a__03asvunit_testrunner__Vclpkg}
    , svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg{vlSymsp->TOP.svunit_pkg__03a__03afilter_for_single_pattern__Vclpkg}
    , svunit_pkg__03a__03afilter__Vclpkg{vlSymsp->TOP.svunit_pkg__03a__03afilter__Vclpkg}
    , svunit_pkg__03a__03a__VDynScope_12__Vclpkg{vlSymsp->TOP.svunit_pkg__03a__03a__VDynScope_12__Vclpkg}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtestrunner::Vtestrunner(const char* _vcname__)
    : Vtestrunner(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtestrunner::~Vtestrunner() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtestrunner___024root___eval_debug_assertions(Vtestrunner___024root* vlSelf);
#endif  // VL_DEBUG
void Vtestrunner___024root___eval_static(Vtestrunner___024root* vlSelf);
void Vtestrunner___024root___eval_initial(Vtestrunner___024root* vlSelf);
void Vtestrunner___024root___eval_settle(Vtestrunner___024root* vlSelf);
void Vtestrunner___024root___eval(Vtestrunner___024root* vlSelf);

void Vtestrunner::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtestrunner::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtestrunner___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtestrunner___024root___eval_static(&(vlSymsp->TOP));
        Vtestrunner___024root___eval_initial(&(vlSymsp->TOP));
        Vtestrunner___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtestrunner___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vtestrunner::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vtestrunner::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vtestrunner::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtestrunner::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtestrunner::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtestrunner___024root___eval_final(Vtestrunner___024root* vlSelf);

VL_ATTR_COLD void Vtestrunner::final() {
    Vtestrunner___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtestrunner::hierName() const { return vlSymsp->name(); }
const char* Vtestrunner::modelName() const { return "Vtestrunner"; }
unsigned Vtestrunner::threads() const { return 1; }
void Vtestrunner::prepareClone() const { contextp()->prepareClone(); }
void Vtestrunner::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtestrunner::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtestrunner___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtestrunner___024root__trace_init_top(Vtestrunner___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtestrunner___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtestrunner___024root*>(voidSelf);
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vtestrunner___024root__trace_decl_types(tracep);
    Vtestrunner___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtestrunner___024root__trace_register(Vtestrunner___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtestrunner::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtestrunner::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtestrunner___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
