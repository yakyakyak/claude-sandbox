module openai_alu_tb;

    logic [31:0] a, b, result;
    logic [3:0] op;
    logic zero, overflow, carry;

    openai_alu dut (
        .a(a),
        .b(b),
        .op(op),
        .result(result),
        .zero(zero),
        .overflow(overflow),
        .carry(carry)
    );

    initial begin
        $display("Starting ALU Testbench...");

        // Test addition
        a = 32'h10; b = 32'h20; op = 4'b0000;
        #10;
        $display("ADD: %h + %h = %h, Zero: %b, Overflow: %b, Carry: %b", a, b, result, zero, overflow, carry);

        // Test subtraction
        a = 32'h20; b = 32'h10; op = 4'b0001;
        #10;
        $display("SUB: %h - %h = %h, Zero: %b, Overflow: %b, Carry: %b", a, b, result, zero, overflow, carry);

        // Add more tests as needed

        $finish;
    end

endmodule
