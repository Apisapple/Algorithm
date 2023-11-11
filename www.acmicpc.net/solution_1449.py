import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize

def solution():
    street_count, total = map(int, input().split())
    graph = [[] for _ in range(total)]
    street_informations = inputStreetInformation(graph, street_count)
    answer = getShortestDistance(street_informations, 0, total)
    print(answer)

def inputStreetInformation(graph, street_count):
    graph = initGraph(graph)
    for _ in range(street_count):
        start_node, end_node, distance = map(int, input().split())

        if end_node > len(graph):
            continue;
        graph[start_node].append((end_node, distance))

    return graph

def initGraph(graph):
    size = len(graph)

    for i in range(size):
        graph[i].append((i + 1, 1))

    return graph

def getShortestDistance(graph, start_node, end_node):
    distance = [INF] * (end_node + 1)
    que = []
    heapq.heappush(que, (0, start_node))
    distance[start_node] = 0

    while que:
        current_distance, current_node = heapq.heappop(que)
        if current_distance > distance[current_node] :
            continue
        if(current_node == end_node):
            break

        for current_node_info in graph[current_node]:
            cost = current_distance + current_node_info[1]

            if cost < distance[current_node_info[0]] :
                distance[current_node_info[0]] = cost
                heapq.heappush(que, (cost, current_node_info[0]))

    return distance[end_node]

solution()