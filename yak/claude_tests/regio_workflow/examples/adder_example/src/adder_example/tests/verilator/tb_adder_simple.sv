// Simple Verilator testbench for adder_example with regio interface
module tb_adder_simple;

    // Clock and reset
    logic clk = 0;
    logic rstn = 0;
    
    // AXI4-Lite interface signals
    logic         axil_awvalid = 0;
    logic         axil_awready;
    logic [31:0]  axil_awaddr = 0;
    logic [2:0]   axil_awprot = 0;
    
    logic         axil_wvalid = 0;
    logic         axil_wready;
    logic [31:0]  axil_wdata = 0;
    logic [3:0]   axil_wstrb = 0;
    
    logic         axil_bvalid;
    logic         axil_bready = 0;
    logic [1:0]   axil_bresp;
    
    logic         axil_arvalid = 0;
    logic         axil_arready;
    logic [31:0]  axil_araddr = 0;
    logic [2:0]   axil_arprot = 0;
    
    logic         axil_rvalid;
    logic         axil_rready = 0;
    logic [31:0]  axil_rdata;
    logic [1:0]   axil_rresp;

    // Clock generation
    always #5 clk = ~clk; // 100MHz clock
    
    // AXI4-Lite interface instantiation
    axi4l_intf axil_if (
        .aclk(clk),
        .aresetn(rstn)
    );
    
    // Connect interface signals
    assign axil_if.awvalid = axil_awvalid;
    assign axil_awready = axil_if.awready;
    assign axil_if.awaddr = axil_awaddr;
    assign axil_if.awprot = axil_awprot;
    
    assign axil_if.wvalid = axil_wvalid;
    assign axil_wready = axil_if.wready;
    assign axil_if.wdata = axil_wdata;
    assign axil_if.wstrb = axil_wstrb;
    
    assign axil_bvalid = axil_if.bvalid;
    assign axil_if.bready = axil_bready;
    assign axil_bresp = axil_if.bresp;
    
    assign axil_if.arvalid = axil_arvalid;
    assign axil_arready = axil_if.arready;
    assign axil_if.araddr = axil_araddr;
    assign axil_if.arprot = axil_arprot;
    
    assign axil_rvalid = axil_if.rvalid;
    assign axil_if.rready = axil_rready;
    assign axil_rdata = axil_if.rdata;
    assign axil_rresp = axil_if.rresp;

    // DUT instantiation
    adder_example dut (
        .clk(clk),
        .rstn(rstn),
        .axil_if(axil_if)
    );

    // Simple test sequence
    initial begin
        $dumpfile("adder_example.vcd");
        $dumpvars(0, tb_adder_simple);
        
        // Reset
        rstn = 0;
        #100;
        rstn = 1;
        #100;
        
        $display("Test completed");
        $finish;
    end

endmodule