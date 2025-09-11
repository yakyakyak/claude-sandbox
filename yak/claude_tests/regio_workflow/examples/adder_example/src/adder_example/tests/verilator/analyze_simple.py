#!/usr/bin/env python3

def analyze_vcd_simple():
    """Simple analysis of VCD file for adder verification"""
    
    with open("adder_functional.vcd", 'r') as f:
        lines = f.readlines()
    
    # Variable mapping from VCD inspection
    var_map = {
        '%': 'enable_reg',
        '&': 'operand_a_reg', 
        "'": 'operand_b_reg',
        '(': 'result_reg'
    }
    
    print("=== ADDER SIMULATION VERIFICATION ===\n")
    
    # Track values
    current_values = {'enable_reg': 0, 'operand_a_reg': 0, 'operand_b_reg': 0, 'result_reg': 0}
    current_time = 0
    
    for line in lines:
        line = line.strip()
        
        if line.startswith('#'):
            current_time = int(line[1:])
            
        elif line.startswith('b') and len(line) > 1:
            # Binary value change
            if line.endswith('&'):
                val = int(line[1:-1], 2)
                current_values['operand_a_reg'] = val
                print(f"Time {current_time}: operand_a = {val}")
                
            elif line.endswith("'"):
                val = int(line[1:-1], 2)
                current_values['operand_b_reg'] = val
                print(f"Time {current_time}: operand_b = {val}")
                
            elif line.endswith('('):
                val = int(line[1:-1], 2)
                current_values['result_reg'] = val
                print(f"Time {current_time}: result = {val}")
                
                # Check if computation is correct
                a = current_values['operand_a_reg']
                b = current_values['operand_b_reg']
                enable = current_values['enable_reg']
                
                if enable and (a != 0 or b != 0):
                    expected = a + b
                    if val == expected:
                        print(f"  ✓ CORRECT: {a} + {b} = {val}")
                    else:
                        print(f"  ✗ ERROR: Expected {expected}, got {val}")
                        
        elif line in ['0%', '1%']:
            # Enable bit change
            enable = int(line[0])
            current_values['enable_reg'] = enable
            print(f"Time {current_time}: enable = {enable}")
    
    print(f"\n=== FINAL TEST SUMMARY ===")
    print(f"Final values:")
    for var, val in current_values.items():
        print(f"  {var} = {val}")

if __name__ == "__main__":
    analyze_vcd_simple()