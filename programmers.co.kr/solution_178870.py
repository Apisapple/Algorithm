def solution(sequence, k):
    answer = [0, 0]
    sequence_len = len(sequence)
    min_length = sequence_len + 1
    left_index, right_index, total = 0, 0, sequence[0]

    while left_index <= right_index < sequence_len:

        if total == k:
            current_len = right_index - left_index + 1
            if current_len < min_length:
                min_length = current_len
                answer = [left_index, right_index]
                
            total -= sequence[left_index]
            left_index += 1
            
        elif total < k:
            right_index += 1
            if right_index < sequence_len:
                total += sequence[right_index]
                
        elif k < total:
            total -= sequence[left_index]
            left_index += 1

    return answer


print(solution([1, 2, 3, 4, 5], 7))
print(solution([1, 1, 1, 2, 3, 4, 5], 5))
print(solution([2, 2, 2, 2, 2], 6))
