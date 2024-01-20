import sys

possible = "YES"
impossible = "NO"

input = sys.stdin.readline

def solution():
    n = int(input())
    m = int(input())
    parents = [i for i in range(n)]
    ranks = [0 for i in range(n)]

    index = 1
    for i in range(n):
        inp = list(map(int, input().split()))
        
        for j in range(index, n):
            if inp[j]:
                union(i, j, parents, ranks)
                
    plan = list(map(int, input().split()))
    comp = find(plan[0] - 1, parents)
    
    for i in range(1, len(plan)) :
        if find(plan[i] - 1, parents) != comp:
            print(impossible)
            return
    
    print(possible)


def union(x, y, parents, ranks):
    xroot = find(x, parents)
    yroot = find(y, parents)
    
    if ranks[xroot] >= ranks[yroot]:
        parents[yroot] = xroot
    else :
        parents[xroot] = yroot
        
    if ranks[xroot] == ranks[yroot]:
        ranks[xroot] += 1
    
    
def find(x, parents):
    if parents[x] == x :
        return x
    
    parents[x] = find(parents[x], parents)
    return parents[x]

solution()