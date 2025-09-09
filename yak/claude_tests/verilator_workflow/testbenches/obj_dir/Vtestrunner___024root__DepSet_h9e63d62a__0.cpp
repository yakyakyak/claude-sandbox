// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner___024root.h"

VlCoroutine Vtestrunner___024root___eval_initial__TOP__Vtiming__0(Vtestrunner___024root* vlSelf);

void Vtestrunner___024root___eval_initial(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_initial\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtestrunner___024root___eval_initial__TOP__Vtiming__0(vlSelf);
}

void Vtestrunner___024root___eval_act(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_act\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtestrunner___024root___eval_nba(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_nba\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtestrunner___024root___timing_resume(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___timing_resume\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdynSched.resume();
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtestrunner___024root___eval_triggers__act(Vtestrunner___024root* vlSelf);

bool Vtestrunner___024root___eval_phase__act(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_phase__act\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtestrunner___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtestrunner___024root___timing_resume(vlSelf);
        Vtestrunner___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtestrunner___024root___eval_phase__nba(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_phase__nba\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtestrunner___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestrunner___024root___dump_triggers__nba(Vtestrunner___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestrunner___024root___dump_triggers__act(Vtestrunner___024root* vlSelf);
#endif  // VL_DEBUG

void Vtestrunner___024root___eval(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtestrunner___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/.testrunner.sv", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtestrunner___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/yak/Projects/Claude/claude_hardware_projects/claude-sandbox/yak/verilator_workflow/testbenches/.testrunner.sv", 2, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtestrunner___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtestrunner___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtestrunner___024root___eval_debug_assertions(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_debug_assertions\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
