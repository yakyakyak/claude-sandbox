# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This repository contains the ESnet FPGA library, a collection of general-purpose FPGA RTL design files and verification suites with a structured design methodology. The library provides standard components for network processing, memory interfaces, synchronization, and other common FPGA design patterns.

## Commands

### Project Configuration

**Initial Setup:**
```bash
cd esnet-fpga-library
make config                           # Configure with default settings
make config PART=<part_name>          # Configure for specific FPGA part
make clean                            # Remove all build outputs
```

### Running Tests

**Component Tests:**
```bash
# Navigate to specific component test directory (e.g., src/fifo/tests/fifo_sync/)
cd src/<component>/tests/<test_name>/
make                                  # Run single test
make waves=ON                         # Run test with waveform generation
make SEED=42 waves=ON                 # Run test with specific random seed
make REGRESSION=1                     # Run regression tests
```

**Common Test Examples:**
```bash
cd src/fifo/tests/fifo_sync && make waves=ON     # FIFO synchronous test
cd src/axi4l/tests/axi4l_intf && make           # AXI4-Lite interface test
cd src/reg/proxy/tests/reg_proxy && make        # Register proxy test
```

### SVUnit Testing Framework

Tests use the SVUnit framework for SystemVerilog unit testing:
```bash
# Test filtering (run specific test cases)
make SVUNIT_FILTER="*basic*" waves=ON
make SVUNIT_FILTER="testname" 
```

### Build Commands

**Component Building:**
```bash
cd src/<component>/rtl && make        # Build RTL component
cd src/<component>/build/<variant> && make  # Build specific IP variant
```

## Architecture

### Component Organization

The library is organized into functional modules under `src/`:

**Core Infrastructure:**
- **std/**: Standard library utilities and base types
- **util/**: General utility functions and common logic
- **sync/**: Clock domain crossing and synchronization primitives

**Memory and Storage:**
- **mem/**: Memory controllers and RAM interfaces  
- **fifo/**: FIFO implementations (sync/async, various configurations)
- **alloc/**: Memory allocation and management components

**Bus Interfaces:**
- **axi4l/**: AXI4-Lite protocol components (bridges, decoders, interfaces)
- **axi3/**: AXI3 protocol support with adapters and pipelines
- **axi4s/**: AXI4-Stream processing (packet handling, split/join)
- **apb/**: APB (Advanced Peripheral Bus) interface components
- **bus/**: Generic bus interfaces and utilities

**Network Processing:**
- **packet/**: Packet processing, queuing, and protocol handling (IPv4, TCP, Ethernet)
- **axi4s/**: Stream processing for packet data
- **sar/**: Segmentation and Reassembly for packet processing
- **pcap/**: Packet capture functionality

**Data Structures and Algorithms:**
- **htable/**: Hash table implementations including cuckoo hashing
- **db/**: Database-like storage with LRU and FIFO policies
- **crc/**: CRC calculation engines
- **arb/**: Arbitration logic (round-robin, priority-based)

**State Management:**
- **state/**: State machines and state vector management
- **timer/**: Timer and timeout functionality

**Register Interface:**
- **reg/**: Register map implementation with endianness handling and proxies

**Platform-Specific:**
- **xilinx/**: Xilinx-specific IP and memory implementations

### Design Methodology

**Component Structure:**
Each component follows a standard directory layout:
- `rtl/`: SystemVerilog source files
- `verif/`: Verification packages and utilities  
- `tests/`: SVUnit test suites with individual test cases
- `regio/`: Register interface definitions (where applicable)
- `build/`: Pre-configured IP variants and build targets
- `pkg/`: Package definitions and type libraries

**Makefile Infrastructure:**
The library uses a hierarchical Makefile system:
- Component-level Makefiles inherit from templates in `scripts/Makefiles/templates/`
- Test configuration via `test_base.mk` files that define dependencies and build settings
- Automatic dependency resolution between components
- Support for regression testing and waveform generation

**Register Generation:**
Uses the `regio` tool (in `tools/regio/`) for automatic register map generation:
- Python-based protocol definitions in `regio/` subdirectories
- Automatic RTL and software API generation
- Integrated with component build system

**Verification Approach:**
- SVUnit framework for unit testing (located in `tools/svunit/`)
- Regression test suites in each component's `tests/regression/` directory
- Waveform generation and debugging support
- Configurable test parameters (seeds, plusargs, compilation options)

### Key Design Patterns

**Parameterizable Components:** Most components support compile-time parameters for width, depth, and behavioral configuration

**Interface Standardization:** Consistent use of AXI4-Lite for register access and AXI4-Stream for data flow

**Hierarchical Testing:** Component tests can depend on subcomponents, with automatic dependency resolution

**Tool Integration:** Deep integration with Xilinx Vivado through specialized Makefiles and Tcl scripts

## Development Workflow

1. **Component Development**: Create new components under `src/` following the standard directory structure
2. **Testing**: Implement SVUnit tests in the component's `tests/` directory
3. **Register Maps**: Use regio tool for components requiring register interfaces
4. **Integration**: Add component dependencies to higher-level designs through Makefile includes
5. **Verification**: Run regression tests to ensure component compatibility

The library emphasizes reusable, parameterizable components with comprehensive verification suites suitable for high-performance network processing applications.