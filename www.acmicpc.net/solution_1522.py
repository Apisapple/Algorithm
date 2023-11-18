import sys 

input = sys.stdin.readline

input_data = list(input().strip())
windows_size = input_data.count('a')
answer = len(input_data) - windows_size

for i in range(len(input_data)):
    count = 0
    
    for j in range(windows_size):
        current = (i + j) % len(input_data)
        
        if input_data[current] == 'b':
            count += 1
            
    answer = min(answer, count)
    
    
print(answer)