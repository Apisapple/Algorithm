from collections import deque
import sys

input = sys.stdin.readline

def search_answer(x, y):
    queue = deque()
    queue.append((x, y))
    
    visited[x][y] = 0
    while queue:
        current_x, current_y = queue.popleft()
        
        for i in range(4):
            next_x, next_y = current_x + dx[i], current_y + dy[i]
            
            if 0 <= next_x < height and 0 <= next_y < width and visited[next_x][next_y] == -1:
                if board[next_x][next_y] == 0:
                    visited[next_x][next_y] = 0
                elif board[next_x][next_y] == 1:
                    visited[next_x][next_y] = visited[current_x][current_y] + 1
                    queue.append((next_x, next_y))

height, width = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(height)]
visited = [ [-1] * width for _ in range(height)]
dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]

                    
for i in range(height):
    for j in range(width):
        if board[i][j] == 2 and visited[i][j] == -1:
            search_answer(i, j)
            
for i in range(height):
    for j in range(width):
        if board[i][j] == 0:
            print(0, end = ' ')
        else :
            print(visited[i][j], end= ' ')
            
            
    print()