def solution(numbers):
    answer = []
    templist = []
    for i in range(0, len(numbers)) :
        for j in range(i + 1, len(numbers)) :
            templist.insert(0, numbers[i] + numbers[j])
            
    answer = list(set(templist))
    answer.sort()
    return answer