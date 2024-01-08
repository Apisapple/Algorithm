import sys
from collections import deque

input=sys.stdin.readline

n=int(input())
number_array=list(map(int, input().split()))

dp = [0] * n
que = deque()
current = set()

for i in range(len(number_array)) :
    if number_array[i] in current:
        while deque:
            pos, value = que.popleft()
            current.remove(value)
            if value == number_array[i]:
                break
    
    que.append([i, number_array[i]])
    current.add(number_array[i])
    
    dp[i] = len(current)
    
print(sum(dp))