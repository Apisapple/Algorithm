import sys

input = sys.stdin.readline

height, width = map(int, input().split())
input_data = list(map(int, input().split()))
answer = 0

for i in range(1, width - 1):
    left_max = max(input_data[:i])
    right_max = max(input_data[i + 1:])
    
    compare_data = min(left_max, right_max)
    
    if input_data[i] < compare_data:
        answer += compare_data - input_data[i]
        
print(answer)