//=============================================================================
// File: alu_testrunner.sv
// Description: SVUnit test runner for ALU unit tests
// Author: Claude Code
// Date: 2025-09-09
//=============================================================================

`include "svunit_defines.svh"

import svunit_pkg::*;

module alu_testrunner;

  string name = "alu_testrunner";
  svunit_testrunner svunit_tr;

  alu_unit_test alu_ut();

  function void build();
    alu_ut.build();
    svunit_tr = new(name);
    svunit_tr.add_testcase(alu_ut.svunit_ut);
  endfunction

  task run();
    svunit_tr.run();
  endtask

endmodule