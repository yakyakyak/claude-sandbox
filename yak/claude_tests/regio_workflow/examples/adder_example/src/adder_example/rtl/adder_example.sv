module adder_example #(
) (
    input logic           clk,
    input logic           rstn,

    axi4l_intf.peripheral axil_if
);

    // ----------------------------------------------------------------
    //  Register map block instantiations
    // ----------------------------------------------------------------
    adder_example_reg_intf  adder_regs ();

    // adder_example register block
    adder_example_reg_blk adder_example_reg_blk (
        .axil_if    ( axil_if ),
        .reg_blk_if ( adder_regs )
    );

    // ----------------------------------------------------------------
    //  Adder logic
    // ----------------------------------------------------------------
    logic [31:0] sum;

    always_ff @(posedge clk) begin
        if (!rstn) begin
            sum <= 32'h0;
        end else if (adder_regs.enable) begin
            sum <= adder_regs.operand_a + adder_regs.operand_b;
        end
    end

    // Connect result back to register interface
    assign adder_regs.result_nxt = sum;
    assign adder_regs.result_nxt_v = 1'b1;

endmodule: adder_example
