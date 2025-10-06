def execute_instruction(label_or_var, operation, operand):
    # Check if it's a label (ends with ':')
    if label_or_var.endswith(':'):
        instructions[label_or_var] = f"{operation} {operand}"
        print(f"{label_or_var} {instructions[label_or_var]}")

        # Split operands for operations that use two variables
        args = operand.split(',')

        if operation == "add":
            safe_update(args[0], iden.get(args[0], 0) + iden.get(args[1], 0))

        elif operation == "sub":
            safe_update(args[0], iden.get(args[0], 0) - iden.get(args[1], 0))

        elif operation == "mul":
            safe_update(args[0], iden.get(args[0], 0) * iden.get(args[1], 0))

        elif operation == "div":
            if iden.get(args[1], 0) != 0:
                safe_update(args[0], iden.get(args[0], 0) / iden.get(args[1], 0))
            else:
                print("Error: divide by zero!")

        elif operation == "jmp":
            target_label = operand + ':'
            if target_label in instructions:
                next_op, next_operand = instructions[target_label].split()
                print(f"Jumping to instruction at {operand}")
                execute_instruction(target_label, next_op, next_operand)
            else:
                print(f"Error: label {target_label} not found")

        elif operation == "out":
            print(iden.get(operand, f"Undefined variable: {operand}"))

        elif operation == "inp":
            try:
                iden[operand] = int(input(f"Enter value for {operand}: "))
            except ValueError:
                print("Invalid input. Expected an integer.")

        elif operation == "mov":
            if args[1] in iden:
                safe_update(args[0], iden[args[1]])
            else:
                print(f"Error: variable {args[1]} not defined")

        elif operation == "cmp":
            val1 = iden.get(args[0])
            val2 = iden.get(args[1])
            if val1 is None or val2 is None:
                print("Error: comparison variables not defined")
            elif val1 == val2:
                print("Values are equal")
            elif val1 < val2:
                print(f"{val1} < {val2}")
            else:
                print(f"{val1} > {val2}")

    else:
        # Variable initialization
        try:
            iden[label_or_var] = int(operand)
        except ValueError:
            print(f"Error: invalid value for {label_or_var}: {operand}")

def safe_update(var, value):
    iden[var] = value
    print(f"{var} = {value}")

# Main program
try:
    with open("testdata.txt", "r") as file:
        lines = file.read().strip().split('\n')
        instructions = {}
        iden = {}

        for line_num, line in enumerate(lines, start=1):
            parts = line.strip().split()
            if len(parts) == 3:
                execute_instruction(parts[0], parts[1], parts[2])
            else:
                print(f"Skipping invalid instruction at line {line_num}: {line}")

except FileNotFoundError:
    print("Error: 'testdata.txt' not found.")

input("Press Enter to exit...")
