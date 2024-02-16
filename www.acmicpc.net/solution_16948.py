from collections import deque
import sys

input = sys.stdin.readline

dx = [-2, -2, 0, 0, 2, 2]
dy = [-1, 1, -2, 2, -1, 1]

n = int(input())
r1, c1, r2, c2 = map(int, input().split())
visited = [[0] * n for _ in range(n)]

def bfs(x: int, y : int):
    
    queue = deque()
    queue.append([x, y])
    visited[x][y] = 1
    
    while queue:
        x, y = queue.popleft()
        
        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < n and 0 <= ny < n and visited[nx][ny] == 0:
                visited[nx][ny] = visited[x][y] + 1
                queue.append([nx, ny])


bfs(r1, c1)
print(visited[r2][c2] - 1)