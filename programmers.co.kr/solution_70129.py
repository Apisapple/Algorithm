def solution(s: str):
    answer = []

    convert_count = 0
    erase_count = 0

    while s != "1":
        erase_str = s.replace("0", "")
        erase_count += (len(s) - len(erase_str))
        binaryNumber = bin(len(erase_str))
        s = binaryNumber[2:]
        convert_count += 1
        
    answer.append(convert_count)
    answer.append(erase_count)
    return answer


print(solution("110010101001"))
print(solution("01110"))
print(solution("1111111"))
