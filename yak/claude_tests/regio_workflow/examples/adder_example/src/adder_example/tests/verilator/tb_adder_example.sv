// Verilator testbench for adder_example with regio interface
module tb_adder_example;

    // Clock and reset
    logic clk = 0;
    logic rstn = 0;
    
    // AXI4-Lite interface signals
    logic         axil_awvalid;
    logic         axil_awready;
    logic [31:0]  axil_awaddr;
    logic [2:0]   axil_awprot;
    
    logic         axil_wvalid;
    logic         axil_wready;
    logic [31:0]  axil_wdata;
    logic [3:0]   axil_wstrb;
    
    logic         axil_bvalid;
    logic         axil_bready;
    logic [1:0]   axil_bresp;
    
    logic         axil_arvalid;
    logic         axil_arready;
    logic [31:0]  axil_araddr;
    logic [2:0]   axil_arprot;
    
    logic         axil_rvalid;
    logic         axil_rready;
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

    // Test tasks accessible from C++
    export "DPI-C" task axi_write;
    export "DPI-C" task axi_read;
    export "DPI-C" task reset_dut;
    export "DPI-C" task wait_cycles;

    // Reset task
    task reset_dut(input int cycles);
        rstn = 0;
        repeat(cycles) @(posedge clk);
        rstn = 1;
        repeat(10) @(posedge clk);
    endtask

    // Wait cycles task
    task wait_cycles(input int cycles);
        repeat(cycles) @(posedge clk);
    endtask

    // AXI write task
    task axi_write(input int addr, input int data);
        @(posedge clk);
        
        // Address phase
        axil_awvalid = 1;
        axil_awaddr = addr;
        axil_awprot = 0;
        
        // Data phase
        axil_wvalid = 1;
        axil_wdata = data;
        axil_wstrb = 4'hF;
        
        axil_bready = 1;
        
        // Wait for address ready
        while (!axil_awready) @(posedge clk);
        @(posedge clk);
        axil_awvalid = 0;
        
        // Wait for data ready
        while (!axil_wready) @(posedge clk);
        @(posedge clk);
        axil_wvalid = 0;
        
        // Wait for response
        while (!axil_bvalid) @(posedge clk);
        @(posedge clk);
        axil_bready = 0;
    endtask

    // AXI read task
    task axi_read(input int addr, output int data);
        @(posedge clk);
        
        // Address phase
        axil_arvalid = 1;
        axil_araddr = addr;
        axil_arprot = 0;
        axil_rready = 1;
        
        // Wait for address ready
        while (!axil_arready) @(posedge clk);
        @(posedge clk);
        axil_arvalid = 0;
        
        // Wait for data ready
        while (!axil_rvalid) @(posedge clk);
        data = axil_rdata;
        @(posedge clk);
        axil_rready = 0;
    endtask

endmodule
