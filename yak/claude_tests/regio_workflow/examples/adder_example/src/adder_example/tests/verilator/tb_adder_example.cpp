#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtb_adder_example.h"
#include "svdpi.h"

// Register offsets from generated package
#define OFFSET_ENABLE    0x00000000
#define OFFSET_OPERAND_A 0x00000004
#define OFFSET_OPERAND_B 0x00000008
#define OFFSET_RESULT    0x0000000C

class AdderTestbench {
private:
    Vtb_adder_example* tb;
    VerilatedVcdC* trace;
    uint64_t sim_time;
    
public:
    AdderTestbench() : sim_time(0) {
        tb = new Vtb_adder_example;
        
        // Initialize waveform tracing
        Verilated::traceEverOn(true);
        trace = new VerilatedVcdC;
        tb->trace(trace, 99);
        trace->open("adder_example.vcd");
        
        // Initialize signals
        tb->clk = 0;
        tb->rstn = 0;
        
        // Initialize AXI4L signals
        tb->axil_awvalid = 0;
        tb->axil_awaddr = 0;
        tb->axil_awprot = 0;
        tb->axil_wvalid = 0;
        tb->axil_wdata = 0;
        tb->axil_wstrb = 0;
        tb->axil_bready = 0;
        tb->axil_arvalid = 0;
        tb->axil_araddr = 0;
        tb->axil_arprot = 0;
        tb->axil_rready = 0;
    }
    
    ~AdderTestbench() {
        trace->close();
        delete trace;
        delete tb;
    }
    
    void reset() {
        std::cout << "Resetting DUT..." << std::endl;
        reset_dut(10);
        std::cout << "Reset complete." << std::endl;
    }
    
    void tick() {
        tb->clk = 0;
        tb->eval();
        trace->dump(sim_time++);
        
        tb->clk = 1;
        tb->eval();
        trace->dump(sim_time++);
    }
    
    void wait_cycles(int cycles) {
        for (int i = 0; i < cycles; i++) {
            tick();
        }
    }
    
    void axi_write(uint32_t addr, uint32_t data) {
        std::cout << "Writing 0x" << std::hex << data << " to address 0x" << addr << std::endl;
        ::axi_write(addr, data);
    }
    
    uint32_t axi_read(uint32_t addr) {
        int data;
        ::axi_read(addr, data);
        std::cout << "Read 0x" << std::hex << data << " from address 0x" << addr << std::endl;
        return data;
    }
    
    void test_adder() {
        std::cout << "\n=== Testing Adder Functionality ===" << std::endl;
        
        // Test case 1: Basic addition
        std::cout << "\nTest 1: 5 + 7 = 12" << std::endl;
        axi_write(OFFSET_OPERAND_A, 5);
        axi_write(OFFSET_OPERAND_B, 7);
        axi_write(OFFSET_ENABLE, 1);
        
        wait_cycles(10); // Allow computation time
        
        uint32_t result = axi_read(OFFSET_RESULT);
        if (result == 12) {
            std::cout << "✓ Test 1 PASSED" << std::endl;
        } else {
            std::cout << "✗ Test 1 FAILED: Expected 12, got " << result << std::endl;
        }
        
        // Test case 2: Large numbers
        std::cout << "\nTest 2: 0x12345678 + 0x87654321 = 0x999999999" << std::endl;
        axi_write(OFFSET_OPERAND_A, 0x12345678);
        axi_write(OFFSET_OPERAND_B, 0x87654321);
        
        wait_cycles(10);
        
        result = axi_read(OFFSET_RESULT);
        uint32_t expected = 0x12345678 + 0x87654321;
        if (result == expected) {
            std::cout << "✓ Test 2 PASSED" << std::endl;
        } else {
            std::cout << "✗ Test 2 FAILED: Expected 0x" << std::hex << expected 
                      << ", got 0x" << result << std::endl;
        }
        
        // Test case 3: Disable operation
        std::cout << "\nTest 3: Testing enable/disable" << std::endl;
        uint32_t old_result = result;
        axi_write(OFFSET_ENABLE, 0); // Disable
        axi_write(OFFSET_OPERAND_A, 100);
        axi_write(OFFSET_OPERAND_B, 200);
        
        wait_cycles(10);
        
        result = axi_read(OFFSET_RESULT);
        if (result == old_result) {
            std::cout << "✓ Test 3 PASSED: Result unchanged when disabled" << std::endl;
        } else {
            std::cout << "✗ Test 3 FAILED: Result changed when disabled" << std::endl;
        }
        
        // Test case 4: Re-enable
        std::cout << "\nTest 4: Re-enabling operation" << std::endl;
        axi_write(OFFSET_ENABLE, 1); // Re-enable
        
        wait_cycles(10);
        
        result = axi_read(OFFSET_RESULT);
        if (result == 300) {
            std::cout << "✓ Test 4 PASSED: Operation resumed correctly" << std::endl;
        } else {
            std::cout << "✗ Test 4 FAILED: Expected 300, got " << result << std::endl;
        }
        
        // Test case 5: Zero addition
        std::cout << "\nTest 5: 0 + 0 = 0" << std::endl;
        axi_write(OFFSET_OPERAND_A, 0);
        axi_write(OFFSET_OPERAND_B, 0);
        
        wait_cycles(10);
        
        result = axi_read(OFFSET_RESULT);
        if (result == 0) {
            std::cout << "✓ Test 5 PASSED" << std::endl;
        } else {
            std::cout << "✗ Test 5 FAILED: Expected 0, got " << result << std::endl;
        }
    }
    
    void run_simulation() {
        std::cout << "Starting Adder Example Simulation" << std::endl;
        
        // Reset the design
        reset();
        
        // Run tests
        test_adder();
        
        // Final simulation time
        wait_cycles(50);
        
        std::cout << "\nSimulation completed successfully!" << std::endl;
        std::cout << "Waveforms saved to adder_example.vcd" << std::endl;
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    AdderTestbench tb;
    tb.run_simulation();
    
    return 0;
}