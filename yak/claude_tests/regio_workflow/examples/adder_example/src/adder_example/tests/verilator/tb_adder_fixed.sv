// Fixed Verilator testbench for adder_example
module tb_adder_fixed;

    // Clock and reset
    logic clk = 0;
    logic rstn = 0;

    // Clock generation
    always #5 clk = ~clk; // 100MHz clock
    
    // AXI4-Lite interface instantiation
    axi4l_intf axil_if ();
    
    // Connect clock and reset to interface
    assign axil_if.aclk = clk;
    assign axil_if.aresetn = rstn;

    // DUT instantiation
    adder_example dut (
        .clk(clk),
        .rstn(rstn),
        .axil_if(axil_if)
    );

    // Simple test sequence
    initial begin
        $dumpfile("adder_example.vcd");
        $dumpvars(0, tb_adder_fixed);
        
        // Reset sequence
        rstn = 0;
        repeat(10) @(posedge clk);
        rstn = 1;
        repeat(10) @(posedge clk);
        
        // Simple write to enable register (offset 0x00)
        axil_if.awvalid = 1;
        axil_if.awaddr = 32'h00000000;
        axil_if.awprot = 0;
        axil_if.wvalid = 1;
        axil_if.wdata = 32'h00000001; // Enable = 1
        axil_if.wstrb = 4'hF;
        axil_if.bready = 1;
        
        // Wait for transaction to complete
        @(posedge clk);
        wait(axil_if.awready && axil_if.wready);
        @(posedge clk);
        axil_if.awvalid = 0;
        axil_if.wvalid = 0;
        wait(axil_if.bvalid);
        @(posedge clk);
        axil_if.bready = 0;
        
        // Write operand A (offset 0x04)
        repeat(5) @(posedge clk);
        axil_if.awvalid = 1;
        axil_if.awaddr = 32'h00000004;
        axil_if.wvalid = 1;
        axil_if.wdata = 32'h00000005; // A = 5
        axil_if.bready = 1;
        
        @(posedge clk);
        wait(axil_if.awready && axil_if.wready);
        @(posedge clk);
        axil_if.awvalid = 0;
        axil_if.wvalid = 0;
        wait(axil_if.bvalid);
        @(posedge clk);
        axil_if.bready = 0;
        
        // Write operand B (offset 0x08)
        repeat(5) @(posedge clk);
        axil_if.awvalid = 1;
        axil_if.awaddr = 32'h00000008;
        axil_if.wvalid = 1;
        axil_if.wdata = 32'h00000007; // B = 7
        axil_if.bready = 1;
        
        @(posedge clk);
        wait(axil_if.awready && axil_if.wready);
        @(posedge clk);
        axil_if.awvalid = 0;
        axil_if.wvalid = 0;
        wait(axil_if.bvalid);
        @(posedge clk);
        axil_if.bready = 0;
        
        // Wait for computation
        repeat(10) @(posedge clk);
        
        // Read result (offset 0x0C)
        axil_if.arvalid = 1;
        axil_if.araddr = 32'h0000000C;
        axil_if.arprot = 0;
        axil_if.rready = 1;
        
        @(posedge clk);
        wait(axil_if.arready);
        @(posedge clk);
        axil_if.arvalid = 0;
        wait(axil_if.rvalid);
        
        // Check result
        if (axil_if.rdata == 32'h0000000C) begin // 5 + 7 = 12
            $display("✓ TEST PASSED: 5 + 7 = %d", axil_if.rdata);
        end else begin
            $display("✗ TEST FAILED: Expected 12, got %d", axil_if.rdata);
        end
        
        @(posedge clk);
        axil_if.rready = 0;
        
        // End simulation
        repeat(20) @(posedge clk);
        $display("Simulation completed");
        $finish;
    end

endmodule
