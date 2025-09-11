// Functional testbench for Verilator
module tb_functional;

    // Clock and reset
    logic clk;
    logic rstn;
    
    // Test signals
    logic enable_reg;
    logic [31:0] operand_a_reg;
    logic [31:0] operand_b_reg;
    logic [31:0] result_reg;

    // Create register interface
    adder_example_reg_intf test_regs ();
    
    // Connect test registers
    assign test_regs.enable = enable_reg;
    assign test_regs.operand_a = operand_a_reg;
    assign test_regs.operand_b = operand_b_reg;
    assign result_reg = test_regs.result_nxt;

    // Simple adder logic
    logic [31:0] sum;
    always_ff @(posedge clk) begin
        if (!rstn) begin
            sum <= 32'h0;
        end else if (test_regs.enable) begin
            sum <= test_regs.operand_a + test_regs.operand_b;
        end
    end
    
    // Connect result
    assign test_regs.result_nxt = sum;
    assign test_regs.result_nxt_v = 1'b1;

    // Test control
    initial begin
        $dumpfile("adder_functional.vcd");
        $dumpvars(0, tb_functional);
        
        // Initialize
        clk = 0;
        rstn = 0;
        enable_reg = 0;
        operand_a_reg = 0;
        operand_b_reg = 0;
        
        // Clock and test sequence
        repeat(5) begin
            #5 clk = 1; #5 clk = 0;  // Reset phase
        end
        
        rstn = 1;
        repeat(2) begin
            #5 clk = 1; #5 clk = 0;  // Wait after reset
        end
        
        // Test 1: 5 + 7 = 12
        operand_a_reg = 32'd5;
        operand_b_reg = 32'd7;
        enable_reg = 1;
        
        repeat(3) begin
            #5 clk = 1; #5 clk = 0;  // Clock cycles for computation
        end
        
        // Test 2: 100 + 200 = 300
        operand_a_reg = 32'd100;
        operand_b_reg = 32'd200;
        
        repeat(3) begin
            #5 clk = 1; #5 clk = 0;
        end
        
        // Test 3: Disable test
        enable_reg = 0;
        operand_a_reg = 32'd999;
        operand_b_reg = 32'd999;
        
        repeat(3) begin
            #5 clk = 1; #5 clk = 0;
        end
        
        // Final clocks
        repeat(5) begin
            #5 clk = 1; #5 clk = 0;
        end
        
        $finish;
    end

endmodule