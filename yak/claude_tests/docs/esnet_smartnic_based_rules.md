# SystemVerilog Coding Style Guide - ESnet SmartNIC

## Overview
This guide captures the coding patterns and conventions observed in the ESnet SmartNIC hardware codebase to ensure consistency and maintainability.

## File Organization

### File Extensions
- **SystemVerilog files**: `.sv` (preferred for all new code)
- **Verilog files**: `.v` (legacy files only)

### Directory Structure
- `src/`: Source files organized by functional blocks
- `pkg/`: Package files containing type definitions and constants
- `rtl/`: RTL implementation files  
- `tb/`: Testbench files
- `tests/`: Unit test files
- `verif/`: Verification packages

## Naming Conventions

### Modules
- Use lowercase with underscores: `smartnic_mux`, `xilinx_alveo_cmac`
- Include project/vendor prefix for clarity: `xilinx_`, `smartnic_`

### Signals and Variables
- Use lowercase with underscores: `axis_cmac_to_core`, `egr_flow_ctl`
- Use descriptive names that indicate data flow direction
- Prefix temporary/intermediate signals with underscore: `_axis_from_cmac`
- Double underscore for deeply intermediate signals: `__axis_hash2qid`

### Parameters
- Use UPPERCASE with underscores: `NUM_CMAC`, `MAX_PKT_LEN`
- Parameter types use `_T` suffix: `TID_T`, `TDEST_T`, `TUSER_T`

### Types
- Package names use lowercase with `_pkg` suffix: `smartnic_pkg`, `xilinx_axi_pkg`
- Typedef names use lowercase with `_t` suffix: `port_t`, `timestamp_t`
- Enum values use UPPERCASE: `PF`, `VF0`, `VF1`, `APP`, `BYPASS`

### Interfaces
- AXI interfaces: `axil_if`, `axis_if` with descriptive suffixes
- Use array notation for multiple instances: `axis_h2c[NUM_CMAC]`

## Code Structure

### Module Declaration
```systemverilog
module module_name #(
    parameter int PARAM_NAME = default_value,
    parameter bit PARAM_FLAG = 1'b0
) (
    input  logic       signal_name,
    output logic [3:0] signal_array,
    
    interface_type.modport interface_name
);
```

### Parameter Declarations
- Use `parameter int` for integer parameters
- Use `parameter bit` for boolean flags  
- Include default values where appropriate
- Group related parameters together

### Port Declarations
- One signal per line with consistent alignment
- Use explicit direction (`input`/`output`)
- Use `logic` type instead of `wire`/`reg`
- Group ports logically (clocks/resets, data interfaces, control)

### Package Imports
```systemverilog
// Imports (after module declaration)
import package_name::*;
import specific_pkg::specific_item;
```

## Interface Usage

### AXI4-Stream Interfaces
```systemverilog
axi4s_intf #(
    .DATA_BYTE_WID (64),
    .TID_T         (port_t),
    .TDEST_T       (port_t),
    .TUSER_T       (tuser_smartnic_meta_t)
) interface_name ();
```

### AXI4-Lite Interfaces
```systemverilog
axi4l_intf interface_name ();
```

### Interface Arrays
```systemverilog
axi4s_intf #(...) axis_array [NUM_INSTANCES] ();
axi4s_intf #(...) axis_2d_array [NUM_CMAC][HOST_NUM_IFS] ();
```

## Signal Declarations

### Signal Groups
Organize signals in logical groups with comments:
```systemverilog
// Clock/reset signals
logic clk;
logic srst;

// AXI4-Stream interfaces  
axi4s_intf #(...) axis_in ();
axi4s_intf #(...) axis_out ();

// Control/status signals
logic [NUM_PORTS-1:0] enable_flags;
```

### Wire vs Logic
- Use `logic` for all signals (both combinational and sequential)
- Use `wire` only for legacy Verilog compatibility

## Generate Blocks

### Array Instantiation Pattern
```systemverilog
generate for (genvar i = 0; i < NUM_INSTANCES; i += 1) begin : g__instance_name
    // Instance declarations
    module_name #(
        .PARAM (value)
    ) instance_name (
        .signal (signal_array[i])
    );
end : g__instance_name
endgenerate
```

### Generate Block Naming
- Use `g__` prefix: `g__fifo`, `g__mux_demux`
- Include descriptive suffix indicating purpose
- Always provide end label matching begin label

## Sequential Logic

### Clocked Processes
```systemverilog
always @(posedge clk) begin
    if (!rstn) begin
        // Reset assignments
        signal <= '0;
    end else begin
        // Normal operation
        if (condition) begin
            signal <= new_value;
        end
    end
end
```

### Reset Style
- Use synchronous reset with active-low polarity (`rstn`)
- Reset all sequential signals to known values
- Use `'0` for resetting to zero

## Combinational Logic

### Always_comb Blocks
```systemverilog
always_comb begin
    output_signal = input_signal;
    case (select)
        VALUE1: result = option1;
        VALUE2: result = option2;
        default: result = default_value;
    endcase
end
```

### Continuous Assignments
```systemverilog
assign output_signal = input_signal;
assign array_signal[index] = source_signal;
```

## Instantiation Patterns

### Named Port Connections
```systemverilog
module_name #(
    .PARAMETER_NAME (PARAMETER_VALUE)
) instance_name (
    .port_name (signal_name),
    .port_array (signal_array[index])
);
```

### Interface Connections
```systemverilog
module_name instance_name (
    .axi4s_if (interface_name),
    .clk      (clock_signal),
    .rst      (reset_signal)
);
```

## Comments and Documentation

### Module Headers
```systemverilog
// =========================================================================
// Module Description
// =========================================================================
```

### Section Separators
```systemverilog
// ----------------------------------------------------------------
// Section Name
// ----------------------------------------------------------------
```

### Inline Comments
- Use `//` for single-line comments
- Align comments with code when describing specific lines
- Use descriptive comments for complex logic

## Package Definitions

### Package Structure
```systemverilog
package package_name;
    // --------------------------------------------------------------
    // Parameters
    // --------------------------------------------------------------
    localparam int CONSTANT_NAME = value;

    // --------------------------------------------------------------
    // Typedefs
    // --------------------------------------------------------------
    typedef logic [WIDTH-1:0] type_name_t;
    
    typedef enum logic [1:0] {
        ENUM_VALUE1 = 2'h0,
        ENUM_VALUE2 = 2'h1
    } enum_name_t;

endpackage : package_name
```

## Testbench Guidelines

### Testbench Structure
```systemverilog
module testbench_name;
    import svunit_pkg::svunit_testcase;
    import package_name::*;
    
    string name = "test_name";
    svunit_testcase svunit_ut;
    
    // Parameters
    localparam int PARAM = value;
    
    // DUT instantiation
    module_name #(
        .PARAM (PARAM)
    ) DUT (
        .ports (signals)
    );
    
    // Test infrastructure
    // Clock generation
    `SVUNIT_CLK_GEN(clk, period);
    
    // Test cases
    `SVUNIT_TESTS_BEGIN
        `SVTEST(test_name)
            // Test code
        `SVTEST_END
    `SVUNIT_TESTS_END
endmodule
```

## Best Practices

### Interface Usage
- Use interfaces for all AXI protocols
- Leverage modports for interface direction control
- Use interface arrays for multiple similar connections

### Type Safety
- Use typedef for all custom types
- Leverage packed structs for complex data types
- Use enums instead of parameters for named constants

### Signal Naming
- Include direction in signal names: `axis_tx`, `axis_rx`
- Use consistent prefixes: `axil_`, `axis_`, `smartnic_`
- Indicate signal purpose: `_probe`, `_ovfl`, `_err`

### Code Organization
- Group related signals and instances together
- Use consistent indentation (4 spaces)
- Align port/signal declarations vertically
- Use blank lines to separate logical sections

### Array Indexing
- Use generate blocks for regular array patterns
- Prefer `[NUM-1:0]` over `[0:NUM-1]` for vectors
- Use meaningful index variables in generate blocks

### Memory and Generics
- Always provide parameter default values
- Use `int` type for integer parameters
- Document parameter meanings and valid ranges