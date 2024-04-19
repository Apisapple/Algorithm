def solution(scores):
    answer = 1

    wonHo_point_a, wonHo_point_b = scores[0]
    wonHo_total_point = wonHo_point_a + wonHo_point_b
    
    scores.sort(key=lambda x: (-x[0], x[1]))
    max_b = 0
    
    for a, b in scores:
        if wonHo_point_a < a and wonHo_point_b < b:
            return -1
        
        if max_b <= b:
            max_b = b
            if wonHo_total_point < a + b:
                answer += 1    
    
    return answer


print(solution([[2, 2], [1, 4], [3, 2], [3, 2], [2, 1]]))
