import sys

input=sys.stdin.readline

t = int(input())

for _ in range(t) :
    phone_count = int(input())
    
    phone_numbers = []
    for _ in range(phone_count):
        phone_numbers.append(input().rstrip())
    
    phone_numbers.sort()
    
    flag = False
    for i in range(len(phone_numbers) - 1):
        if phone_numbers[i] in phone_numbers[i + 1][:len(phone_numbers[i])]:
            print("NO")
            flag = True
            break
    
    if flag == False:
        print("YES")
        