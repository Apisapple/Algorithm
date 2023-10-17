import sys

n, m = map(int, sys.stdin.readline().split())

memoriztion_book = {}
for i in range(n):
    word = sys.stdin.readline().strip()
    
    if m <= len(word):
        if word in memoriztion_book:
            memoriztion_book[word] += 1
        
        else :
            memoriztion_book[word] = 1
            
            
            
memoriztion_book = sorted(memoriztion_book.items(), key=lambda x:(-x[1], -len(x[0]), x[0]))

for word in memoriztion_book:
    print(word[0])