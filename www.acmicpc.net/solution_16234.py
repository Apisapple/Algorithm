from collections import deque
import sys

input = sys.stdin.readline

def search_answer(x, y):
    queue = deque()
    union = []
    queue.append((x, y))
    union.append((x, y))
    
    while queue:
        
        current_x, current_y = queue.popleft()
        
        for i in range(4):
            next_x = current_x + dx[i]
            next_y = current_y + dy[i]
            
            if 0 <= next_x < board_size and 0 <= next_y < board_size and visited[next_x][next_y] == 0:
                
                if min_people <= abs(board[next_x][next_y] - board[current_x][current_y]) <= max_people:
                    visited[next_x][next_y] = 1
                    queue.append((next_x, next_y))
                    union.append((next_x, next_y))
                    
    return union
                


board_size, min_people, max_people = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(board_size)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
answer = 0

while True:
    visited = [[0] * board_size for _ in range(board_size + 1)]
    flag = True
    
    for i in range(board_size):
        for j in range(board_size):
            
            if visited[i][j] == 0:
                
                visited[i][j] = 1
                countries = search_answer(i, j)
                
                if 1 < len(countries):
                    flag = False
                    
                    number = sum([board[x][y] for x, y in countries]) // len(countries)
                    for x, y in countries:
                        board[x][y] = number
                        
    if flag:
        break
    
    answer += 1
    
    
print(answer)