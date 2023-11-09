import sys

input = sys.stdin.readline

number_count, condition_value = map(int, input().split())
numbers = list(map(int, input().split()))
numbers_count = [0] * (max(numbers) + 1)
left, right, answer = 0, 0, 0

while right < number_count:
    if numbers_count[numbers[right]] < condition_value:
        numbers_count[numbers[right]] += 1
        right += 1
    
    else :
        numbers_count[numbers[left]] -= 1
        left += 1
        
    answer = max(answer, right - left)
    
print(answer)