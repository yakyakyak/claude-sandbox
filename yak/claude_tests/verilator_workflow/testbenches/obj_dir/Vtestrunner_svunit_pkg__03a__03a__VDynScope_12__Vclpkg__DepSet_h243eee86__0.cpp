// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestrunner.h for the primary calling header

#include "Vtestrunner__pch.h"
#include "Vtestrunner_svunit_pkg__03a__03a__VDynScope_12__Vclpkg.h"

std::string VL_TO_STRING(const VlClassRef<Vtestrunner_svunit_pkg__03a__03a__VDynScope_12>& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vtestrunner_svunit_pkg__03a__03a__VDynScope_12::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->to_string() : "null");
}

std::string Vtestrunner_svunit_pkg__03a__03a__VDynScope_12::to_string() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vtestrunner_svunit_pkg__03a__03a__VDynScope_12::to_string\n"); );
    // Body
    return ("'{"s + to_string_middle() + "}");
}

std::string Vtestrunner_svunit_pkg__03a__03a__VDynScope_12::to_string_middle() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vtestrunner_svunit_pkg__03a__03a__VDynScope_12::to_string_middle\n"); );
    // Body
    std::string out;
    out += "local_error_count:" + VL_TO_STRING(__PVT__local_error_count);
    return out;
}
