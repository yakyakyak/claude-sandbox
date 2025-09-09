`include "svunit_defines.svh"
`include "../verilog/alu.v"

module alu_unit_test;
  import svunit_pkg::svunit_testcase;

  string name = "alu_ut";
  svunit_testcase svunit_ut;


  //===================================
  // This is the UUT that we're 
  // running the Unit Tests on
  //===================================
  parameter DATA_WIDTH = 32;
  
  // ALU operation codes
  localparam ADD  = 4'b0000;
  localparam SUB  = 4'b0001;
  localparam AND  = 4'b0010;
  localparam OR   = 4'b0011;
  localparam XOR  = 4'b0100;
  localparam SLL  = 4'b0101;
  localparam SRL  = 4'b0110;
  localparam SRA  = 4'b0111;
  localparam SLT  = 4'b1000;
  localparam SLTU = 4'b1001;
  localparam NOR  = 4'b1010;
  localparam NAND = 4'b1011;

  // ALU interface signals
  logic [DATA_WIDTH-1:0] a;
  logic [DATA_WIDTH-1:0] b;
  logic [3:0] op;
  logic [DATA_WIDTH-1:0] result;
  logic zero;
  logic overflow;
  logic carry_out;

  alu #(.DATA_WIDTH(DATA_WIDTH)) my_alu(
    .a(a),
    .b(b),
    .op(op),
    .result(result),
    .zero(zero),
    .overflow(overflow),
    .carry_out(carry_out)
  );


  //===================================
  // Build
  //===================================
  function void build();
    svunit_ut = new(name);
    
    // Generate VCD file for waveform analysis
    $dumpfile("alu_test.vcd");
    $dumpvars(0, alu_unit_test);
    $dumpvars(1, my_alu);
  endfunction


  //===================================
  // Setup for running the Unit Tests
  //===================================
  task setup();
    svunit_ut.setup();
    // Note: SVUnit calls setup before each test
    // We should NOT initialize inputs here as they get reset
    $display("DEBUG SETUP: Called for each test");
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

  // Test ADD operations
  `SVTEST(test_add_basic)
    a = 32'h10;
    b = 32'h20;
    op = ADD;
    #1;
    $display("DEBUG: test_add_basic - a=%h, b=%h, op=%h, result=%h, expected=%h", a, b, op, result, 32'h30);
    `FAIL_UNLESS_EQUAL(result, 32'h30);
    `FAIL_UNLESS_EQUAL(zero, 1'b0);
    `FAIL_UNLESS_EQUAL(overflow, 1'b0);
    `FAIL_UNLESS_EQUAL(carry_out, 1'b0);
  `SVTEST_END

  `SVTEST(test_add_overflow)
    a = 32'h7FFFFFFF; // Max positive signed
    b = 32'h00000001;
    op = ADD;
    #1;
    `FAIL_UNLESS_EQUAL(result, 32'h80000000);
    `FAIL_UNLESS_EQUAL(zero, 1'b0);
    `FAIL_UNLESS_EQUAL(overflow, 1'b1);
    `FAIL_UNLESS_EQUAL(carry_out, 1'b0);
  `SVTEST_END

  `SVTEST(test_add_carry)
    a = 32'hFFFFFFFF;
    b = 32'h00000001;
    op = ADD;
    #1;
    `FAIL_UNLESS_EQUAL(result, 32'h00000000);
    `FAIL_UNLESS_EQUAL(zero, 1'b1);
    `FAIL_UNLESS_EQUAL(overflow, 1'b0);
    `FAIL_UNLESS_EQUAL(carry_out, 1'b1);
  `SVTEST_END

  // Test SUB operations
  `SVTEST(test_sub_basic)
    a = 32'h30;
    b = 32'h10;
    op = SUB;
    #1;
    `FAIL_UNLESS_EQUAL(result, 32'h20);
    `FAIL_UNLESS_EQUAL(zero, 1'b0);
    `FAIL_UNLESS_EQUAL(overflow, 1'b0);
  `SVTEST_END

  `SVTEST(test_sub_zero)
    a = 32'h15;
    b = 32'h15;
    op = SUB;
    #1;
    `FAIL_UNLESS_EQUAL(result, 32'h00000000);
    `FAIL_UNLESS_EQUAL(zero, 1'b1);
    `FAIL_UNLESS_EQUAL(overflow, 1'b0);
  `SVTEST_END

  // Test logical operations
  `SVTEST(test_and)
    a = 32'hF0F0F0F0;
    b = 32'h0F0F0F0F;
    op = AND;
    #1;
    `FAIL_UNLESS_EQUAL(result, 32'h00000000);
    `FAIL_UNLESS_EQUAL(zero, 1'b1);
  `SVTEST_END

  `SVTEST(test_or)
    a = 32'hF0F0F0F0;
    b = 32'h0F0F0F0F;
    op = OR;
    #1;
    `FAIL_UNLESS_EQUAL(result, 32'hFFFFFFFF);
    `FAIL_UNLESS_EQUAL(zero, 1'b0);
  `SVTEST_END

  `SVTEST(test_xor)
    a = 32'hF0F0F0F0;
    b = 32'hF0F0F0F0;
    op = XOR;
    #1;
    `FAIL_UNLESS_EQUAL(result, 32'h00000000);
    `FAIL_UNLESS_EQUAL(zero, 1'b1);
  `SVTEST_END

  // Test shift operations
  `SVTEST(test_sll)
    a = 32'h00000001;
    b = 32'h00000004; // Shift left by 4
    op = SLL;
    #1;
    $display("DEBUG: test_sll - a=%h, b=%h, op=%h, result=%h, expected=%h", a, b, op, result, 32'h00000010);
    $display("DEBUG: test_sll - b[4:0]=%h, zero=%b", b[4:0], zero);
    `FAIL_UNLESS_EQUAL(result, 32'h00000010);
    `FAIL_UNLESS_EQUAL(zero, 1'b0);
  `SVTEST_END

  `SVTEST(test_srl)
    a = 32'h80000000;
    b = 32'h00000004; // Shift right logical by 4
    op = SRL;
    #1;
    `FAIL_UNLESS_EQUAL(result, 32'h08000000);
    `FAIL_UNLESS_EQUAL(zero, 1'b0);
  `SVTEST_END

  // Test comparison operations
  `SVTEST(test_slt_true)
    a = 32'h10;
    b = 32'h20;
    op = SLT;
    #1;
    `FAIL_UNLESS_EQUAL(result, 32'h00000001);
    `FAIL_UNLESS_EQUAL(zero, 1'b0);
  `SVTEST_END

  `SVTEST(test_slt_false)
    a = 32'h20;
    b = 32'h10;
    op = SLT;
    #1;
    `FAIL_UNLESS_EQUAL(result, 32'h00000000);
    `FAIL_UNLESS_EQUAL(zero, 1'b1);
  `SVTEST_END

  `SVUNIT_TESTS_END

endmodule
