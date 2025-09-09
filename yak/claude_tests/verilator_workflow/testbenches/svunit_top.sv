//=============================================================================
// File: svunit_top.sv
// Description: Top-level module for running SVUnit tests with Verilator
// Author: Claude Code
// Date: 2025-09-09
//=============================================================================

`include "svunit_defines.svh"

module svunit_top;
  import svunit_pkg::*;

  // Instantiate the unit test
  alu_unit_test alu_test();

  // Main test execution
  initial begin
    string name = "svunit_top";
    
    $display("=== Starting SVUnit Tests ===");
    
    // Build and run the test
    alu_test.build();
    alu_test.run();
    
    $display("=== SVUnit Tests Complete ===");
    $finish;
  end

  // Generate VCD for debugging
  initial begin
    $dumpfile("sim/svunit_alu_test.vcd");
    $dumpvars(0, svunit_top);
  end

endmodule