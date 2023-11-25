import sys

input = sys.stdin.readline

tower_cnt = int(input())
towers_height = list(map(int, input().split()))
stack = []
answer = []

for i in range(tower_cnt):
    while stack:
        if stack[-1][1] > towers_height[i]:
            answer.append(stack[-1][0] + 1)
            break
        
        else:
            stack.pop()
            
    if not stack:
        answer.append(0)
        
    stack.append([i, towers_height[i]])
    
print(" ".join(map(str, answer)))