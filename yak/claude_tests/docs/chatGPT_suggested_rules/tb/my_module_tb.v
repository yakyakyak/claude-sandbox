module my_module_tb;
    reg clk;
    reg rst_n;
    reg [7:0] i_data;
    wire [7:0] o_data;

    my_module dut (
        .clk(clk),
        .rst_n(rst_n),
        .i_data(i_data),
        .o_data(o_data)
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        rst_n = 0;
        i_data = 0;
        #20 rst_n = 1;
        #20 i_data = 8'hAA;
        #20 i_data = 8'h55;
        #40 $finish;
    end

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, my_module_tb);
    end
endmodule
