import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
board = []
dx = [-1, -1, -1, 0, 1, 1, 1, 0]
dy = [-1, 0, 1, 1, 1, 0, -1, -1]
shark_position = deque()

for i in range(n):
    temp_list = list(map(int, input().split()))

    for j in range(m):
        if temp_list[j] == 1:
            shark_position.append((i, j))

    board.append(temp_list)


def bfs():
    while shark_position:
        x, y = shark_position.popleft()
        
        for i in range(8):
            next_x = x + dx[i]
            next_y = y + dy[i]
            
            if 0 <= next_x < n and 0 <= next_y < m:
                if board[next_x][next_y] == 0:
                    shark_position.append((next_x, next_y))
                    board[next_x][next_y] = board[x][y] + 1
                    
    return

bfs()

answer = 0
for i in range(n):
    for j in range(m):
        answer = max(answer, board[i][j])
        
print(answer - 1)