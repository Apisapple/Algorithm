import sys

input = sys.stdin.readline

def solution():
    h, w, x, y = map(int, input().split())
    
    board = [list(map(int, input().split())) for _ in range(h + x)]
    temp_arr = [[0] * w for _ in range(h)]
    
    for i in range(h):
        for j in range(w):
            if i < x or i >= h or j < y or j >= w:
                temp_arr[i][j] = board[i][j]
            else:
                temp_arr[i][j] = board[i][j] - temp_arr[i - x][j - y]
                
                
    for answer in temp_arr:
        print(' '.join(map(str, answer)))
        
solution()