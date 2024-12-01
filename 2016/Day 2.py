inputFile = open("input/input_day2", "r")

code = ""

keypad = [
    [0, 0, 1, 0, 0],
    [0, 2, 3, 4, 0],
    [5, 6, 7, 8, 9],
    [0, 'A', 'B', 'C', 0],
    [0, 0, 'D', 0, 0]
]

pos = [2, 0]

for line in inputFile:
    if line.strip() == "":
        continue
    for char in line:
        if char == 'U':
            if pos[0] > 0 and keypad[pos[0] - 1][pos[1]] != 0:
                pos[0] -= 1
        elif char == 'D':
            if pos[0] < 4 and keypad[pos[0] + 1][pos[1]] != 0:
                pos[0] += 1
        elif char == 'L':
            if pos[1] > 0 and keypad[pos[0]][pos[1] - 1] != 0:
                pos[1] -= 1
        elif char == 'R':
            if pos[1] < 4 and keypad[pos[0]][pos[1] + 1] != 0:
                pos[1] += 1

    code += str(keypad[pos[0]][pos[1]])

print(code)

inputFile.close()
