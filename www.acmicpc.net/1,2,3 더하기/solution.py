import sys

def solution():
    input_number = []
    test_case = 0
    test_case = int(input())
    # dp값 1, 2, 3
    dp = [1, 2, 4]
    # 경우의 수에 따른 값 입력
    for _ in range(test_case):
        input_number.append(int(input()))

    
    for i in range(3, max(input_number)):
        dp.append(dp[i - 1] + dp[i - 2] + dp[i - 3])

    for i in input_number:
        print(dp[i - 1])


solution()
