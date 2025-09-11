#!/bin/bash

# Simple test runner script for adder_example Verilator testbench

set -e  # Exit on any error

echo "=== Adder Example Verilator Test Runner ==="
echo

# Check if Verilator is installed
if ! command -v verilator &> /dev/null; then
    echo "❌ Error: Verilator not found!"
    echo "   Install with: apt-get install verilator (Ubuntu) or brew install verilator (macOS)"
    exit 1
fi

echo "✓ Verilator found: $(verilator --version | head -n1)"

# Clean previous builds
echo "🧹 Cleaning previous builds..."
gmake clean

# Build and run simulation
echo "🔨 Building and running simulation..."
if gmake sim; then
    echo
    echo "✅ All tests passed!"
    echo "📊 Waveforms saved to adder_example.vcd"
    echo
    echo "To view waveforms: make waves"
else
    echo
    echo "❌ Tests failed!"
    exit 1
fi