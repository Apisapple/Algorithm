from collections import deque


def solution(land: list):
    height, width = len(land), len(land[0])
    answer = [0] * width
    visited = [[False] * width for _ in range(height)]
    search_dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    oil_info = []

    def search_oil_amount(x, y):

        que = deque([(x, y)])
        visited[x][y] = True
        count = 1
        oil_values = {y}

        while que:
            current_x, current_y = que.popleft()
            for dx, dy in search_dir:
                next_x = current_x + dx
                next_y = current_y + dy

                if (
                    0 <= next_x < height
                    and 0 <= next_y < width
                    and not visited[next_x][next_y]
                    and land[next_x][next_y] == 1
                ):
                    visited[next_x][next_y] = True
                    que.append((next_x, next_y))
                    count += 1
                    oil_values.add(next_y)

        return (oil_values, count)

    for x in range(height):
        for y in range(width):
            if land[x][y] and not visited[x][y]:
                oil_info.append(search_oil_amount(x, y))

    for oil, cnt in oil_info:
        for y in oil:
            answer[y] += cnt

    return max(answer)


print(
    solution(
        [
            [0, 0, 0, 1, 1, 1, 0, 0],
            [0, 0, 0, 0, 1, 1, 0, 0],
            [1, 1, 0, 0, 0, 1, 1, 0],
            [1, 1, 1, 0, 0, 0, 0, 0],
            [1, 1, 1, 0, 0, 0, 1, 1],
        ]
    )
)
print(
    solution(
        [
            [1, 0, 1, 0, 1, 1],
            [1, 0, 1, 0, 0, 0],
            [1, 0, 1, 0, 0, 1],
            [1, 0, 0, 1, 0, 0],
            [1, 0, 0, 1, 0, 1],
            [1, 0, 0, 0, 0, 0],
            [1, 1, 1, 1, 1, 1],
        ]
    )
)
