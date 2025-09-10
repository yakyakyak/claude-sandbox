# Verilog Coding Rules (CLAUDE.md)

This document defines coding rules for AI-assisted Verilog generation.  
It ensures **lint-clean, synthesizable, and maintainable** Verilog RTL.

---

## 1. General Principles
- All modules must be **synthesizable** unless explicitly marked as testbench-only.
- Use **SystemVerilog-2005 subset** supported by most synthesis tools (no exotic features).
- RTL must be **lint-clean under Verilator** with `.verilator.f` config.

---

## 2. Style Rules

### 2.1 Module Declaration
✅ Do:
```verilog
`default_nettype none

module my_module #(
    parameter WIDTH = 8
)(
    input  wire             clk,
    input  wire             rst_n,
    input  wire [WIDTH-1:0] i_data,
    output reg  [WIDTH-1:0] o_data
);
```
❌ Don’t:
```verilog
module my_module (clk, rst_n, i_data, o_data);
```

### 2.2 Signal Naming
- Inputs: `i_foo`
- Outputs: `o_bar`
- Internal regs: `r_foo`
- Internal wires: `w_bar`
- Active-low reset always named `rst_n`.

### 2.3 Constants
- Always sized:
```verilog
o_data <= 8'd255; // ✅
o_data <= 255;    // ❌
```

### 2.4 Assignments
- **Sequential** (`always @(posedge clk)`) → non-blocking (`<=`)
- **Combinational** (`always @*`) → blocking (`=`)

### 2.5 Reset
- Synchronous or asynchronous reset must be **explicit**.  
- Default: synchronous, active-low.

```verilog
always @(posedge clk) begin
    if (!rst_n)
        r_state <= 2'd0;
    else
        r_state <= next_state;
end
```

### 2.6 FSMs
- Use `localparam` for state encoding.
- Always include a `default:` branch.

### 2.7 Testbenches
- Allowed to use `$display`, `$monitor`, `$dumpfile`, `$finish`.
- Never mix testbench logic into RTL.

---

## 3. Examples

### Simple Counter
```verilog
`default_nettype none

module counter #(
    parameter WIDTH = 8
)(
    input  wire clk,
    input  wire rst_n,
    output reg  [WIDTH-1:0] o_count
);
    always @(posedge clk) begin
        if (!rst_n)
            o_count <= {WIDTH{1'b0}};
        else
            o_count <= o_count + 1'b1;
    end
endmodule
```

### Testbench
```verilog
module counter_tb;
    reg clk;
    reg rst_n;
    wire [7:0] o_count;

    counter dut (.clk(clk), .rst_n(rst_n), .o_count(o_count));

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        rst_n = 0;
        #20 rst_n = 1;
        #100 $finish;
    end

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, counter_tb);
    end
endmodule
```

---

## 4. Prompt Template (for AI models)

```
You are generating Verilog RTL code.  
Apply the following constraints:
- Add `default_nettype none` at top.  
- Inputs = i_xxx, Outputs = o_xxx.  
- All constants explicitly sized.  
- Sequential logic uses non-blocking (<=).  
- Combinational uses blocking (=).  
- Resets are synchronous, active-low, named rst_n.  
- FSMs use localparam encoding and default case.  
- Code must lint-clean with Verilator using `.verilator.f`.  
- Provide a testbench if requested.
```

---

## 5. Self-Checklist Before Commit
- [ ] Added ``default_nettype none``  
- [ ] No implicit wires  
- [ ] No unsized constants  
- [ ] No inferred latches  
- [ ] Reset is synchronous, active-low, named `rst_n`  
- [ ] Blocking vs non-blocking correct  
- [ ] FSMs: `localparam` + `default` branch  
- [ ] Testbench isolated from RTL  
- [ ] Lint-clean with `make lint`  
- [ ] Waveform verified with `make sim`  

---
