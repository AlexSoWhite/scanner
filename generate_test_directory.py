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

js_detects = 0
cmd_detects = 0
exe_detects = 0

js_overall = 0
cmd_overall = 0
exe_overall = 0

dir_name = sys.argv[1]
path = dir_name + "/"
count = int(sys.argv[2])

os.makedirs(dir_name)

bar = IncrementalBar("generating files", max = count)

for i in range(count):

    bar.next()

    num = random.randint(0, count)

    if num < count * 1 / 5:
        with open(path + str(i) + ".js", "w+") as f:
            r = requests.get(
                url + hex(i) + "-w" + str(i) + "-s" + str(i) + "-v" + str(random.randint(0, 5)) + ":1").text.split()
            if random.randint(0, 5) > 3:
                r.insert(int(len(r) / random.randint(1, 10)), sus_strings[0][0])
                js_detects += 1
            r = " ".join(r)
            js_overall += 1
            r = r * (20 + random.randint(0, 100))
            f.write(r)
        continue

    elif num < count * 2 / 5:
        with open(path + str(i) + ".cmd", "w+") as f:
            r = requests.get(
                url + hex(i) + "-w" + str(i) + "-s" + str(i) + "-v" + str(random.randint(0, 5)) + ":1").text.split()
            if random.randint(0, 5) > 3:
                r.insert(int(len(r) / random.randint(1, 10)), sus_strings[1][0])
                cmd_detects += 1
            r = " ".join(r)
            cmd_overall += 1
            r = r * (20 + random.randint(0, 100))
            f.write(r)
        continue

    elif num < count * 3 / 5:
        with open(path + str(i) + ".bat", "w+") as f:
            r = requests.get(
                url + hex(i) + "-w" + str(i) + "-s" + str(i) + "-v" + str(random.randint(0, 5)) + ":1").text.split()
            if random.randint(0, 5) > 3:
                r.insert(int(len(r) / random.randint(1, 10)), sus_strings[2][0])
                cmd_detects += 1
            r = " ".join(r)
            cmd_overall += 1
            r = r * (20 + random.randint(0, 100))
            f.write(r)
        continue

    elif num < count * 4 / 5:
        with open(path + str(i) + ".exe", "w+") as f:
            r = requests.get(
                url + hex(i) + "-w" + str(i) + "-s" + str(i) + "-v" + str(random.randint(0, 5)) + ":1").text.split()
            if random.randint(0, 5) > 3:
                r.insert(int(len(r) / random.randint(1, 10)), sus_strings[3][random.randint(0, 1) % 2])
                exe_detects += 1
            r = " ".join(r)
            exe_overall += 1
            r = r * (20 + random.randint(0, 100))
            f.write(r)
        continue

    else:
        with open(path + str(i) + ".dll", "w+") as f:
            r = requests.get(
                url + hex(i) + "-w" + str(i) + "-s" + str(i) + "-v" + str(random.randint(0, 5)) + ":1").text.split()
            if random.randint(0, 5) > 3:
                r.insert(int(len(r) / random.randint(1, 10)), sus_strings[4][random.randint(0, 1) % 2])
                exe_detects += 1
            r = " ".join(r)
            exe_overall += 1
            r = r * (100 + random.randint(0, 1000))
            f.write(r)
        continue

bar.finish()

print("js")
print("\toverall "+str(js_overall)+"\tinfected "+str(js_detects))
print("cmd")
print("\toverall "+str(cmd_overall)+"\tinfected "+str(cmd_detects))
print("exe")
print("\toverall "+str(exe_overall)+"\tinfected "+str(exe_detects))
