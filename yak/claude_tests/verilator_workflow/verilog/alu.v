module alu #(
    parameter DATA_WIDTH = 32
) (
    input  wire [DATA_WIDTH-1:0] a,
    input  wire [DATA_WIDTH-1:0] b,
    input  wire [3:0]            op,
    output reg  [DATA_WIDTH-1:0] result,
    output wire                  zero,
    output wire                  overflow,
    output wire                  carry_out
);

  localparam ADD  = 4'b0000;
  localparam SUB  = 4'b0001;
  localparam AND  = 4'b0010;
  localparam OR   = 4'b0011;
  localparam XOR  = 4'b0100;
  localparam SLL  = 4'b0101;  // Shift left logical
  localparam SRL  = 4'b0110;  // Shift right logical
  localparam SRA  = 4'b0111;  // Shift right arithmetic
  localparam SLT  = 4'b1000;  // Set less than
  localparam SLTU = 4'b1001;  // Set less than unsigned
  localparam NOR  = 4'b1010;
  localparam NAND = 4'b1011;

  reg [DATA_WIDTH:0] temp_result;
  wire signed [DATA_WIDTH-1:0] a_signed = a;
  wire signed [DATA_WIDTH-1:0] b_signed = b;

  always @(*) begin
    temp_result = 0;
    result = 0;  // Default assignment
    case (op)
      ADD: begin
        temp_result = a + b;
        result = temp_result[DATA_WIDTH-1:0];
      end
      SUB: begin
        temp_result = a - b;
        result = temp_result[DATA_WIDTH-1:0];
      end
      AND:  result = a & b;
      OR:   result = a | b;
      XOR:  result = a ^ b;
      SLL:  result = a << b[4:0];  // Use only 5 bits for shift amount
      SRL:  result = a >> b[4:0];
      SRA:  result = a_signed >>> b[4:0];
      SLT:  result = (a_signed < b_signed) ? 1 : 0;
      SLTU: result = (a < b) ? 1 : 0;
      NOR:  result = ~(a | b);
      NAND: result = ~(a & b);
      default: result = 0;
    endcase
  end

  assign zero = (result == 0);
  assign carry_out = (op == ADD || op == SUB) ? temp_result[DATA_WIDTH] : 1'b0;
  
  // Overflow detection for addition and subtraction
  assign overflow = (op == ADD) ? ((a[DATA_WIDTH-1] == b[DATA_WIDTH-1]) && 
                                   (result[DATA_WIDTH-1] != a[DATA_WIDTH-1])) :
                    (op == SUB) ? ((a[DATA_WIDTH-1] != b[DATA_WIDTH-1]) && 
                                   (result[DATA_WIDTH-1] != a[DATA_WIDTH-1])) : 1'b0;

endmodule
