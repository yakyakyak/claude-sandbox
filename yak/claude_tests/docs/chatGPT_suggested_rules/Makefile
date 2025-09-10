# =====================================================
# Verilog Lint & Simulation Makefile
# =====================================================

RTL_DIR   = rtl
TB_DIR    = tb
RTL_SRCS  = $(wildcard $(RTL_DIR)/*.v)
TB_SRCS   = $(wildcard $(TB_DIR)/*.v)

BUILD_DIR = build
WAVE_FILE = dump.vcd

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

lint: $(BUILD_DIR)
	verilator -f .verilator.f --lint-only $(RTL_SRCS)

sim: $(BUILD_DIR)
	verilator -f .verilator.f \
	    --cc --exe --build \
	    -o $(BUILD_DIR)/sim_main \
	    $(RTL_SRCS) $(TB_SRCS) sim_main.cpp
	$(BUILD_DIR)/sim_main

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all lint sim clean
