import sys, itertools

input = sys.stdin.readline

n, k = map(int, input().split())

word_bitmask = [0] * n
answer = 0

for i in range(n):
    temp_str = input().rstrip()

    for str in temp_str:
        word_bitmask[i] |= (1 << (ord(str) - ord('a')))


if k < 5:
    print(0)
else:
    candidiate = ['b','d','e','f','g','h','j','k','l','m','o','p','q','r','s','u','v','w','x','y','z']
    need = ['a','c','t','i','n']
    for i in list(itertools.combinations(candidiate, k - 5)):
        each = 0
        res = 0
        for j in need:
            each |= (1 << (ord(j) - ord('a')))
        for j in i:
            each |= (1 << (ord(j) - ord('a')))
            
        for j in word_bitmask:
            if each & j == j:
                res += 1
                
        if answer < res:
            answer = res
    print(answer)