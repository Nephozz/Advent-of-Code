inputFile = open("input/input_day6", "r")

G = []

for line in inputFile:
    G.append(list(line.strip()))

message = ""

for j in range(len(G[0])):
    letters = [G[i][j] for i in range(len(G))]
    message += min(set(letters), key=letters.count)


print(message)
