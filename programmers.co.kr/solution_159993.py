from collections import deque


def solution(maps):
    def search_path(start, end):
        dx = [0, 0, 1, -1]
        dy = [1, -1, 0, 0]

        height = len(maps)
        width = len(maps[0])
        visited = [[False] * width for _ in range(height)]
        que = deque()

        for i in range(height):
            for j in range(width):
                if maps[i][j] == start:
                    que.append((i, j, 0))
                    visited[i][j] = True
                    break

            else:
                continue
            break

        while que:
            cur_y, cur_x, cost = que.popleft()

            if maps[cur_y][cur_x] == end:
                return cost

            for i in range(4):
                next_y = cur_y + dy[i]
                next_x = cur_x + dx[i]

                if (
                    0 <= next_y < height
                    and 0 <= next_x < width
                    and maps[next_y][next_x] != "X"
                ):
                    if not visited[next_y][next_x]:
                        que.append((next_y, next_x, cost + 1))
                        visited[next_y][next_x] = True

        return -1

    start_to_lever = search_path("S", "L")
    lever_to_exit = search_path("L", "E")
    answer = -1

    if start_to_lever != -1 and lever_to_exit != -1:
        answer = start_to_lever + lever_to_exit

    return answer


print(solution(["SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"]))
print(solution(["LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO"]))
