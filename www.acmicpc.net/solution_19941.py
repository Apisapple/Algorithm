import sys

input = sys.stdin.readline

n, k = map(int, input().split())
positioning = list(input())
answer = 0

for i in range(n):
    if positioning[i] == "P":
        for j in range(i - k, i + k + 1):
            if 0 <= j < n and positioning[j] == "H":
                answer += 1
                positioning[j] = "O"
                break

print(answer)
