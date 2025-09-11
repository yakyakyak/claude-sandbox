#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "obj_dir/Vtb_functional_fixed.h"

// Required by Verilator
double sc_time_stamp() {
    return 0;  // Not using SystemC
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    // Create testbench instance
    Vtb_functional_fixed* tb = new Vtb_functional_fixed;
    
    // Initialize waveform tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* trace = new VerilatedVcdC;
    tb->trace(trace, 99);
    trace->open("adder_functional.vcd");
    
    // Run simulation until $finish
    uint64_t sim_time = 0;
    while (sim_time < 50000 && !Verilated::gotFinish()) {
        tb->eval();
        trace->dump(sim_time);
        sim_time++;
    }
    
    // Clean up
    trace->close();
    delete trace;
    delete tb;
    
    std::cout << "Functional simulation completed!" << std::endl;
    return 0;
}