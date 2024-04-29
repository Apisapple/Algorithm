from collections import deque

def solution(n, roads, sources, destination):
    answer = []

    visited = [-1] * (n + 1)
    
    graph = [[] for _ in range(n + 1)]
    for start, end in roads:
        graph[start].append(end)
        graph[end].append(start)
        
    que = deque([destination])
    visited[destination] = 0
    
    while que:
        now = que.popleft()
        
        for node in graph[now]:
            if visited[node] == -1 :
                visited[node] = visited[now] + 1
                que.append(node)

    return [visited[i] for i in sources]


print(solution(3, [[1, 2], [2, 3]], [2, 3], 1))
print(solution(5, [[1, 2], [1, 4], [2, 4], [2, 5], [4, 5]], [1, 3, 5], 5))
