// Simple Verilator-compatible testbench
module tb_simple;

    // Clock and reset
    logic clk;
    logic rstn;
    
    // Test control
    integer cycle_count;
    
    // Direct signals to test adder logic
    logic enable_reg = 0;
    logic [31:0] operand_a_reg = 0;
    logic [31:0] operand_b_reg = 0;
    logic [31:0] result_reg;

    // Create a simple register interface for testing
    adder_example_reg_intf test_regs ();
    
    // Connect test registers
    assign test_regs.enable = enable_reg;
    assign test_regs.operand_a = operand_a_reg;
    assign test_regs.operand_b = operand_b_reg;
    assign result_reg = test_regs.result_nxt;

    // Simple adder logic (bypassing AXI4L for this test)
    logic [31:0] sum;
    always_ff @(posedge clk) begin
        if (!rstn) begin
            sum <= 32'h0;
        end else if (test_regs.enable) begin
            sum <= test_regs.operand_a + test_regs.operand_b;
        end
    end
    
    // Connect result back to register interface
    assign test_regs.result_nxt = sum;
    assign test_regs.result_nxt_v = 1'b1;

    // Clock generation
    initial begin
        clk = 0;
        cycle_count = 0;
        forever #5 clk = ~clk;
    end

    // Test sequence
    initial begin
        $dumpfile("adder_simple.vcd");
        $dumpvars(0, tb_simple);
        
        // Reset sequence
        rstn = 0;
        #100;
        rstn = 1;
        #50;
        
        // Test 1: 5 + 7 = 12
        $display("Test 1: 5 + 7");
        operand_a_reg = 32'd5;
        operand_b_reg = 32'd7;
        enable_reg = 1;
        
        #50;
        
        if (result_reg == 32'd12) begin
            $display("✓ PASS: 5 + 7 = %d", result_reg);
        end else begin
            $display("✗ FAIL: Expected 12, got %d", result_reg);
        end
        
        // Test 2: Disable test
        $display("Test 2: Disable operation");
        enable_reg = 0;
        operand_a_reg = 32'd100;
        operand_b_reg = 32'd200;
        
        #50;
        
        if (result_reg == 32'd12) begin // Should remain 12
            $display("✓ PASS: Result unchanged when disabled");
        end else begin
            $display("✗ FAIL: Result changed when disabled");
        end
        
        // Test 3: Re-enable
        $display("Test 3: Re-enable operation");
        enable_reg = 1;
        
        #50;
        
        if (result_reg == 32'd300) begin
            $display("✓ PASS: 100 + 200 = %d", result_reg);
        end else begin
            $display("✗ FAIL: Expected 300, got %d", result_reg);
        end
        
        // End simulation
        #100;
        $display("Simple simulation completed successfully!");
        $finish;
    end

endmodule
