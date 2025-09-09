// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner___024root.h"

VL_ATTR_COLD void Vtestrunner___024root___eval_final(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_final\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestrunner___024root___dump_triggers__stl(Vtestrunner___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtestrunner___024root___eval_phase__stl(Vtestrunner___024root* vlSelf);

VL_ATTR_COLD void Vtestrunner___024root___eval_settle(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_settle\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtestrunner___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/.testrunner.sv", 2, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtestrunner___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestrunner___024root___dump_triggers__stl(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___dump_triggers__stl\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtestrunner___024root___eval_triggers__stl(Vtestrunner___024root* vlSelf);
VL_ATTR_COLD void Vtestrunner___024root___eval_stl(Vtestrunner___024root* vlSelf);

VL_ATTR_COLD bool Vtestrunner___024root___eval_phase__stl(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_phase__stl\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtestrunner___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtestrunner___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestrunner___024root___dump_triggers__act(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___dump_triggers__act\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdynSched.evaluate())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestrunner___024root___dump_triggers__nba(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___dump_triggers__nba\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdynSched.evaluate())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtestrunner___024root___ctor_var_reset(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___ctor_var_reset\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    }
