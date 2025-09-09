module openai_alu (
    input logic [31:0] a,
    input logic [31:0] b,
    input logic [3:0] op,
    output logic [31:0] result,
    output logic zero,
    output logic overflow,
    output logic carry
);

    always_comb begin
        case (op)
            4'b0000: {carry, result} = a + b; // Addition
            4'b0001: {carry, result} = a - b; // Subtraction
            // Add more operations as needed
            default: result = 32'b0;
        endcase

        zero = (result == 32'b0);
        overflow = (op == 4'b0000) ? ((a[31] == b[31]) && (result[31] != a[31])) : 1'b0;
    end

endmodule
