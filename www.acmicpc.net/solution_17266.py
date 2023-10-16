n = int(input())
m = int(input())

light_positions = list(map(int, input().split()))
positions_size = len(light_positions)

min_height = 0

if positions_size == 1:
    min_height = max(light_positions[0] - 0, n - light_positions[0])
    
else:
    for i in range(positions_size) :
        if i == 0:
            height = light_positions[i] - 0
        elif i == positions_size - 1:
            height = n - light_positions[i]
        else:
            temp = light_positions[i] - light_positions[i - 1]
            if temp % 2 :
                height = temp // 2 + 1
            else:
                height = temp // 2
                
        min_height = max(height, min_height)    
        
        
print(min_height)
