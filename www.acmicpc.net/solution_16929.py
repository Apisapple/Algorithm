import sys

input = sys.stdin.readline
IS_POSSIBLE = "Yes"
IS_NOT_POSSIBLE = "No"
answer = False
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

n, m = map(int, input().split())
board = [[i for i in input().strip()] for _ in range(n)]
visited = [[0] * m for _ in range(n)]

def is_cycle(color, x, y, dept, start_x, start_y):
    global answer
    
    if answer :
        return
    
    for i in range(4):
        next_x, next_y = x + dx[i], y + dy[i]
        
        if next_x < 0 or n <= next_x or next_y < 0 or m <= next_y:
            continue
        
        if 4 <= dept and next_x == start_x and next_y == start_y:
            answer = True
            return
        
        if board[next_x][next_y] == color and visited[next_x][next_y] == 0:
            
            visited[next_x][next_y] = True
            is_cycle(color, next_x, next_y, dept + 1, start_x, start_y)
            visited[next_x][next_y] = False
            

def game_start():
    for i in range(n):
        for j in range(m):
            
            visited[i][j] = True
            is_cycle(board[i][j], i, j, 1, i, j)
            
            if answer:
                return IS_POSSIBLE
    
    return IS_NOT_POSSIBLE

print(game_start())