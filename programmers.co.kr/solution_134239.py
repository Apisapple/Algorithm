def solution(k, ranges):

    def get_ubak_numbers(k):
        result = []

        while k != 1:
            result.append(k)
            k = k / 2 if k % 2 == 0 else k * 3 + 1

        result.append(k)
        return result

    answer = []

    ubak_numbers = get_ubak_numbers(k)

    for range_index in ranges:
        total = 0
        ubak_range = ubak_numbers[range_index[0] : len(ubak_numbers) + range_index[1]]

        if range_index[0] >= range_index[1] + len(ubak_numbers):
            answer.append(-1)
            continue

        for i in range(len(ubak_range) - 1):
            total += ((ubak_range[i] + ubak_range[i + 1]) * 1) / 2

        answer.append(total)

    return answer


print(solution(5, [[0, 0], [0, -1], [2, -3], [3, -3]]))
print(solution(3, [[0, 0], [1, -2], [3, -3]]))
