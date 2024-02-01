import sys

input = sys.stdin.readline

command_count = int(input())
commands = [list(input().split()) for _ in range(command_count)]

deque = []

for command in commands:
    if 'push_front' in command[0]:
        deque.insert(0, command[1])
    elif 'push_back' in command[0]:
        deque.append(command[1])
    elif 'pop_front' in command:
        print(deque.pop(0)) if deque else print(-1)
    elif 'pop_back' in command:
        print(deque.pop(-1)) if deque else print(-1)
    elif 'size' in command:
        print(len(deque))
    elif 'empty' in command:
        print(0) if deque else print(1)
    elif 'front' in command:
        print(deque[0]) if deque else print(-1)
    elif 'back' in command:
        print(deque[-1]) if deque else print(-1)