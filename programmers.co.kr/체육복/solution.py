def solution(n, lost, reserve):
    answer = 0
    count = list(set(lost) & set(reserve))
    lost2 = list(set(lost) - set(reserve))
    reserve2 = list(set(reserve) - set(lost))

    for i in lost2:
        if(i - 1 in reserve2) :
            count += [i]
            reserve2.remove(i - 1)
        elif(i + 1 in reserve2) :
            count += [i]
            reserve2.remove(i + 1)

    answer = n - (len(lost) - len(count))
    return answer