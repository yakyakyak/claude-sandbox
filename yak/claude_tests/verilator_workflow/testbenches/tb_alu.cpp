#include <iostream>
#include <iomanip>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Valu.h"

// ALU operation codes
#define OP_ADD  0x0
#define OP_SUB  0x1
#define OP_AND  0x2
#define OP_OR   0x3
#define OP_XOR  0x4
#define OP_SLL  0x5
#define OP_SRL  0x6
#define OP_SRA  0x7
#define OP_SLT  0x8
#define OP_SLTU 0x9
#define OP_NOR  0xA
#define OP_NAND 0xB

class ALUTestbench {
private:
    Valu* dut;
    VerilatedVcdC* tfp;
    vluint64_t sim_time;
    int test_count;
    int pass_count;

public:
    ALUTestbench() {
        dut = new Valu;
        sim_time = 0;
        test_count = 0;
        pass_count = 0;
        
        Verilated::traceEverOn(true);
        tfp = new VerilatedVcdC;
        dut->trace(tfp, 99);
        tfp->open("sim/alu_test.vcd");
    }

    ~ALUTestbench() {
        tfp->close();
        delete dut;
        delete tfp;
    }

    void tick() {
        dut->eval();
        tfp->dump(sim_time);
        sim_time++;
    }

    void test_operation(uint32_t a, uint32_t b, uint8_t op, uint32_t expected, 
                       bool exp_zero, bool exp_overflow, bool exp_carry, 
                       const char* op_name) {
        dut->a = a;
        dut->b = b;
        dut->op = op;
        tick();
        
        test_count++;
        bool pass = true;
        
        if (dut->result != expected) {
            std::cout << "FAIL: " << op_name << " - Expected result: 0x" 
                     << std::hex << expected << ", Got: 0x" << dut->result << std::endl;
            pass = false;
        }
        
        if (dut->zero != exp_zero) {
            std::cout << "FAIL: " << op_name << " - Expected zero: " << exp_zero 
                     << ", Got: " << (int)dut->zero << std::endl;
            pass = false;
        }
        
        if (dut->overflow != exp_overflow) {
            std::cout << "FAIL: " << op_name << " - Expected overflow: " << exp_overflow 
                     << ", Got: " << (int)dut->overflow << std::endl;
            pass = false;
        }
        
        if (dut->carry_out != exp_carry) {
            std::cout << "FAIL: " << op_name << " - Expected carry: " << exp_carry 
                     << ", Got: " << (int)dut->carry_out << std::endl;
            pass = false;
        }
        
        if (pass) {
            pass_count++;
            std::cout << "PASS: " << op_name << " (0x" << std::hex << a 
                     << " op 0x" << b << " = 0x" << dut->result << ")" << std::endl;
        }
    }

    void run_tests() {
        std::cout << "Starting ALU Tests..." << std::endl;
        std::cout << "===================" << std::endl;

        // Addition tests
        test_operation(0x10, 0x20, OP_ADD, 0x30, false, false, false, "ADD basic");
        test_operation(0xFFFFFFFF, 0x1, OP_ADD, 0x0, true, false, true, "ADD overflow");
        test_operation(0x7FFFFFFF, 0x1, OP_ADD, 0x80000000, false, true, false, "ADD signed overflow");

        // Subtraction tests
        test_operation(0x30, 0x10, OP_SUB, 0x20, false, false, false, "SUB basic");
        test_operation(0x10, 0x20, OP_SUB, 0xFFFFFFF0, false, false, true, "SUB underflow");
        test_operation(0x0, 0x0, OP_SUB, 0x0, true, false, false, "SUB zero");

        // Logical operations
        test_operation(0xAAAA, 0x5555, OP_AND, 0x0, true, false, false, "AND");
        test_operation(0xAAAA, 0x5555, OP_OR, 0xFFFF, false, false, false, "OR");
        test_operation(0xAAAA, 0x5555, OP_XOR, 0xFFFF, false, false, false, "XOR");
        test_operation(0xAAAA, 0x5555, OP_NOR, 0xFFFF0000, false, false, false, "NOR");
        test_operation(0xAAAA, 0x5555, OP_NAND, 0xFFFFFFFF, false, false, false, "NAND");

        // Shift operations
        test_operation(0x1, 0x4, OP_SLL, 0x10, false, false, false, "SLL");
        test_operation(0x10, 0x2, OP_SRL, 0x4, false, false, false, "SRL");
        test_operation(0x80000000, 0x1, OP_SRA, 0xC0000000, false, false, false, "SRA");

        // Comparison operations
        test_operation(0x5, 0x10, OP_SLT, 0x1, false, false, false, "SLT true");
        test_operation(0x10, 0x5, OP_SLT, 0x0, true, false, false, "SLT false");
        test_operation(0x5, 0x10, OP_SLTU, 0x1, false, false, false, "SLTU true");
        test_operation(0xFFFFFFFF, 0x1, OP_SLTU, 0x0, true, false, false, "SLTU false");

        // Edge cases
        test_operation(0x0, 0x0, OP_ADD, 0x0, true, false, false, "ADD zeros");
        test_operation(0xFFFFFFFF, 0xFFFFFFFF, OP_AND, 0xFFFFFFFF, false, false, false, "AND all ones");

        std::cout << std::endl;
        std::cout << "Test Results: " << pass_count << "/" << test_count << " passed" << std::endl;
        
        if (pass_count == test_count) {
            std::cout << "ALL TESTS PASSED!" << std::endl;
        } else {
            std::cout << "SOME TESTS FAILED!" << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    ALUTestbench tb;
    tb.run_tests();
    
    return 0;
}