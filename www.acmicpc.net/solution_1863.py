import sys

input=sys.stdin.readline

n = int(input().strip())
stack = []
answer = 0

for _ in range(n):
    x, y = map(int, input().strip().split())
    
    while 0 < len(stack) and y < stack[-1] :
        answer += 1
        stack.pop()
    
    if 0 < len(stack) and stack[-1] == y:
        continue
    
    stack.append(y)
    
while 0 < len(stack):
    if stack[-1] > 0:
        answer += 1
        
    stack.pop()
    
print(answer)