inputFile = open("input/input_day7", "r")

def isABBA(string):
    for i in range(len(string)-3):
        if string[i] == string[i+3] and string[i+1] == string[i+2] and string[i] != string[i+1]:
            return True
    return False

def isABA(string):
    list = []
    for i in range(len(string)-2):
        if string[i] == string[i+2] and string[i] != string[i+1]:
            list.append(string[i:i+3])
    return list

def supportsTLS(line):
    abba_outside = False

    for part in line:
        if part[0] == "[" and isABBA(part):
            return False
        elif part[0] != "[" and isABBA(part):
            abba_outside = True

    return abba_outside

def supportsSSL(line):
    aba_list = []
    bab_list = []

    for part in line:
        if part[0] == "[":
            bab_list += isABA(part)
        else:
            aba_list += isABA(part)

    for aba in aba_list:
        bab = aba[1] + aba[0] + aba[1]
        if bab in bab_list:
            return True

    return False

numTLS = 0
numSSL = 0

for line in inputFile:
    line = line.replace("[", " [").replace("]", "] ").split()

    if supportsTLS(line):
        numTLS += 1

    if supportsSSL(line):
        numSSL += 1

print("Number supporting TLS : ",numTLS)
print("Number supporting SSL : ",numSSL)

inputFile.close()
