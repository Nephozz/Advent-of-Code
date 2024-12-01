inputFile = open("input/input_day3", "r")

G = []
numTriangles = 0

for line in inputFile:
    G.append(list(line.split()))

def isTriangle(a, b, c):
    return a + b > c and b + c > a and a + c > b

for i in range(0, len(G), 3):
    for j in range(3):
        if isTriangle(int(G[i][j]), int(G[i + 1][j]), int(G[i + 2][j])):
            numTriangles += 1

print(numTriangles)

inputFile.close()
