// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_alu_unit_test.h"

VL_ATTR_COLD void Vtestrunner_alu_unit_test___stl_sequent__TOP__testrunner__DOT_____05Fts__DOT__alu_ut__0(Vtestrunner_alu_unit_test* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtestrunner_alu_unit_test___stl_sequent__TOP__testrunner__DOT_____05Fts__DOT__alu_ut__0\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*32:0*/ __PVT__my_alu__DOT__temp_result;
    __PVT__my_alu__DOT__temp_result = 0;
    CData/*0:0*/ my_alu__DOT____VdfgRegularize_hac4c0285_0_4;
    my_alu__DOT____VdfgRegularize_hac4c0285_0_4 = 0;
    // Body
    __PVT__my_alu__DOT__temp_result = 0ULL;
    vlSelfRef.__PVT__result = 0U;
    if ((8U & (IData)(vlSelfRef.__PVT__op))) {
        vlSelfRef.__PVT__result = ((4U & (IData)(vlSelfRef.__PVT__op))
                                    ? 0U : ((2U & (IData)(vlSelfRef.__PVT__op))
                                             ? ((1U 
                                                 & (IData)(vlSelfRef.__PVT__op))
                                                 ? 
                                                (~ 
                                                 (vlSelfRef.__PVT__a 
                                                  & vlSelfRef.__PVT__b))
                                                 : 
                                                (~ 
                                                 (vlSelfRef.__PVT__a 
                                                  | vlSelfRef.__PVT__b)))
                                             : ((1U 
                                                 & (IData)(vlSelfRef.__PVT__op))
                                                 ? 
                                                ((vlSelfRef.__PVT__a 
                                                  < vlSelfRef.__PVT__b)
                                                  ? 1U
                                                  : 0U)
                                                 : 
                                                (VL_LTS_III(32, vlSelfRef.__PVT__a, vlSelfRef.__PVT__b)
                                                  ? 1U
                                                  : 0U))));
    } else if ((4U & (IData)(vlSelfRef.__PVT__op))) {
        vlSelfRef.__PVT__result = ((2U & (IData)(vlSelfRef.__PVT__op))
                                    ? ((1U & (IData)(vlSelfRef.__PVT__op))
                                        ? VL_SHIFTRS_III(32,32,5, vlSelfRef.__PVT__a, 
                                                         (0x1fU 
                                                          & vlSelfRef.__PVT__b))
                                        : (vlSelfRef.__PVT__a 
                                           >> (0x1fU 
                                               & vlSelfRef.__PVT__b)))
                                    : ((1U & (IData)(vlSelfRef.__PVT__op))
                                        ? (vlSelfRef.__PVT__a 
                                           << (0x1fU 
                                               & vlSelfRef.__PVT__b))
                                        : (vlSelfRef.__PVT__a 
                                           ^ vlSelfRef.__PVT__b)));
    } else if ((2U & (IData)(vlSelfRef.__PVT__op))) {
        vlSelfRef.__PVT__result = ((1U & (IData)(vlSelfRef.__PVT__op))
                                    ? (vlSelfRef.__PVT__a 
                                       | vlSelfRef.__PVT__b)
                                    : (vlSelfRef.__PVT__a 
                                       & vlSelfRef.__PVT__b));
    } else if ((1U & (IData)(vlSelfRef.__PVT__op))) {
        __PVT__my_alu__DOT__temp_result = (0x1ffffffffULL 
                                           & ((QData)((IData)(vlSelfRef.__PVT__a)) 
                                              - (QData)((IData)(vlSelfRef.__PVT__b))));
        vlSelfRef.__PVT__result = (IData)(__PVT__my_alu__DOT__temp_result);
    } else {
        __PVT__my_alu__DOT__temp_result = (0x1ffffffffULL 
                                           & ((QData)((IData)(vlSelfRef.__PVT__a)) 
                                              + (QData)((IData)(vlSelfRef.__PVT__b))));
        vlSelfRef.__PVT__result = (IData)(__PVT__my_alu__DOT__temp_result);
    }
    vlSelfRef.__PVT__carry_out = (((0U == (IData)(vlSelfRef.__PVT__op)) 
                                   | (1U == (IData)(vlSelfRef.__PVT__op))) 
                                  & (IData)((__PVT__my_alu__DOT__temp_result 
                                             >> 0x20U)));
    my_alu__DOT____VdfgRegularize_hac4c0285_0_4 = (
                                                   (vlSelfRef.__PVT__result 
                                                    >> 0x1fU) 
                                                   != 
                                                   (vlSelfRef.__PVT__a 
                                                    >> 0x1fU));
    vlSelfRef.__PVT__overflow = ((0U == (IData)(vlSelfRef.__PVT__op))
                                  ? (((vlSelfRef.__PVT__a 
                                       >> 0x1fU) == 
                                      (vlSelfRef.__PVT__b 
                                       >> 0x1fU)) & (IData)(my_alu__DOT____VdfgRegularize_hac4c0285_0_4))
                                  : ((1U == (IData)(vlSelfRef.__PVT__op)) 
                                     & (((vlSelfRef.__PVT__a 
                                          >> 0x1fU) 
                                         != (vlSelfRef.__PVT__b 
                                             >> 0x1fU)) 
                                        & (IData)(my_alu__DOT____VdfgRegularize_hac4c0285_0_4))));
}

VL_ATTR_COLD void Vtestrunner_alu_unit_test___ctor_var_reset(Vtestrunner_alu_unit_test* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtestrunner_alu_unit_test___ctor_var_reset\n"); );
    Vtestrunner__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__PVT__a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 510903276987443985ull);
    vlSelf->__PVT__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16900879642891266615ull);
    vlSelf->__PVT__op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3630531923276091163ull);
    vlSelf->__PVT__result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16664408842984530663ull);
    vlSelf->__PVT__overflow = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16341344440165733293ull);
    vlSelf->__PVT__carry_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14237614780810244017ull);
    }
