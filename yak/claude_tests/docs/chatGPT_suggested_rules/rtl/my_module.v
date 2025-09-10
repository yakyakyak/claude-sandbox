module my_module (
    input  wire clk,
    input  wire rst_n,
    input  wire [7:0] i_data,
    output reg  [7:0] o_data
);
    always @(posedge clk) begin
        if (!rst_n)
            o_data <= 8'd0;
        else
            o_data <= i_data;
    end
endmodule
