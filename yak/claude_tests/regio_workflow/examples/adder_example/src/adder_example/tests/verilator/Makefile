# Makefile for Verilator simulation of adder_example

# Project paths
PROJ_ROOT := ../..
RTL_DIR := $(PROJ_ROOT)/rtl
REGIO_RTL_DIR := ../../../lib/regio/rtl/src
LIB_ROOT := ../../../../../../esnet-fpga-library

# ESnet library paths
ESNET_RTL_DIRS := \
	$(LIB_ROOT)/src/axi4l/rtl/src \
	$(LIB_ROOT)/src/reg/rtl/src \
	$(LIB_ROOT)/src/util/rtl/src

# Verilator configuration
VERILATOR := verilator
VERILATOR_FLAGS := \
	--cc --exe \
	--build \
	--trace \
	--Wall \
	-Wno-PINCONNECTEMPTY \
	-Wno-ASSIGNDLY \
	-Wno-DECLFILENAME \
	-Wno-UNUSED \
	--top-module tb_adder_example

# Include directories
INCDIRS := \
	$(RTL_DIR) \
	$(REGIO_RTL_DIR) \
	$(ESNET_RTL_DIRS)

VERILATOR_INCS := $(addprefix -I,$(INCDIRS))

# Source files
RTL_SOURCES := \
	$(RTL_DIR)/adder_example.sv \
	$(REGIO_RTL_DIR)/adder_example_reg_pkg.sv \
	$(REGIO_RTL_DIR)/adder_example_reg_intf.sv \
	$(REGIO_RTL_DIR)/adder_example_reg_blk.sv

TB_SOURCES := \
	tb_adder_example.sv \
	tb_adder_example.cpp

# ESnet library sources (all required packages and modules)
ESNET_SOURCES := \
	$(LIB_ROOT)/src/axi4l/rtl/src/axi4l_pkg.sv \
	$(LIB_ROOT)/src/reg/rtl/src/reg_pkg.sv \
	$(LIB_ROOT)/src/axi4l/rtl/src/axi4l_intf.sv \
	$(LIB_ROOT)/src/reg/rtl/src/reg_intf.sv \
	$(LIB_ROOT)/src/axi4l/rtl/src/axi4l_reg_peripheral.sv \
	$(LIB_ROOT)/src/reg/rtl/src/reg_rw.sv

# Targets
.PHONY: all clean sim waves help

all: sim

# Build and run simulation
sim: obj_dir/Vtb_adder_example
	@echo "Running simulation..."
	./obj_dir/Vtb_adder_example

# Build the Verilator executable
obj_dir/Vtb_adder_example: $(RTL_SOURCES) $(TB_SOURCES) $(ESNET_SOURCES)
	@echo "Building with Verilator..."
	$(VERILATOR) $(VERILATOR_FLAGS) \
		$(VERILATOR_INCS) \
		$(TB_SOURCES) \
		$(RTL_SOURCES) \
		$(ESNET_SOURCES)

# View waveforms (requires gtkwave)
waves: adder_example.vcd
	@echo "Opening waveforms in GTKWave..."
	gtkwave adder_example.vcd &

# Clean build artifacts
clean:
	rm -rf obj_dir
	rm -f adder_example.vcd

# Display help
help:
	@echo "Available targets:"
	@echo "  all    - Build and run simulation (default)"
	@echo "  sim    - Run simulation" 
	@echo "  waves  - View waveforms in GTKWave"
	@echo "  clean  - Clean build artifacts"
	@echo "  help   - Show this help"

# Check if required tools are available
check-tools:
	@which $(VERILATOR) > /dev/null || (echo "Error: Verilator not found. Install with: apt-get install verilator" && exit 1)
	@echo "✓ Verilator found: $(shell $(VERILATOR) --version | head -n1)"