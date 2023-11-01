import sys

input = sys.stdin.readline

input_data = list(input())

zero_count = input_data.count("0")
one_count = input_data.count("1")

check = 0
for i in input_data:
    if check == one_count // 2:
        break

    if i == "1":
        input_data.remove(i)
        check += 1


check = 0
input_data = input_data[::-1]
for i in input_data:
    if check == zero_count // 2:
        break

    if i == "0":
        input_data.remove(i)
        check += 1


for i in input_data[::-1]:
    print(i, end="")
