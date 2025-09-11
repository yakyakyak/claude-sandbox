# Adder Example Verilator Testbench

This directory contains a Verilator-based testbench for the `adder_example` module with regio register interface.

## Prerequisites

- **Verilator** (version 4.0 or later)
- **GNU Make** (`gmake` on macOS, `make` on Linux)
- **GTKWave** (optional, for viewing waveforms)
- **C++ compiler** (g++ or clang++)

### Installing Verilator

**Ubuntu/Debian:**
```bash
sudo apt-get install verilator
```

**macOS:**
```bash
brew install verilator
```

## Test Structure

### Files

- `tb_adder_example.sv` - SystemVerilog testbench wrapper with DPI tasks
- `tb_adder_example.cpp` - C++ main testbench that drives the simulation
- `Makefile` - Build and simulation automation
- `README.md` - This documentation

### Register Interface

The testbench accesses the adder through AXI4-Lite register interface:

| Register    | Offset | Access | Description |
|-------------|--------|--------|-------------|
| `enable`    | 0x00   | RW     | Enable adder operation (1-bit) |
| `operand_a` | 0x04   | RW     | First operand (32-bit) |
| `operand_b` | 0x08   | RW     | Second operand (32-bit) |
| `result`    | 0x0C   | RO     | Addition result (32-bit) |

## Running Tests

### Basic Simulation
```bash
gmake sim
```

### View Waveforms
```bash
gmake waves
```

### Clean Build
```bash
gmake clean
```

## Test Cases

The testbench includes the following test cases:

1. **Basic Addition**: 5 + 7 = 12
2. **Large Numbers**: 0x12345678 + 0x87654321 
3. **Enable/Disable**: Verify enable control works
4. **Re-enable**: Test operation resumes correctly
5. **Zero Addition**: 0 + 0 = 0

## Expected Output

```
Starting Adder Example Simulation
Resetting DUT...
Reset complete.

=== Testing Adder Functionality ===

Test 1: 5 + 7 = 12
Writing 0x5 to address 0x4
Writing 0x7 to address 0x8
Writing 0x1 to address 0x0
Read 0xc from address 0xc
✓ Test 1 PASSED

Test 2: 0x12345678 + 0x87654321 = 0x999999999
Writing 0x12345678 to address 0x4
Writing 0x87654321 to address 0x8
Read 0x99999999 from address 0xc
✓ Test 2 PASSED

Test 3: Testing enable/disable
Writing 0x0 to address 0x0
Writing 0x64 to address 0x4
Writing 0xc8 to address 0x8
Read 0x99999999 from address 0xc
✓ Test 3 PASSED: Result unchanged when disabled

Test 4: Re-enabling operation
Writing 0x1 to address 0x0
Read 0x12c from address 0xc
✓ Test 4 PASSED: Operation resumed correctly

Test 5: 0 + 0 = 0
Writing 0x0 to address 0x4
Writing 0x0 to address 0x8
Read 0x0 from address 0xc
✓ Test 5 PASSED

Simulation completed successfully!
Waveforms saved to adder_example.vcd
```

## Design Under Test

The testbench verifies:
- **Register Interface**: AXI4-Lite protocol compliance
- **Adder Logic**: Correct arithmetic operations  
- **Control Logic**: Enable/disable functionality
- **Register Updates**: Result register updates correctly

## Debugging

- Use `gmake waves` to view signal waveforms in GTKWave
- Check console output for detailed register transactions
- Modify test cases in `tb_adder_example.cpp` for additional scenarios