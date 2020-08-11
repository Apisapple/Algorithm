people = []
for i in range(9):
    people.append(int(input()))
result = sum(people)
people.sort()
for i in range(9):
    for j in range(i + 1, 9):
        if (result - people[i] - people[j]) == 100:
            for p in range(len(people)):
                if p == i or p == j:
                    continue
                else:
                    print(people[p])
                
            exit()