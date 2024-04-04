directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]


def solution(grid):
    answer = []

    max_height, max_width = len(grid), len(grid[0])
    visited = [[[False] * 4 for _ in range(max_width)] for _ in range(max_height)]
    
    for height in range(max_height):
        for width in range(max_width):
            
            for index in range(4):
                
                if visited[height][width][index]:
                    continue
                
                dept = 0
                next_height, next_width = height, width
                
                while not visited[next_height][next_width][index]:
                    visited[next_height][next_width][index] = True
                    dept += 1
                    
                    if grid[next_height][next_width] == "S":
                        pass
                    elif grid[next_height][next_width] == "L":
                        index = (index - 1) % 4
                    elif grid[next_height][next_width] == "R":
                        index = (index + 1) % 4
                        
                    next_height = (next_height + directions[index][0]) % max_height
                    next_width = (next_width + directions[index][1]) % max_width
                    
                
                answer.append(dept)
                
    answer = sorted(answer)
    return answer


print(solution(["SL", "LR"]))
print(solution(["S"]))
print(solution(["R", "R"]))
