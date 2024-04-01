def solution(n, tops):
    MOD_VALUE = 10007
    
    a = [0] * (n + 1)
    b = [0] * (n + 1)
    b[0] = 1
    
    for index in range(1, n + 1):
        if tops[index - 1] == 1 :
            a[index] = (a[index - 1] + b[index - 1]) % MOD_VALUE
            b[index] = (2 * a[index - 1] + 3 * b[index - 1]) % MOD_VALUE
        elif tops[index - 1] == 0:
            a[index] = (a[index - 1] + b[index - 1]) % MOD_VALUE
            b[index] = (a[index - 1] + 2 * b[index - 1]) % MOD_VALUE
            
    
    return (a[n] + b[n]) % MOD_VALUE