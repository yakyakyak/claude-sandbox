// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner__Syms.h"
#include "Vtestrunner___024root.h"

VL_ATTR_COLD void Vtestrunner_alu_unit_test___eval_static__TOP__testrunner__DOT_____05Fts__DOT__alu_ut(Vtestrunner_alu_unit_test* vlSelf);
VL_ATTR_COLD void Vtestrunner_svunit_pkg___eval_static__TOP__svunit_pkg(Vtestrunner_svunit_pkg* vlSelf);

VL_ATTR_COLD void Vtestrunner___024root___eval_static(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_static\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtestrunner_alu_unit_test___eval_static__TOP__testrunner__DOT_____05Fts__DOT__alu_ut((&vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut));
    Vtestrunner_svunit_pkg___eval_static__TOP__svunit_pkg((&vlSymsp->TOP__svunit_pkg));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestrunner___024root___dump_triggers__stl(Vtestrunner___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtestrunner___024root___eval_triggers__stl(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_triggers__stl\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtestrunner___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtestrunner_alu_unit_test___stl_sequent__TOP__testrunner__DOT_____05Fts__DOT__alu_ut__0(Vtestrunner_alu_unit_test* vlSelf);

VL_ATTR_COLD void Vtestrunner___024root___eval_stl(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_stl\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtestrunner_alu_unit_test___stl_sequent__TOP__testrunner__DOT_____05Fts__DOT__alu_ut__0((&vlSymsp->TOP__testrunner__DOT_____05Fts__DOT__alu_ut));
    }
}
