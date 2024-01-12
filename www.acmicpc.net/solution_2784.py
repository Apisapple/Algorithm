import sys

input = sys.stdin.readline
answer = []

def solution():
    datas = [input().rstrip() for _ in range(6)]
    
    if is_possible(datas):
        global answer
        
        for i in range(0, 10, 3):
            print(answer[0][i : i + 3])
    else:
        print(0)
        
def is_possible(datas):
    global answer
    
    make_board(datas)
    return len(answer) != 0
        
def make_board(datas):
    global answer
    
    for first in range(6):
        for second in  range(6):
            for third in range(6):
                
                if first == second or first == third or second == third:
                    continue
                
                temp = [datas[first], datas[second], datas[third]]
                temp2 = temp.copy()
                
                for i in range(3):
                    temp2.append(temp[0][i] + temp[1][i] + temp[2][i])
                    
                temp2.sort()
                if datas == temp2:
                    answer.append(temp[0] + temp[1] + temp[2])
                    
    answer.sort()    


solution()