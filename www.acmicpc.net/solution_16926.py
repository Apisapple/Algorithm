from collections import deque
import sys

input = sys.stdin.readline

def rotate_board():
    que = deque()

    for dept in range(min(n, m) // 2):
        x = y = dept
        
        for dx, dy in move:
            while True:
                nx = x + dx
                ny = y + dy
                
                if dept <= nx < n - dept and dept <= ny < m - dept:
                    que.append(board[x][y])
                    x = nx
                    y = ny
                else :
                    break
                
        for _ in range(r % ((n - dept * 2) * 2 + (m - dept * 2) * 2 - 4)):
            que.appendleft(que.pop())
            
        for dx, dy in move:
            while True:
                nx = x + dx
                ny = y + dy
                
                if dept <= nx < n - dept and dept <= ny < m - dept:
                    board[x][y] = que.popleft()
                    x = nx
                    y = ny
                else :
                    break
                



            
n, m, r = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
move = [[1, 0], [0, 1], [-1, 0], [0, -1]]

rotate_board()


for i in range(n):
    for j in range(m):
        print(board[i][j], end=" ")
    print()
            