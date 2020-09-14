def solution(priorities, location):
    answer = 0
#   가장 큰 우선순위 값 확인
    max_priority = max(priorities)
    while True:
        priority = priorities.pop(0)
        if(max_priority == priority):
            answer += 1
            if(location == 0)
                break
            else:
                location -= 1
#   가장 높은 우선순위랑 값이 같은 경우
        else:
            priorities.append(priority)
            if(location==0)
                location = len(priorities) - 1
            else
                location -= 1

    return answer
