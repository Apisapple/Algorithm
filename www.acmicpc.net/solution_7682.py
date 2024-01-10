import sys

input = sys.stdin.readline

def solution() :
    while True:
        data = input().strip()
        if checkTheEnd(data):
            break
        
        answer = checkValidData(data)
        if answer :
            print("valid")
        else :
            print("invalid")
    

def checkTheEnd(data) :
    return data == "end"

def checkValidData(data) :
    arr = [[0] * 3 for _ in range(3)]
    x_count, o_count, index = 0, 0, 0
    
    for i in range(3):
        for j in range(3):
            arr[i][j] = data[index]
            
            if data[index] == "X":
                x_count += 1
            if data[index] == "O":
                o_count += 1
                
            index += 1
            
    if x_count > o_count + 1 :
        return False
    
    if o_count > x_count :
        return False
    
    if o_count == x_count :
        if flag(arr, "O") and not flag(arr, "X"):
            return True
        
    if o_count + 1 == x_count :
        if flag(arr, "X") and not flag(arr, "O"):
            return True

    if x_count == 5 and o_count == 4:
        if not flag(arr, "O"):
            return True

    return False
        
def flag(arr, symbol):    
    if arr[0][0]==arr[0][1]==arr[0][2]==symbol:
        return True
    if arr[1][0]==arr[1][1]==arr[1][2]==symbol:
        return True
    if arr[2][0]==arr[2][1]==arr[2][2]==symbol:
        return True
    if arr[0][0]==arr[1][0]==arr[2][0]==symbol:
        return True
    if arr[0][1]==arr[1][1]==arr[2][1]==symbol:
        return True
    if arr[0][2]==arr[1][2]==arr[2][2]==symbol:
        return True
    if arr[0][0]==arr[1][1]==arr[2][2]==symbol:
        return True
    if arr[2][0]==arr[1][1]==arr[0][2]==symbol:
        return True
    return False

solution()