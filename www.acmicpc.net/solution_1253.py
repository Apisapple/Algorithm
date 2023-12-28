import sys

input=sys.stdin.readline

n = int(input())
numbers = list(map(int, input().split()))
numbers.sort()
answer = 0

for i in range(n):
    temp = numbers[:i] + numbers[i + 1 :]
    left, right = 0, len(temp) - 1
    
    while left < right:
        t = temp[left] + temp[right]
        if t == numbers[i]:
            answer += 1
            break
        
        if t < numbers[i]:
            left += 1
        else :
            right -= 1
            
print(answer)