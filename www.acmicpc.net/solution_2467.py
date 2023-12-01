import sys

input = sys.stdin.readline

liquid_count = int(input())
liquid_list = list(map(int, input().split(' ')))

liquid_list.sort()

left = 0 
right = liquid_count - 1
total = 2e+9+1
answer = []

while left < right :
    liquid_left = liquid_list[left]
    liquid_right = liquid_list[right]
    mixed_liquid = liquid_left + liquid_right
    
    if abs(mixed_liquid) < total:
        total = abs(mixed_liquid)
        answer = [liquid_left, liquid_right]
        
    if mixed_liquid < 0:
        left += 1
    else :
        right -= 1
        
        
print(answer[0], answer[1])