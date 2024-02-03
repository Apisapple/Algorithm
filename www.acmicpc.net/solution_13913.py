from collections import deque

n, k = map(int, input().split())
dist = [0] * 1000001
move = [0] * 1000001

def path(x):
    arr = []
    temp = x
    for _ in range(dist[x]+1):
        arr.append(temp)
        temp = move[temp]
    print(' '.join(map(str, arr[::-1])))

def bfs():
    que = deque()
    que.append(n)
    while que:
        x = que.popleft()
        if x == k:
            print(dist[x])
            path(x)
            return x
        for i in (x + 1, x - 1, 2 * x):
            if 0 <= i <= 100000 and dist[i] == 0:
                que.append(i)
                dist[i] = dist[x] + 1
                move[i] = x


bfs()