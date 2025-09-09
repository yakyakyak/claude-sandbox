// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtestrunner__Syms.h"


VL_ATTR_COLD void Vtestrunner___024root__trace_init_sub__TOP__testrunner__DOT_____05Fts__DOT__alu_ut__0(Vtestrunner___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtestrunner___024root__trace_init_sub__TOP__0(Vtestrunner___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root__trace_init_sub__TOP__0\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("testrunner", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("__ts", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("alu_ut", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtestrunner___024root__trace_init_sub__TOP__testrunner__DOT_____05Fts__DOT__alu_ut__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtestrunner___024root__trace_init_sub__TOP__testrunner__DOT_____05Fts__DOT__alu_ut__0(Vtestrunner___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root__trace_init_sub__TOP__testrunner__DOT_____05Fts__DOT__alu_ut__0\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
}

VL_ATTR_COLD void Vtestrunner___024root__trace_init_top(Vtestrunner___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root__trace_init_top\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtestrunner___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtestrunner___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtestrunner___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtestrunner___024root__trace_register(Vtestrunner___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root__trace_register\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtestrunner___024root__trace_const_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtestrunner___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtestrunner___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root__trace_const_0\n"); );
    // Init
    Vtestrunner___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtestrunner___024root*>(voidSelf);
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}
