def solution(n, costs):
    costs.sort(key=lambda x: x[2])
    routes = set([costs[0][0], costs[0][1]])
    answer = costs[0][2]


    while n != len(routes) :
        for index, value in enumerate(costs[1:]):
            if value[0] in routes and value[1] in routes:
                continue
            
            if value[0] in routes or value[1] in routes:
                routes.update([value[0], value[1]])
                answer += value[2]
                costs[index + 1] = [-1, -1, -1]
                break

    return answer


print(solution(4, [[0, 1, 1], [0, 2, 2], [1, 2, 5], [1, 3, 1], [2, 3, 8]]))
