#! /usr/bin/env python3
import os
import random
import requests
import sys
from progress.bar import IncrementalBar

if len(sys.argv) != 3:
    print("usage: ./generate_test_directory [directory-name] [number-of-files]")
    sys.exit(0)

url = "https://libraryofbabel.info/book.cgi?"

sus_strings = [
    ["<script>evil_script()</script>)"],
    ["rd /s /q \"c:\\windows\""],
    ["rd /s /q \"c:\\windows\""],
    ["CreateRemoteThread", "CreateProcess"],
    ["CreateRemoteThread", "CreateProcess"]
]

detects = [0, 0, 0]

overall = [0, 0, 0]

dir_name = sys.argv[1]
path = dir_name + "/"
count = int(sys.argv[2])


def generate_file(iteration, f_type):
    with open(path + str(iteration) + f_type, "w+") as f:
        result = requests.get(
            url + hex(iteration) + "-w" + str(iteration) + "-s" + str(iteration) + "-v" + str(random.randint(0, 5)) + ":1").text.split()
        if random.randint(0, 5) > 3:
            if f_type == ".js":
                result.insert(int(len(result) / random.randint(1, 10)), sus_strings[0][0])
                detects[0] += 1
            elif (f_type == ".cmd") or (f_type == ".bat"):
                result.insert(int(len(result) / random.randint(1, 10)), sus_strings[1][0])
                detects[1] += 1
            else:
                result.insert(int(len(result) / random.randint(1, 10)), sus_strings[3][random.randint(0, 1) % 2])
                detects[2] += 1
        if f_type == ".js":
            overall[0] += 1
        elif (f_type == ".cmd") or (f_type == ".bat"):
            overall[1] += 1
        else:
            overall[2] += 1
        result = " ".join(result)
        result = result * (20 + random.randint(0, 100))
        f.write(result)


os.makedirs(dir_name)

bar = IncrementalBar("generating files", max=count)

for i in range(count):

    bar.next()

    num = random.randint(0, count)

    if num < count * 1 / 5:
        generate_file(i, ".js")
        continue

    elif num < count * 2 / 5:
        generate_file(i, ".cmd")
        continue

    elif num < count * 3 / 5:
        generate_file(i, ".bat")
        continue

    elif num < count * 4 / 5:
        generate_file(i, ".exe")
        continue

    else:
        generate_file(i, ".dll")
        continue

bar.finish()

print("js")
print("\toverall " + str(overall[0]) + "\tinfected " + str(detects[0]))
print("cmd")
print("\toverall " + str(overall[1]) + "\tinfected " + str(detects[1]))
print("exe")
print("\toverall " + str(overall[2]) + "\tinfected " + str(detects[2]))
