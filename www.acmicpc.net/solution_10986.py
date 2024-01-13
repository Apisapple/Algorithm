import sys

input = sys.stdin.readline

n, m = map(int, input().split())
numbers = list(map(int, input().split()))
total = 0
remain_numbers = [0] * m

for i in range(n):
    total += numbers[i]
    remain_numbers[total % m] += 1
    
result = remain_numbers[0]

for i in remain_numbers:
    result += i * (i - 1) // 2
    
print(result)