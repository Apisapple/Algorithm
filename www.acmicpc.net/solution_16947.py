from collections import deque
import sys

input = sys.stdin.readline

station_count = int(input())
graph = [[] for _ in range(station_count)]
temp_graph = [[] for _ in range(station_count)]
graph_size = [0] * station_count
parents = [-1] * station_count
answer = [-1] * station_count


for _ in range(station_count):
    start, end = map(int, input().split())

    graph[start - 1].append(end - 1)
    temp_graph[start - 1].append(end - 1)
    graph_size[start - 1] += 1

    graph[end - 1].append(start - 1)
    temp_graph[end - 1].append(start - 1)
    graph_size[end - 1] += 1


while True:
    is_end = True
    
    for i in range(station_count):
        if graph_size[i] == 1:
            parent = temp_graph[i].pop()
            parents[i] = parent
            temp_graph[parent].remove(i)
            graph_size[i] = 0
            graph_size[parent] -= 1
            
            is_end = False
    
    if is_end:
        break
    
    
que = deque()

for i in range(station_count):
    if parents[i] == -1:
        answer[i] = 0
        que.append(i)
        
while que:
    current = que.popleft()
    
    for child in graph[current]:
        if answer[child] == -1:
            answer[child] = answer[current] + 1
            que.append(child)
            
print(*answer)