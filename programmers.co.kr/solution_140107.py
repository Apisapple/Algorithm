import math

def solution(k, d):
    answer = 0
    
    for x in range(0, d + 1, k):
        distance = math.floor(math.sqrt(d * d - x * x))
        answer += (distance // k) + 1
    
    return answer


print(solution(2, 4))
print(solution(1, 5))