`include "svunit_defines.svh"

module my_block_delay_unit_test;
    import svunit_pkg::svunit_testcase;

    string name = "my_block_delay_ut";
    svunit_testcase svunit_ut;

    localparam int WID = 32;
    localparam int DELAY = 8;

    //===================================
    // This is the UUT that we're 
    // running the Unit Tests on
    //===================================
    logic           clk;
    logic           srst;
    logic           valid_in;
    logic [WID-1:0] data_in;
    logic           valid_out;
    logic [WID-1:0] data_out;

    my_block_delay#(.WID(WID), .DELAY(DELAY)) DUT (.*);

    `SVUNIT_CLK_GEN(clk, 5ns);

    //===================================
    // Build
    //===================================
    function void build();
        svunit_ut = new(name);
    endfunction


    //===================================
    // Setup for running the Unit Tests
    //===================================
    task setup();
        svunit_ut.setup();
        /* Place Setup Code Here */
        valid_in <= 1'b0;
        srst <= 1'b1;
        repeat(8) @(posedge clk);
        srst <= 1'b0;

    endtask


    //===================================
    // Here we deconstruct anything we 
    // need after running the Unit Tests
    //===================================
    task teardown();
      svunit_ut.teardown();
      /* Place Teardown Code Here */

    endtask


    //===================================
    // All tests are defined between the
    // SVUNIT_TESTS_BEGIN/END macros
    //
    // Each individual test must be
    // defined between `SVTEST(_NAME_)
    // `SVTEST_END
    //
    // i.e.
    //   `SVTEST(mytest)
    //     <test code>
    //   `SVTEST_END
    //===================================
    `SVUNIT_TESTS_BEGIN

    `SVTEST(reset)
        `FAIL_IF(valid_out);
    `SVTEST_END

    `SVTEST(sanity)
        int delay = 0;
        @(posedge clk);
        valid_in <= 1'b1;
        data_in <= $urandom();
        do begin
            @(posedge clk);
            `FAIL_IF(delay > DELAY);
            delay++;
        end while (!valid_out);
        `FAIL_UNLESS_EQUAL(data_out, data_in);
    `SVTEST_END

    `SVUNIT_TESTS_END

endmodule
