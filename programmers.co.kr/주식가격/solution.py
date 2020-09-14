def solution(prices):

#   답안 배열 초기화
    size = len(prices)
    answer = [0] * size
    #  내용 탐색
    for i in range(size - 1):
        for j in range(i, size - 1):
            if(prices[i] > prices[j]):
                break
            else:
                answer[i] += 1
    
    return answer
