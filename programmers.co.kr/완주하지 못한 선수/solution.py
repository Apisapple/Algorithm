def solution(participant, completion):
    answer = ''
    participant.sort()
    completion.sort()
    
    for i in range(len(participant)):
        if(participant[i] == completion[i]):
            participant.remove(i)
            completion.remove(i)

    answer= participant

    return answer