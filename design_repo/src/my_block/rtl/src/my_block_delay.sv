module my_block_delay #(
    parameter int WID = 32,
    parameter int DELAY = 8
) (
    input  logic           clk,
    input  logic           srst = 1'b0,

    input  logic           valid_in,
    input  logic [WID-1:0] data_in,
    
    output logic           valid_out,
    output logic [WID-1:0] data_out
);

    util_delay    #(
        .DATA_WID  ( 1 ),
        .DELAY     ( DELAY ),
        .RESET_VAL ( 1'b0 )
    ) i_util_delay__valid (
        .clk,
        .srst,
        .data_in  ( valid_in ),
        .data_out ( valid_out )
    );

    util_delay   #(
        .DATA_WID ( WID ),
        .DELAY    ( DELAY )
    ) i_util_delay__data (
        .clk,
        .srst ( 1'b0 ),
        .data_in,
        .data_out
    );

endmodule : my_block_delay
