import sys

input = sys.stdin.readline

number_of_person = int(input())
people_height = list(map(int, input().split()))
answer = [0] * number_of_person

for i in range(number_of_person):
    zero_count = 0
    
    for j in range(number_of_person):
        if zero_count == people_height[i] and answer[j] == 0:
            answer[j] = i + 1
            break
        
        elif(answer[j] == 0):
            zero_count += 1
            
print(*answer)