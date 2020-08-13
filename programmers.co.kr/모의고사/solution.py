def solution(answers = [1, 2, 3, 4, 5]):
    answer = []
    first_persion = [1, 2, 3, 4, 5]
    second_persion = [2,1, 2, 3, 2, 4, 2, 5]
    third_persion = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    first_count = 0
    second_count = 0
    third_count = 0

    for i in range(len(answers)):
        first_index = (i % len(first_persion))
        second_index = (i % len(second_persion))
        third_index = (i % len(third_persion))
        if(answer[i] == first_persion[first_index]):
            first_count += 1
        if(answer[i] == second_persion[second_index]):
            second_count += 1
        if(answer[i] == third_persion[third_index]):
            third_count += 1

    max_count = max(first_count, max(second_count, third_count))
    if(max_count == first_count):
        answer.append(1)
    if(max_count == second_count):
        answer.append(2)
    if(max_count == third_count):
        answer.append(3)
    return answer



solution([1, 2, 3, 4, 5])