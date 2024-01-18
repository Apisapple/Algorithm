import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

def solution(data, boom_word) :

    stack = []
    boom_word_len = len(boom_word)
    
    for d in range(len(data)):
        stack.append(data[d])
        
        if ''.join(stack[-boom_word_len:]) == boom_word:
            for _ in range(boom_word_len):
                stack.pop()
    
    if stack:
        print(*stack, sep='')
    else:
        print("FRULA")

plain_text = input().rstrip()
boom_word = input().rstrip()

solution(plain_text, boom_word)