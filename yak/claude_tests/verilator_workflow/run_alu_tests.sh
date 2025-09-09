#!/bin/bash

# ALU Test Runner Script for Verilator
# This script compiles and runs the ALU testbench using Verilator

set -e  # Exit on any error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}=====================================${NC}"
echo -e "${YELLOW}    ALU Verilator Test Runner${NC}"
echo -e "${YELLOW}=====================================${NC}"

# Create sim directory if it doesn't exist
if [ ! -d "sim" ]; then
    echo "Creating sim directory..."
    mkdir -p sim
fi

# Clean previous build artifacts
echo "Cleaning previous build artifacts..."
rm -rf obj_dir
rm -f sim/*.vcd
rm -f sim/*.fst

# Check if Verilator is installed
if ! command -v verilator &> /dev/null; then
    echo -e "${RED}ERROR: Verilator is not installed or not in PATH${NC}"
    echo "Please install Verilator:"
    echo "  macOS: brew install verilator"
    echo "  Ubuntu: sudo apt-get install verilator"
    exit 1
fi

# Check if required files exist
if [ ! -f "verilog/alu.v" ]; then
    echo -e "${RED}ERROR: verilog/alu.v not found${NC}"
    exit 1
fi

if [ ! -f "testbenches/tb_alu.cpp" ]; then
    echo -e "${RED}ERROR: testbenches/tb_alu.cpp not found${NC}"
    exit 1
fi

echo "Verilator version: $(verilator --version | head -1)"
echo ""

# Lint the Verilog code
echo -e "${YELLOW}Step 1: Linting Verilog code...${NC}"
if verilator --lint-only verilog/alu.v; then
    echo -e "${GREEN}✓ Linting passed${NC}"
else
    echo -e "${RED}✗ Linting failed${NC}"
    exit 1
fi
echo ""

# Compile with Verilator
echo -e "${YELLOW}Step 2: Compiling with Verilator...${NC}"
if verilator --cc --exe --build -j 0 -Wall --trace \
    testbenches/tb_alu.cpp \
    verilog/alu.v; then
    echo -e "${GREEN}✓ Compilation successful${NC}"
else
    echo -e "${RED}✗ Compilation failed${NC}"
    exit 1
fi
echo ""

# Run the simulation
echo -e "${YELLOW}Step 3: Running ALU tests...${NC}"
echo ""

if ./obj_dir/Valu; then
    echo ""
    echo -e "${GREEN}✓ Simulation completed successfully${NC}"
    
    # Check if VCD file was generated
    if [ -f "sim/alu_test.vcd" ]; then
        echo -e "${GREEN}✓ Waveform file generated: sim/alu_test.vcd${NC}"
        echo "  View with: gtkwave sim/alu_test.vcd"
    fi
else
    echo -e "${RED}✗ Simulation failed${NC}"
    exit 1
fi

echo ""
echo -e "${YELLOW}=====================================${NC}"
echo -e "${GREEN}    ALU Tests Complete!${NC}"
echo -e "${YELLOW}=====================================${NC}"

# Optional: Show file sizes
echo ""
echo "Generated files:"
ls -lh obj_dir/Valu 2>/dev/null || true
ls -lh sim/*.vcd 2>/dev/null || true

echo ""
echo "To view waveforms: gtkwave sim/alu_test.vcd"
echo "To clean build files: rm -rf obj_dir sim/*.vcd"