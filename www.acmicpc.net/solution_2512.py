import sys

country_count = int(input())
countries_budget = list(map(int, input().split()))
total_budget = int(input())

start, end = 0, max(countries_budget)

while start <= end:
    max_budget = (start + end) // 2
    sum = 0

    for request_budget in countries_budget:
        if request_budget <= max_budget:
            sum += request_budget
        else:
            sum += max_budget

    if sum <= total_budget:
        start = max_budget + 1
    else:
        end = max_budget - 1

print(end)
