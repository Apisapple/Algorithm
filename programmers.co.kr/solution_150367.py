def solution(numbers):
    answer = []
    
    for number in numbers:
        binary_number = bin(number)[2:]
        nodes = bin(len(binary_number) + 1)[2:]
        
        if '1' in nodes[1:]:
            dummy_datas = (1 << len(nodes)) - int(nodes, 2)
            binary_number = '0' * dummy_datas + binary_number
        
        
        def dfs(binary, index, dept):
            if dept == 0:
                return True
            
            elif binary[index] == '0':
                if binary[index - dept] == '1' or binary[index + dept] == '1':
                    return False
                
            left = dfs(binary, index - dept, dept // 2)
            right = dfs(binary, index + dept, dept // 2)
            
            return left and right
        
        result = dfs(binary_number, len(binary_number) // 2, (len(binary_number)+1)//4)
        answer.append(1 if result else 0)
    
    return answer


print(solution([7, 42, 5]))
print(solution([63, 111, 95]))
