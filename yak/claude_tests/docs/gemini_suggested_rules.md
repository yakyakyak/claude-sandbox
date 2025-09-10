# Verilog Coding Guidelines for Synthesis & Verification

This document outlines a set of best practices and rules for writing synthesizable Verilog code and robust testbenches. Following these guidelines will lead to more predictable synthesis results, fewer bugs, and more readable, maintainable code. 🧠

---

## I. General Rules & Naming Conventions

These rules apply to all Verilog files for consistency and readability.

* **File Naming**: Name files after the module they contain: `module_name.v`.
* **One Module Per File**: Each file should contain only one module definition.
* **Header**: Start every file with a comment block detailing the author, date, module description, and modification history.
* **Signal Naming**: Use `snake_case` for all signal and variable names (e.g., `data_bus`, `write_enable`).
* **Constants & Parameters**: Use `UPPER_CASE` for parameters and localparams to distinguish them from signals.
* **Clock Signals**: Name clocks clearly, like `clk` or `core_clk`.
* **Reset Signals**: Indicate active-low signals with `_n` (e.g., `rst_n`, `reset_n`).
* **I/O Ports**: Prefix inputs with `i_`, outputs with `o_`, and inouts with `io_`.
    * *Example*: `input i_data`, `output o_valid`
* **State Machines**: Suffix state registers with `_q` for the current state and `_d` for the next state (e.g., `state_q`, `state_d`).

---

## II. Rules for Synthesizable Code

These rules are critical for ensuring your RTL is correctly interpreted by synthesis tools to produce efficient hardware.

### Clocking and Reset

1.  **Synchronous Design**: Design your logic to be fully synchronous. All flip-flops should be driven by a single clock domain, unless you are intentionally creating a clock domain crossing (CDC) circuit.
2.  **Use Synchronous Resets**: **Prefer synchronous resets** over asynchronous ones. They are less susceptible to timing issues when the reset signal is de-asserted. If an asynchronous reset is required, ensure you use a reset synchronizer for its de-assertion.
    ```verilog
    // Good: Synchronous Reset Flip-Flop
    always @(posedge clk) begin
      if (!rst_n) begin // Active-low synchronous reset
        data_q <= 1'b0;
      end else begin
        data_q <= data_d;
      end
    end
    ```

### Combinational Logic (`always @(*)`)

1.  **Use `always @(*)`**: Always use the implicit sensitivity list `always @(*)` (or `always_comb` in SystemVerilog) for combinational logic. This prevents accidentally omitting a signal from the sensitivity list.
2.  **Use Blocking Assignments (`=`)**: Inside a combinational `always` block, **use blocking assignments**. This models the immediate-propogation nature of combinational logic.
3.  **Avoid Inferring Latches**: This is a common and serious mistake. A latch is inferred if a signal is not assigned a value in every possible branch of an `if` or `case` statement.
    * **Rule**: Ensure every output of a combinational block is **always assigned a value**, either within a branch or with a default value at the top of the block.

    ```verilog
    // ❌ Bad: Infers a latch for `o_data` when `i_enable` is low
    always @(*) begin
      if (i_enable) begin
        o_data = i_data;
      end
      // What happens to o_data when i_enable is 0? Latch!
    end

    // ✅ Good: Default assignment prevents a latch
    always @(*) begin
      o_data = 1'b0; // Default value
      if (i_enable) begin
        o_data = i_data;
      end
    end
    ```

### Sequential Logic (`always @(posedge clk)`)

1.  **Use Non-Blocking Assignments (`<=`)**: Inside a sequential `always` block (clocked), **always use non-blocking assignments**. This correctly models the behavior of flip-flops, where all registers sample their inputs at the clock edge and update their outputs simultaneously.
2.  **Separate Logic**: Do not mix combinational and sequential logic in the same `always` block. It's better to calculate the "next-state" logic in a combinational block and perform the register update in a sequential block. This is the foundation of a robust state machine.

    ```verilog
    // ✅ Good: Two-process state machine and logic
    reg [7:0] counter_q, counter_d;

    // Process 1: Combinational logic for next state
    always @(*) begin
      counter_d = counter_q; // Default: hold value
      if (i_increment) begin
        counter_d = counter_q + 1;
      end
    end

    // Process 2: Sequential logic for register update
    always @(posedge clk) begin
      if (!rst_n) begin
        counter_q <= 8'h00;
      end else begin
        counter_q <= counter_d;
      end
    end
    ```

### Constructs to Avoid in Synthesis

* **`#delays`**: Synthesis tools ignore timing delays like `#10`. They are for simulation only.
* **`initial` blocks**: Do not use `initial` blocks for synthesizable logic. They are primarily for testbenches.
* **`for` loops**: Use `for` loops with caution. The loop bounds must be constant and known at compile time so the tool can unroll the loop into parallel hardware.
* **System Tasks**: `$display`, `$monitor`, `$finish` are not synthesizable.

---

## III. Rules for Testbenches

Testbenches are for simulation only and do not need to be synthesizable. The goal is to create robust, readable, and self-checking tests.

1.  **Clear Structure**: Organize your testbench into distinct sections:
    * Parameter and signal declarations (`reg` for DUT inputs, `wire` for DUT outputs).
    * DUT (Device Under Test) instantiation.
    * Clock and reset generation.
    * Stimulus generation.
    * Response checking and monitoring.
2.  **Clock Generation**: Use an `always` block to generate a periodic clock signal.
    ```verilog
    parameter CLK_PERIOD = 10; // In ns

    initial clk = 0;
    always #(CLK_PERIOD/2) clk = ~clk;
    ```
3.  **Stimulus**: Use an `initial` block to define the sequence of test vectors. Use delays (`#`) to control the timing of input changes relative to the clock.
4.  **Self-Checking**: Don't rely on manually reading waveforms! A good testbench checks the DUT's outputs and reports errors. This is crucial for automation.
    ```verilog
    // Example of a self-checking test
    initial begin
      // ... apply some stimulus ...
      #10; // Wait for output to be valid
      if (o_dut_result !== expected_result) begin
        $display("ERROR: Test failed at time %0t", $time);
        $display("Expected: %h, Got: %h", expected_result, o_dut_result);
        $finish;
      end
    end
    ```
5.  **Use Tasks**: Encapsulate common sequences of operations (like an AXI transaction or applying a specific input) into **tasks**. This makes your testbench much cleaner and more reusable.
    ```verilog
    task write_register;
      input [31:0] address;
      input [31:0] data;
      begin
        @(posedge clk);
        i_addr  = address;
        i_wdata = data;
        i_we    = 1'b1;
        @(posedge clk);
        i_we    = 1'b0;
      end
    endtask
    ```
6.  **Simulation Control**: Use `$display` and `$monitor` to print information to the console. End the simulation with `$finish` once all tests are complete.
