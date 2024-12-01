import hashlib

prefix = "ojvtpuvg"
password = [None] * 8
count = 0
i = 0

while count < 8:
    hash = hashlib.md5()

    hash.update((prefix + str(i)).encode('utf-8'))
    result = hash.hexdigest()

    if result[:5] == "00000":
        if result[5].isdigit() and int(result[5]) < 8 and password[int(result[5])] is None:
            password[int(result[5])] = result[6]
            count += 1

    i += 1

password = ''.join(password)
print(password)
