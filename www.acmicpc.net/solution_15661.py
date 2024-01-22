import sys

input=sys.stdin.readline
answer = sys.maxsize

def acmicpc_15661():
    
    n = int(input())
    stat_board = [list(map(int, input().split())) for _ in range(n)]
    visited = [False] * n
    
    solution(0, n, stat_board, visited)
    
    print(answer)
    
def solution(index, n, stat_board, visited) :
    if index is n :
        calc_answer(n, stat_board, visited)
        return
    
    visited[index] = True
    solution(index + 1, n, stat_board, visited)
    visited[index] = False
    solution(index + 1, n, stat_board, visited)
    
    
def calc_answer(n, stat_board, visited):
    global answer
    star, link = 0, 0
    
    for i in range(n - 1):
        for j in range(i + 1, n):
            if visited[i] and visited[j]:
                star += stat_board[i][j] + stat_board[j][i]
            elif not visited[i] and not visited[j]:
                link += stat_board[i][j] + stat_board[j][i]
    
    answer = min(answer, abs(star - link))
    
    
acmicpc_15661()