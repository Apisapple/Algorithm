import heapq
import sys

input=sys.stdin.readline
INF=int(1e9)
loop_count = 1

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dijkstra(board_size):
    que = []
    heapq.heappush(que, (board[0][0], 0, 0))
    distance[0][0] = 0
    
    while que:
        cost, x, y = heapq.heappop(que)
        
        if x == board_size - 1 and y == board_size - 1:
            print(f'Problem {loop_count}: {distance[x][y]}')
            break
        
        for i in range(4):
            next_x = x + dx[i]
            next_y = y + dy[i]
            
            if 0 <= next_x < board_size and 0 <= next_y < board_size:
                next_cost = cost + board[next_x][next_y]
                
                if next_cost < distance[next_x][next_y]:
                    distance[next_x][next_y] = next_cost
                    heapq.heappush(que, (next_cost, next_x, next_y))

while True:
    board_size = int(input())
    
    if board_size == 0:
        break
    
    board = [list(map(int, input().split())) for _ in range(board_size)]
    distance = [[INF] * board_size for _ in range(board_size)]
    
    dijkstra(board_size)
    loop_count += 1