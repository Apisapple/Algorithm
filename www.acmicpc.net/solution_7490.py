import sys

input=sys.stdin.readline

def find_answer(target, number, text):
    if target == number:
        if eval(text.replace(" ", "")) == 0:
            return print(text)
        return
    
    
    next_number = target + 1

    str_empty = text + " " + str(next_number)
    find_answer(target + 1, number, str_empty)
    
    str_plus = text + "+" + str(next_number)
    find_answer(target + 1, number, str_plus)
    
    str_minus = text + "-" + str(next_number)
    find_answer(target + 1, number, str_minus)

test_count = int(input())

for _ in range(test_count):
    number = int(input())
    find_answer(1, number, "1")
    print()