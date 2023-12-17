import sys

number_of_children = int(input())
children = [0]
dp = [1] * (number_of_children + 1)

for _ in range(number_of_children):
    children.append(int(input()))
    

for i in range(1, number_of_children + 1):
    for j in range(1, i):
        if children[j] < children[i]:
            dp[i] = max(dp[i], dp[j] + 1)
            
print(number_of_children - max(dp))