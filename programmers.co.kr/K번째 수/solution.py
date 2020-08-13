def solution(array, commands):
    answer = []

    for command in commands:
        temp = array
        temp = temp[(command[0]-1):command[1]]
        temp.sort()
        answer.append(temp[command[2] - 1])
    return answer