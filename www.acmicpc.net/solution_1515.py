numbers = str(input())
find_number = 0

while True:
    find_number += 1
    find_number_str = str(find_number)

    while 0 < len(find_number_str) and 0 < len(numbers):
        if numbers[0] == find_number_str[0]:
            numbers = numbers[1:]
        
        find_number_str = find_number_str[1:]

    if numbers == '':
        print(find_number)
        exit()
