import sys
from collections import defaultdict

def solve():
    left, right, answer = 0, 0, 0
    dictionary = defaultdict(int)
    
    while right < k:
        dictionary[dishes[right]] += 1
        right += 1
        
    dictionary[c] += 1
    
    while left < n:
        answer = max(answer, len(dictionary))
        
        dictionary[dishes[left]] -= 1
        if dictionary[dishes[left]] == 0:
            del dictionary[dishes[left]]
            
        dictionary[dishes[right % n]] += 1
        left += 1
        right += 1
        
    print(answer)
    
    return


if __name__ == "__main__":
    input = sys.stdin.readline
    
    n, d, k, c = map(int, input().split())
    dishes = [int(input()) for _ in range(n)]
    
    solve()