#!/bin/bash

# Compile the Verilog files with Verilator
verilator --sv --cc openai_alu.sv --exe openai_alu_tb.sv --timing

# Build the executable
make -C obj_dir -f Vopenai_alu.mk Vopenai_alu

# Run the testbench
./obj_dir/Vopenai_alu
