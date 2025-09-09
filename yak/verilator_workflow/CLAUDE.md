# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a Verilator-based Verilog simulation workflow project. Verilator is a fast, open-source simulator that compiles Verilog HDL to C++ for high-performance simulation.

## Directory Structure

- **verilog/**: Source Verilog (.v) and SystemVerilog (.sv) files
- **testbenches/**: Testbench files for simulation and verification
- **sim/**: Generated simulation outputs, waveforms (.vcd), and build artifacts
- **docs/**: Project documentation and design specifications

## Commands

### Verilator Simulation Workflow

**Basic Simulation:**
```bash
# Compile Verilog to C++ simulator
verilator --cc --exe --build -j 0 -Wall testbenches/tb_top.cpp verilog/design.v

# Run simulation
./obj_dir/Vdesign

# With waveform generation
verilator --cc --exe --build -j 0 -Wall --trace testbenches/tb_top.cpp verilog/design.v
./obj_dir/Vdesign
```

**Linting:**
```bash
verilator --lint-only verilog/design.v
```

**Coverage Analysis:**
```bash
verilator --cc --exe --build -j 0 --coverage testbenches/tb_top.cpp verilog/design.v
./obj_dir/Vdesign
verilator_coverage --annotate logs logs/coverage.dat
```

### Waveform Viewing

```bash
# GTKWave for viewing VCD files
gtkwave sim/dump.vcd

# For FST format (faster, smaller files)
gtkwave sim/dump.fst
```

## Architecture

### Verilator Integration

This project uses Verilator's C++ testbench approach rather than traditional Verilog testbenches. Key aspects:

- **C++ Testbenches**: Main simulation control written in C++ for better performance and debugging
- **Clock Generation**: Handled in C++ with precise timing control
- **Signal Manipulation**: Direct access to design signals through Verilator's generated interface
- **Assertion Integration**: Supports both Verilog assertions and C++ checks

### Simulation Flow

1. **Verilator Compilation**: Converts Verilog to C++ classes
2. **C++ Compilation**: Links testbench with generated design model
3. **Execution**: Runs compiled simulator with timing-accurate results
4. **Trace Generation**: Optional VCD/FST output for waveform analysis

### Testbench Guidelines

**C++ Testbench Structure:**
- Include generated Verilator headers (`#include "Vdesign.h"`)
- Use `VerilatedContext` for simulation context management
- Implement proper clock edge simulation with `eval()` calls
- Handle reset sequences and initial conditions
- Use `VerilatedVcdC` for waveform tracing

**Performance Considerations:**
- Verilator optimizes for speed over waveform generation
- Use `--trace` only when waveforms are needed
- Consider `--trace-fst` for faster trace file generation
- Utilize `--build -j 0` for parallel compilation

## Requirements

- **Verilator**: Version 4.0+ recommended
  - macOS: `brew install verilator`
  - Ubuntu: `sudo apt-get install verilator`
- **GTKWave**: For waveform viewing
  - macOS: `brew install gtkwave`
  - Ubuntu: `sudo apt-get install gtkwave`
- **C++ Compiler**: GCC or Clang with C++14 support