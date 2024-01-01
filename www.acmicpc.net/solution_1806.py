import sys

input=sys.stdin.readline

n, s = map(int, input().split())
numbers = list(map(int, input().split()))
answer = sys.maxsize

left, right = 0, 0
total = 0

while True:
    if total >= s:
        answer = min(answer, right - left)
        total -= numbers[left]
        left += 1
    elif right == n:
        break
    else:
        total += numbers[right]
        right += 1
        
if answer == sys.maxsize:
    print(0)
else:
    print(answer)
