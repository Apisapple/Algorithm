import sys

input = sys.stdin.readline

title_cnt, character_cnt = map(int, input().split())
title = [input().split() for _ in range(title_cnt)]
title.sort(key=lambda x: int(x[1]))

combat_powers = [int(input().strip()) for _ in range(character_cnt)]

for combat_power in combat_powers:
    right_index = len(title)
    left_index = 0
    result = 0
    
    while left_index <= right_index:
        middle_index = (right_index + left_index) // 2
        
        if combat_power <= int(title[middle_index][1]):
            result = middle_index
            right_index = middle_index - 1
            
        else:
            left_index = middle_index + 1
            
    
    print(title[result][0])