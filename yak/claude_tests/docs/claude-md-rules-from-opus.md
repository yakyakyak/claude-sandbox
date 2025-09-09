# Verilog Design Rules for Claude Code

## Naming
- **Modules**: `lowercase_underscore` (e.g., `fifo_controller`)
- **Signals**: `lowercase_underscore`, suffix `_n` for active-low, `_q`/`_d` for registered
- **Parameters**: `UPPERCASE` (e.g., `DATA_WIDTH`)
- **Clocks**: prefix `clk_` or just `clk`

## Module Template
```verilog
module module_name #(
    parameter PARAM = 8
)(
    input  wire clk,
    input  wire reset_n,
    // Control signals
    input  wire enable,
    output reg  ready,
    // Data signals  
    input  wire [PARAM-1:0] data_in,
    output reg  [PARAM-1:0] data_out
);
    // Internal declarations first
    reg [3:0] state_q, state_d;
    
    // Sequential: non-blocking (<=), single clock edge
    always @(posedge clk) begin
        if (!reset_n) begin
            state_q <= '0;
        end else begin
            state_q <= state_d;
        end
    end
    
    // Combinational: blocking (=), complete sensitivity
    always @(*) begin
        state_d = state_q;  // Default assignment
        case (state_q)
            // FSM logic
        endcase
    end
endmodule
```

## Critical Rules
1. **Sequential blocks**: Use `<=`, include reset for all registers
2. **Combinational blocks**: Use `=`, assign defaults first to prevent latches
3. **FSM**: Separate state register from next-state logic
4. **No synthesis issues**: No `initial` blocks, no delays (#), no X/Z in logic
5. **Complete sensitivity**: Use `@(*)` or list all inputs
6. **Explicit sizing**: Always specify bit widths `[7:0]`

## Testbench Template
```verilog
`timescale 1ns/1ps
module tb_module();
    localparam CLK_PERIOD = 10;
    
    // DUT signals
    reg clk = 0;
    reg reset_n;
    
    // Clock generation
    always #(CLK_PERIOD/2) clk = ~clk;
    
    // DUT instance
    module_name dut (.*);
    
    // Test sequence
    initial begin
        // Initialize
        reset_n = 0;
        #(CLK_PERIOD*5);
        reset_n = 1;
        
        // Test cases
        @(posedge clk);
        // Apply stimulus
        
        // Check results
        if (result !== expected) $display("ERROR");
        
        $finish;
    end
    
    // Timeout protection
    initial begin
        #100000;
        $display("Timeout!");
        $finish;
    end
endmodule
```

## Tasks for Testbenches
```verilog
task apply_reset();
    @(posedge clk);
    reset_n <= 0;
    repeat(5) @(posedge clk);
    reset_n <= 1;
endtask

task check_result(input [7:0] exp, act);
    if (exp !== act) 
        $display("ERROR: Expected %h, Got %h", exp, act);
endtask
```

## FSM Pattern
```verilog
localparam [1:0] IDLE = 2'b00,
                 RUN  = 2'b01,
                 DONE = 2'b10;

reg [1:0] state_q, state_d;

// State register
always @(posedge clk)
    if (!reset_n) state_q <= IDLE;
    else state_q <= state_d;

// Next state + outputs
always @(*) begin
    state_d = state_q;  // Default
    out = 0;           // Default
    
    case (state_q)
        IDLE: if (start) state_d = RUN;
        RUN:  begin
            out = 1;
            if (complete) state_d = DONE;
        end
        DONE: state_d = IDLE;
        default: state_d = IDLE;
    endcase
end
```

## Common Patterns

### Counter
```verilog
reg [7:0] cnt_q;
wire cnt_en = (state_q == RUN);
wire cnt_done = (cnt_q == MAX_COUNT);

always @(posedge clk)
    if (!reset_n) cnt_q <= '0;
    else if (cnt_en) cnt_q <= cnt_q + 1'b1;
```

### Synchronizer (CDC)
```verilog
reg [1:0] sync_q;
always @(posedge clk_dest)
    if (!reset_n) sync_q <= '0;
    else sync_q <= {sync_q[0], async_in};
wire sync_out = sync_q[1];
```

### Shift Register
```verilog
reg [7:0] shift_q;
always @(posedge clk)
    if (!reset_n) shift_q <= '0;
    else if (shift_en) shift_q <= {shift_q[6:0], serial_in};
```

### Edge Detector
```verilog
reg signal_q;
always @(posedge clk) signal_q <= signal;
wire rising_edge = signal & ~signal_q;
wire falling_edge = ~signal & signal_q;
```

## Must Avoid
- Incomplete case without default
- Missing signals in sensitivity list  
- Mixing blocking/non-blocking incorrectly
- Multiple drivers for same signal
- Combinational loops
- Latches (unintentional)
- Initial blocks in RTL
- Delays (#) in synthesizable code

## Quick Checks
✓ All regs have reset values
✓ All outputs assigned in all paths
✓ Parameters for all magic numbers
✓ No warnings from synthesis
✓ Testbench has timeout
✓ Self-checking tests