from sys import stdin, stdout

def solution(value):
    for i in range(len(value) - 2, -1, -1):
        if s[i] == ']':
            print('[]', end='')
        elif s[i] == '[':
            continue
        elif s[i] in '&*':
            print(s[i], end='')
        else:
            print(' ', end='')
            for j in range(0, i+1):
                print(s[j], end='')
            print(';')
            return


dataType , *values = input().split()
for s in values:
    print(dataType, end='')
    # print(s)
    solution(s)

