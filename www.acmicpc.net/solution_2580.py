import sys

input = sys.stdin.readline

sudoku_board = [list(map(int, input().rstrip().split())) for _ in range(9)]
blank = []

for i in range(9):
  for j in range(9):
    if sudoku_board[i][j] == 0:
      blank.append((i, j))
      
def search_answer(index):

  if index == len(blank):
    for i in range(9):
      print(*sudoku_board[i])
    exit()
    
  for i in range(1, 10):
    x = blank[index][0]
    y = blank[index][1]

    if check_row(x, i) and check_colum(y, i) and check_square(x, y, i):
      sudoku_board[x][y] = i
      search_answer(index + 1)
      sudoku_board[x][y] = 0
      
def check_row(x, a):
  for i in range(9):
    if a == sudoku_board[x][i]:
      return False
    
  return True

def check_colum(y, a):
  for i in range(9):
    if a == sudoku_board[i][y]:
      return False
    
  return True
    
def check_square(x, y, a):
  nx = x // 3 * 3
  ny = y // 3 * 3
  for i in range(3):
      for j in range(3):
          if a == sudoku_board[nx+i][ny+j]:
              return False
  return True

search_answer(0)