from collections import deque
import sys

input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
n, m = map(int, input().split())
coin = deque()
board = []
temp = []

for i in range(n):
    board.append(list(input().strip()))
    
    for j in range(m):
        if board[i][j] == 'o':
            temp.append((i, j))
            
coin.append((temp[0][0], temp[0][1], temp[1][0], temp[1][1], 0))

def bfs():
    
    while coin:
        x1, y1, x2, y2, count = coin.popleft()
        
        if 10 <= count:
            return -1
        
        for i in range(4):
            next_x1 = x1 + dx[i]
            next_y1 = y1 + dy[i]
            next_x2 = x2 + dx[i]
            next_y2 = y2 + dy[i]
            
            if 0 <= next_x1 < n and 0 <= next_y1 < m and 0 <= next_x2 < n and 0 <= next_y2 < m:
                
                if board[next_x1][next_y1] == '#':
                    next_x1, next_y1 = x1, y1
                if board[next_x2][next_y2] == '#':
                    next_x2, next_y2 = x2, y2
                    
                coin.append((next_x1, next_y1, next_x2, next_y2, count + 1))

            elif 0 <= next_x1 < n and 0 <= next_y1 < m :
                return count + 1
            elif 0 <= next_x2 < n and 0 <= next_y2 < m:
                return count + 1
            else:
                continue
            
    return -1                
    


print(bfs())