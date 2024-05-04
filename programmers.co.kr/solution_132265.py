def solution(topping):
    answer = 0

    old = {}
    young = {}
    
    for t in topping:
        if t in old:
            old[t] += 1
        else :
            old[t] = 1
            
    for t in topping:
        if len(young) == len(old):
            answer += 1
            
        if t not in young:
            young[t] = 1
        
        old[t] -= 1
        
        if old[t] == 0:
            del old[t]

    return answer


print(solution([1, 2, 1, 3, 1, 4, 1, 2]))
print(solution([1, 2, 3, 1, 4]))
