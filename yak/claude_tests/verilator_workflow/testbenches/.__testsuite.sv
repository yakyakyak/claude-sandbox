module __testsuite;
  import svunit_pkg::svunit_testsuite;

  string name = "__ts";
  svunit_testsuite svunit_ts;
  
  
  //===================================
  // These are the unit tests that we
  // want included in this testsuite
  //===================================
  alu_unit_test alu_ut();


  //===================================
  // Build
  //===================================
  function void build();
    alu_ut.build();
    alu_ut.__register_tests();
    svunit_ts = new(name);
    svunit_ts.add_testcase(alu_ut.svunit_ut);
  endfunction


  //===================================
  // Run
  //===================================
  task run();
    svunit_ts.run();
    alu_ut.run();
    svunit_ts.report();
  endtask

endmodule
