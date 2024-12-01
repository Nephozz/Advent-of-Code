inputFile = open("input/input_day1", "r")

direction = 0
y_block = 0
x_block = 0

line = inputFile.readline()

inputFile.close()

instructions = line.split(", ")

visitedPosition = set()
visitedPosition.add((x_block,y_block))

revisited = False

for instruction in instructions:

    if instruction[0] == 'R':
        direction = (direction + 1) % 4
    else:
        direction = (direction - 1) % 4

    distance = int(instruction[1:])

    for _ in range(distance):
        match direction:
            case 0:
                x_block += 1
            case 1:
                y_block += 1
            case 2:
                x_block -= 1
            case 3:
                y_block -= 1

        currentPosition = (x_block,y_block)

        if currentPosition in visitedPosition and not revisited:
            print(abs(x_block) + abs(y_block))
            revisited = True

        visitedPosition.add(currentPosition)

if not revisited:
    print("Only unique visits")

print(abs(x_block) + abs(y_block))

