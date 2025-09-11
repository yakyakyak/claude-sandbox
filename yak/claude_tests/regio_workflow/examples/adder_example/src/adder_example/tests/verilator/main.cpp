#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "obj_dir/Vtb_simple.h"

// Required by Verilator
double sc_time_stamp() {
    return 0;  // Not using SystemC
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    // Create testbench instance
    Vtb_simple* tb = new Vtb_simple;
    
    // Initialize waveform tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* trace = new VerilatedVcdC;
    tb->trace(trace, 99);
    trace->open("adder_simple.vcd");
    
    // Run simulation
    uint64_t sim_time = 0;
    
    // Run for enough time to complete the test
    while (sim_time < 10000 && !Verilated::gotFinish()) {
        tb->eval();
        trace->dump(sim_time);
        sim_time++;
    }
    
    // Clean up
    trace->close();
    delete trace;
    delete tb;
    
    std::cout << "Simulation completed!" << std::endl;
    return 0;
}