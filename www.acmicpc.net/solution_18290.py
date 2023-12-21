import sys
input=sys.stdin.readline

n, m, k = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

answer = -sys.maxsize

def search(cx, cy, index, total) :
    if index == k:
        global answer
        answer = max(answer, total)
        return

    for x in range(cx, n):
        for y in range(cy if x == cx else 0, m):
            if visited[x][y] :
                continue
            
            flag = True
            
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                
                if 0 <= nx < n and 0 <= ny < m:
                    if visited[nx][ny]:
                        flag = False
                        
            if flag:
                visited[x][y] = True
                search(x, y, index + 1, total + arr[x][y])
                visited[x][y] = False
                
search(0, 0, 0, 0)
print(answer)