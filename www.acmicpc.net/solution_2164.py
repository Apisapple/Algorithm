from collections import deque

que = deque()
n = int(input())

for i in range(n):
   que.append(i + 1) 
   
   
while 1 < len(que):
    que.popleft()
    que.append(que.popleft())
    
    
print(que.pop()) 