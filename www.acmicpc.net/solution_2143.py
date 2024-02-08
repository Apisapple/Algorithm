import sys
from collections import defaultdict 

input = sys.stdin.readline

test_numbr = int(input())

a_arr_count = int(input())
a_arr = list(map(int, input().split()))

b_arr_count = int(input())
b_arr = list(map(int, input().split()))

answer = 0
a_dict = defaultdict(int)

for i in range(a_arr_count):
    for j in range(i, a_arr_count):
        a_dict[sum(a_arr[i:j+1])] += 1


for i in range(b_arr_count):
    for j in range(i, b_arr_count):
        answer += a_dict[test_numbr - sum(b_arr[i:j+1])]

print(answer)