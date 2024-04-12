from collections import deque

def solution(x, y, n):
    answer = 0
    dp = set()
    dp.add(x)
    
    while dp:
        if y in dp:
            return answer
        else :
            dp_y = set()
            for current in dp:
                if current + n <= y:
                    dp_y.add(current + n)
                if current * 2 <= y:
                    dp_y.add(current * 2)
                if current * 3 <= y:
                    dp_y.add(current * 3)
            
            dp = dp_y
            answer += 1
    
    return -1



print(solution(10, 40, 5))
print(solution(10, 40, 30))
print(solution(2, 5, 4))