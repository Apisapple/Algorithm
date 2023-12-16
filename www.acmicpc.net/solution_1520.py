import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
dp = [[-1] * m for _ in range(n)]
dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]

def dfs(cx, cy):
    if cx == n - 1 and cy == m - 1:
        return 1
    
    if dp[cx][cy] != -1:
        return dp[cx][cy]
    

    ways = 0
    for i in range(4):
        nx, ny = cx + dx[i], cy + dy[i]
        
        if 0 <= nx < n and 0 <= ny < m and board[cx][cy] > board[nx][ny]:
            ways += dfs(nx, ny)
            
    dp[cx][cy] = ways
    return dp[cx][cy]    

print(dfs(0, 0))