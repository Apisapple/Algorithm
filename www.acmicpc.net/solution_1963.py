import sys, math
from collections import deque

def is_prime() :
    for i in range(2, 100):
        if prime_number[i] :
            for j in range(2 * i, 10000, i):
                prime_number[j] = False
                
                
def bfs():
    que = deque()
    que.append([start, 0])
    visited = [0 for i in range(10000)]
    visited[start]
    
    while que:
        current, count = que.popleft()
        current_string = str(current)
        
        if current == end:
            return count
        
        for i in range(4):
            for j in range(10):
                temp = int(current_string[:i] + str(j) + current_string[i + 1:])
                if visited[temp] == 0 and prime_number[temp] and temp >= 1000:
                    visited[temp] = 1
                    que.append([temp, count + 1])
    
    
t = int(sys.stdin.readline())
prime_number = [True for _ in range(10000)]
is_prime()

for _ in range(t):
    
    start, end = map(int, sys.stdin.readline().split())
    
    result = bfs()
    
    print(result if result != None else "Impossible")