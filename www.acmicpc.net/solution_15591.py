from collections import deque, defaultdict

def solution(k, v, visited):
    count = 0
    queue = deque()
    queue.appendleft(v)
    
    while queue:
        edge = queue.popleft()
        visited[edge] = 1
        
        for edge, length in graph[edge]:
            if k <= length and not visited[edge]:
                visited[edge] = 1
                count += 1
                queue.appendleft(edge)
                
    return count


N, Q = map(int, input().split())
graph = defaultdict(list)

for p, q, r in [map(int, input().split()) for _ in range (N - 1)]:
    graph[p].append((q, r))
    graph[q].append((p, r))
    
for k, v in [map(int, input().split()) for _ in range(Q)]:
    print(solution(k, v, [0] * (N + 1)))