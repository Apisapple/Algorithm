import sys

sys.setrecursionlimit(10**6)

n=int(input())
graph = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)
answer = []

for i in range(n) :
    temp = int(input())
    graph[temp].append(i + 1)

def search_answer(index, route):
    route.add(index)
    visited[index] = True

    for i in graph[index]:
        if i not in route:
            search_answer(i, route.copy())

        else :
            answer.extend(list(route))
            return
        

for i in range(1, n + 1) :
    if not visited[i]:
        search_answer(i, set([]))


answer.sort()

print(len(answer))
for i in answer:
    print(i)
