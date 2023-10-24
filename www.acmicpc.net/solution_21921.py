def get_sum_of_section(visit_count):
    sum_of_section = [0]
    for i in range(len(visit_count)):
        sum_of_section.append(sum_of_section[i] + visit_count[i])
        
    return sum_of_section


def get_answer(sum_of_section, N, X):
    left_index = 0
    right_index = X
    answer = 0
    period = 0

    while right_index <= N:
        sum_of_period = sum_of_section[right_index] - sum_of_section[left_index]

        if answer == sum_of_period:
            period += 1
        elif answer < sum_of_period:
            period = 1
            answer = sum_of_period

        right_index += 1
        left_index += 1
        
    return answer, period


N, X = map(int, input().split())
visit_count = list(map(int, input().split()))

sum_of_section = get_sum_of_section(visit_count)

answer, period = get_answer(sum_of_section, N, X)

if 0 < answer:
    print(answer)
    print(period)
else:
    print("SAD")