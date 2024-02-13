import sys

def calc_1():
    temp = [[0] * m for _ in range(n)]
    for i in range(n):
        temp[i] = board[n - 1 - i]
    
    return temp

def calc_2():
    temp = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            temp[i][j] = board[i][m - 1 - j]
            
    return temp

def calc_3(board, n, m):
    temp = [[0] * n for _ in range(m)]
    for i in range(m):
        for j in range(n):
            temp[i][j] = board[n - 1 - j][i]
    
    return temp

def calc_4(board ,n , m):
    temp = [[0] * n for _ in range(m)]
    for i in range(m):
        for j in range(n):
            temp[i][j] = board[j][m - 1 - i]
    
    return temp

def calc_5():
    temp = [[0] * m for _ in range(n)]
    for i in range(n // 2):
        for j in range(m // 2):
            temp[i][j + m // 2] = board[i][j]
            
    for i in range(n // 2):
        for j in range(m // 2, m):
            temp[i + n // 2][j] = board[i][j]
            
    for i in range(n // 2, n):
        for j in range(m // 2, m):
            temp[i][j - m // 2] = board[i][j]
            
    for i in range(n // 2, n):
        for j in range(m // 2):
            temp[i - n // 2][j] = board[i][j]
            
    return temp

def calc_6():
    temp = [[0] * m for _ in range(n)]
    
    for i in range(n // 2):
        for j in range(m // 2):
            temp[i + n // 2][j] = board[i][j]
            
    for i in range(n // 2, n):
        for j in range(m // 2):
            temp[i][j + m // 2] = board[i][j]
            
    for i in range(n // 2, n):
        for j in range(m // 2, m):
            temp[i - n // 2][j] = board[i][j]
            
    for i in range(n // 2):
        for j in range(m // 2, m):
            temp[i][j - m // 2] = board[i][j]
            
    return temp


n, m, r = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
operations = list(map(int, input().split()))

for operation in operations:
    if operation is 1:
        board = calc_1()        
    elif operation is 2:
        board = calc_2()
    elif operation is 3:
        board = calc_3(board, n, m)
        n, m = m, n      
    elif operation is 4:
        board = calc_4(board, n, m)        
        n, m = m, n      
    elif operation is 5:
        board = calc_5()
    elif operation is 6:
        board = calc_6()


for i in board:
    print(*i)
# 1 번 연산 : 상하반전
# 2 번 연산 : 좌우반전
# 3 번 연산 : 오른쪽 90도 회전
# 4 번 연산 : 왼쪽 90도 회전
# 5 번 연산 : 4 부분으로 나눈 그룹을 1->2, 2->3, 3->4, 4->1
# 6 번 연산 : 4- > 3, 3-> 2, 2-> 1, 1-> 4