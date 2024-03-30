def solution(h1, m1, s1, h2, m2, s2):
    answer = 0
    
    start_time = h1 * 3600 + m1 * 60 + s1
    end_time = h2 * 3600 + m2 * 60 + s2
    
    if start_time == 0 or start_time == 12 * 3600 :
        answer += 1
    
    while start_time < end_time :
        hour_angle = start_time / 120 % 360
        minute_angle = start_time / 10 % 360
        second_angle = start_time * 6 % 360
        
        next_hour_angle = 360 if (start_time + 1) / 120 % 360 == 0 else (start_time + 1) / 120 % 360
        next_minute_angle = 360 if (start_time + 1) / 10 % 360 == 0 else (start_time + 1) / 10 % 360
        next_second_angle = 360 if (start_time + 1) * 6 % 360 == 0 else (start_time + 1) * 6 % 360
        
        if second_angle < hour_angle and next_hour_angle <= next_second_angle :
            answer += 1
        if second_angle < minute_angle and next_minute_angle <= next_second_angle :
            answer += 1
            
        if next_second_angle == next_hour_angle and next_hour_angle == next_minute_angle:
            answer -= 1
            
        start_time += 1
    
    return answer