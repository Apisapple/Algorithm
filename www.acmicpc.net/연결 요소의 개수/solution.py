import sys
sys.setrecursionlimit(10000)

def dfs(index, visit, board):
    """[깊이 우선 탐샘 함수]

    Args:
        index ([int]): [찾는 위치]
        visit ([list]): [방문 여부]
        board ([double list]): [그래프]
    """
    visit[index] = True
    for i in board[index]:
        if (visit[i] == False):
            dfs(i, visit, board)

def solution():
    """
    main 함수
    """
    node_count, line_count = map(int, input().split())
    board = [[] for _ in range(node_count + 1)]
    visit = [False] * (node_count + 1)
    count = 0

    #  그래프 연결
    for _ in range(line_count):
        start, end = map(int, input().split())
        board[start].append(end)
        board[end].append(start)

    for i in range(1, node_count + 1) :
        if(visit[i] == False) :
            dfs(i, visit, board)
            count += 1
    
    print(count)

solution()