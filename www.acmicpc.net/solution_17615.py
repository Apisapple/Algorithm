import sys

input = sys.stdin.readline

ball_count = int(input())
ball_array = str(input().strip())
answer = []

erase_right = ball_array.rstrip('R')
answer.append(erase_right.count('R'))

erase_right = ball_array.rstrip('B')
answer.append(erase_right.count('B'))

erase_left = ball_array.lstrip('R')
answer.append(erase_left.count('R'))

erase_left = ball_array.lstrip('B')
answer.append(erase_left.count('B'))

print(min(answer))