def count_edges(edges):
    line_count = {}
    for a, b in edges:
        if not line_count.get(a):
            line_count[a] = [0, 0]
            
        if not line_count.get(b):
            line_count[b] = [0, 0]
            
        line_count[a][0] += 1
        line_count[b][1] += 1
        
    return line_count

def check_answer(line_count):
    answer = [0, 0, 0, 0]
    
    for key, values in line_count.items():
        
        if 2 <= values[0] and values[1] == 0:
            answer[0] = key
        elif values[0] == 0 and values[1] > 0:
            answer[2] += 1
        elif 2 <= values[0] and 2 <= values[1]:
            answer[3] += 1
        
    answer[1] = (line_count[answer[0]][0] - answer[2] - answer[3])
    
    return answer


def solution(edges):
    line_count = count_edges(edges)
    answer = check_answer(line_count)
    return answer


print(solution([[2, 3], [4, 3], [1, 1], [2, 1]]))