// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner__Syms.h"
#include "Vtestrunner___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestrunner___024root___dump_triggers__act(Vtestrunner___024root* vlSelf);
#endif  // VL_DEBUG

void Vtestrunner___024root___eval_triggers__act(Vtestrunner___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestrunner___024root___eval_triggers__act\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.setBit(1U, vlSelfRef.__VdynSched.evaluate());
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtestrunner___024root___dump_triggers__act(vlSelf);
    }
#endif
    vlSelfRef.__VdynSched.doPostUpdates();
}
