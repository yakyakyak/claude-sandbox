#include "Vmy_module_tb.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vmy_module_tb* top = new Vmy_module_tb;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("dump.vcd");

    for (int sim_time = 0; sim_time < 200; sim_time++) {
        top->clk = (sim_time & 1);
        top->eval();
        tfp->dump(sim_time);
    }

    tfp->close();
    delete top;
    return 0;
}
