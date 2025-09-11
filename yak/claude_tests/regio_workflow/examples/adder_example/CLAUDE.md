# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is the adder_example project within the ESnet FPGA library regio workflow. It demonstrates register map generation for a simple adder component using the regio tool infrastructure.

## Commands

### Register Generation

**Build register maps:**
```bash
cd src/adder_example/regio
make                                  # Generate all: register maps, compile, and synthesize
make reg                             # Generate register maps only
make compile                         # Compile generated RTL
make synth                          # Synthesize design
make clean                          # Remove all generated files
make info                           # Display register map information
```

**Regio-specific options:**
The Makefile supports regio elaboration and generation options via `REGIO_ELABORATE_OPTS` and `REGIO_GENERATE_OPTS` variables.

## Architecture

### Project Structure

This example follows the standard ESnet FPGA library component structure:
- `src/adder_example/regio/`: Register interface definitions and Makefile
- `src/adder_example/rtl/`: SystemVerilog RTL source files (to be populated)

### Register Map Configuration

The project uses the regio tool for register map generation:
- **REG_BLOCK_YAML**: `adder_example.yaml` - defines the adder component's register interface
- **REG_DECODER_YAML**: Currently empty - would contain decoder specifications if needed

### Integration

The project integrates with the parent ESnet FPGA library through:
- `LIB_ROOT` pointing to `../../../../../esnet-fpga-library/`
- Inclusion of standard library paths and regio Makefile templates
- Use of shared build infrastructure and tooling

This example serves as a template for creating register-mapped components within the ESnet FPGA library ecosystem.