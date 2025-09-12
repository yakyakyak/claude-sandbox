module my_block_inv #(
    parameter int WID = 32
) (
    input  logic           clk,
    input  logic           srst = 1'b0,

    input  logic           valid_in,
    input  logic [WID-1:0] data_in,
    
    output logic           valid_out,
    output logic [WID-1:0] data_out
);
    initial valid_out = 1'b0;
    always @(posedge clk) begin
        if (srst) valid_out <= '0;
        else      valid_out <= valid_in;
    end

    always_ff @(posedge clk) data_out <= ~data_in;

endmodule : my_block_inv
