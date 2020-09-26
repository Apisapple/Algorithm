import sys

# Link : https://www.acmicpc.net/problem/10972

def next_permutation(arr):
    """[다음 순열을 반환하는 함수]

    Args:
        arr ([list]): [입력되는 순열]
    """
    list_len = len(arr)
    next_arr = [0] * list_len
    
    # 마지막 순열( 내림차순 정렬일 경우 -1 반환)
    i = list_len - 1
    while i > 0 and arr[i - 1] >= arr[i]:
        i -= 1
    if(i == 0):
        return False

    # 마지막 순열이 아니라면..
    j = list_len - 1
    while arr[i - 1] >= arr[j] :
        j -= 1

    arr[i - 1], arr[j] = arr[j], arr[i - 1]

    j = list_len - 1
    while i < j:
        arr[i], arr[j] = arr[j], arr[i]
        i += 1
        j -= 1

    return True

def solution():
    """[main 함수]
    """
    # 순열 숫자 갯수 입력
    input_value = int(input())
    #  순열 입력
    
    number_list = list(map(int, input().split()))

    if next_permutation(number_list) :
        print(' '.join(map(str, number_list)))

    else :
        print(-1)



solution()