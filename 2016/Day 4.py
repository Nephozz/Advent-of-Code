inputFile = open("input/input_day4", "r")

for line in inputFile:
    line = line.split("-")
    checksum = line[-1].split("[")[1].split("]")[0]
    id = int(line[-1].split("[")[0])

    line = line[:-1]
    name = " ".join(line)
    line = "".join(line)

    letters_count = set()

    for letter in line:
        letters_count.add((name.count(letter), letter))

    letters_count = sorted(letters_count, key=lambda x: (-x[0], x[1]))
    letters_count = letters_count[:5]

    calculated_checksum = "".join([x[1] for x in letters_count])

    if calculated_checksum == checksum:
        decrypted_name = ""
        for letter in name:
            if letter == " ":
                decrypted_name += " "
            else:
                decrypted_name += chr((ord(letter) - 97 + id) % 26 + 97)
        if "north" in decrypted_name:
            print(decrypted_name, id)
            break



