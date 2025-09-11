#!/usr/bin/env python3

import re

def analyze_vcd(filename):
    """Analyze VCD file to extract and verify adder test results"""
    
    # Read the VCD file
    with open(filename, 'r') as f:
        content = f.read()
    
    # Find variable definitions
    var_map = {}
    lines = content.split('\n')
    
    for line in lines:
        if '$var wire' in line and ('operand_a_reg' in line or 'operand_b_reg' in line or 'result_reg' in line or 'enable_reg' in line):
            parts = line.split()
            if len(parts) >= 6:
                var_id = parts[4]
                var_name = parts[5]
                var_map[var_id] = var_name
                print(f"Found variable: {var_name} -> {var_id}")
    
    print(f"\nVariable mapping: {var_map}")
    
    # Track signal values over time
    current_time = 0
    values = {}
    
    for line in lines:
        line = line.strip()
        
        # Time updates
        if line.startswith('#'):
            current_time = int(line[1:])
            
        # Binary value updates
        elif line.startswith('b') and len(line) > 32:
            binary_val = line[:33]  # b + 32 bits
            var_id = line[33:]
            if var_id in var_map:
                decimal_val = int(binary_val[1:], 2)  # Skip 'b' prefix
                values[current_time] = values.get(current_time, {})
                values[current_time][var_map[var_id]] = decimal_val
                
        # Single bit updates  
        elif len(line) == 2 and line[1] in var_map:
            bit_val = int(line[0])
            var_id = line[1]
            values[current_time] = values.get(current_time, {})
            values[current_time][var_map[var_id]] = bit_val
    
    # Print results timeline
    print("\n=== SIMULATION RESULTS ANALYSIS ===")
    prev_values = {}
    
    for time in sorted(values.keys()):
        current_vals = values[time]
        changed = False
        
        for var, val in current_vals.items():
            if var not in prev_values or prev_values[var] != val:
                changed = True
                break
                
        if changed:
            print(f"\nTime {time}:")
            merged_vals = {**prev_values, **current_vals}
            
            operand_a = merged_vals.get('operand_a_reg', 0)
            operand_b = merged_vals.get('operand_b_reg', 0) 
            result = merged_vals.get('result_reg', 0)
            enable = merged_vals.get('enable_reg', 0)
            
            print(f"  operand_a = {operand_a}")
            print(f"  operand_b = {operand_b}")
            print(f"  enable = {enable}")
            print(f"  result = {result}")
            
            if enable and operand_a != 0 and operand_b != 0:
                expected = operand_a + operand_b
                if result == expected:
                    print(f"  ✓ CORRECT: {operand_a} + {operand_b} = {result}")
                else:
                    print(f"  ✗ ERROR: Expected {expected}, got {result}")
            
            prev_values.update(current_vals)

if __name__ == "__main__":
    analyze_vcd("adder_functional.vcd")