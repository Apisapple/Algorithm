import sys

def changeBulb(a, b) :
    temp_a = a[:]
    answer = 0
    
    for i in range(1, n):
        
        if temp_a[i - 1] == b[i - 1]:
            continue
        
        answer += 1
        for j in range(i - 1, i + 2) :
            if j < n :
                temp_a[j] = 1 - temp_a[j]
                
    if temp_a == b:
        return answer
    else:
        return sys.maxsize


n=int(input())
current=list(map(int, input()))
target=list(map(int, input()))

result = changeBulb(current, target)
current[0] = 1 - current[0]
current[1] = 1 - current[1]

result = min(result, changeBulb(current, target) + 1)

if result != sys.maxsize:
    print(result)
else:
    print(-1)



