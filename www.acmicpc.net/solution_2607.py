import sys

input = sys.stdin.readline

data_count = int(input())
target = input().strip()
string_list = [input().strip() for _ in range(data_count - 1)]
answer = 0

for compare_data in string_list:
    if 1 < abs(len(compare_data) - len(target)) or 1 < len(
        set(target).difference(set(compare_data))
    ):
        continue

    for c in target:
        if c in compare_data:
            compare_data = compare_data.replace(c, "", 1)

    if len(compare_data) <= 1:
        answer += 1

print(answer)
