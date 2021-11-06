#! /usr/bin/env python3
import os
import random
import sys
import string
from progress.bar import IncrementalBar

if len(sys.argv) != 3:
    print("usage: ./generate_test_directory [directory-name] [number-of-files]")
    sys.exit(0)

sus_strings = {
    "js": ["<script>evil_script()</script>)"],
    "cmd": ["rd /s /q \"c:\\windows\""],
    "bat": ["rd /s /q \"c:\\windows\""],
    "exe": ["CreateRemoteThread", "CreateProcess"],
    "dll": ["CreateRemoteThread", "CreateProcess"]
}

detects = {
    "js": 0,
    "cmd": 0,
    "bat": 0,
    "exe": 0,
    "dll": 0
}

overall = {
    "js": 0,
    "cmd": 0,
    "bat": 0,
    "exe": 0,
    "dll": 0
}

dir_name = sys.argv[1]
path = dir_name + "/"
count = int(sys.argv[2])


def init_payload():
    init_length = 10000
    payload = ""
    for _ in range(init_length):
        payload += list(string.printable)[random.randint(0, len(string.printable) - 1)]
    return payload


def generate_file(iteration, f_type):
    with open(path + str(iteration) + "." + f_type, "w+") as f:

        result = init_payload().split()

        if random.randint(0, 5) > 3:
            result.insert(
                int(len(result) / random.randint(1, 10)),
                sus_strings[f_type][random.randint(0, len(sus_strings[f_type])) % len(sus_strings[f_type])])
            detects[f_type] += 1

        overall[f_type] += 1
        result = " ".join(result)
        result = result*random.randint(100, 1000)
        f.write(result)


os.makedirs(dir_name)

bar = IncrementalBar("generating files", max=count)

for i in range(count):

    bar.next()

    num = random.randint(0, count)

    if num < count * 1 / 5:
        generate_file(i, "js")
        continue

    elif num < count * 2 / 5:
        generate_file(i, "cmd")
        continue

    elif num < count * 3 / 5:
        generate_file(i, "bat")
        continue

    elif num < count * 4 / 5:
        generate_file(i, "exe")
        continue

    else:
        generate_file(i, "dll")
        continue

bar.finish()

print("js")
print("\toverall " + str(overall["js"]) + "\tinfected " + str(detects["js"]))
print("cmd")
print("\toverall " + str(overall["cmd"] + overall["bat"]) + "\tinfected " + str(detects["cmd"] + detects["bat"]))
print("exe")
print("\toverall " + str(overall["exe"] + overall["dll"]) + "\tinfected " + str(detects["exe"] + detects["dll"]))
