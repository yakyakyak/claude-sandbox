module my_block_fifo #(
    parameter int WID = 32,
    parameter int DEPTH = 16
) (
    input  logic           clk,
    input  logic           srst = 1'b0,

    input  logic           valid_in,
    output logic           ready_in,
    input  logic [WID-1:0] data_in,
    
    output logic           valid_out,
    input  logic           ready_out,
    output logic [WID-1:0] data_out
);

    fifo_ctxt    #( 
        .DATA_T   ( logic[WID-1:0] ),
        .DEPTH    ( DEPTH )
    ) i_fifo_sync (
        .clk,
        .srst,
        .wr_rdy   ( ready_in ),
        .wr       ( valid_in ),
        .wr_data  ( data_in ),
        .rd       ( ready_out ),
        .rd_vld   ( valid_out ),
        .rd_data  ( data_out ),
        .uflow    ( ),
        .oflow    ( )
    );

endmodule : my_block_fifo
