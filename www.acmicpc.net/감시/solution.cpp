#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 8
#define INF 987654321

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}}; //right, up, left, down
int N, M;
int result;
int room[MAX][MAX], copyRoom[MAX][MAX];

vector<pair<int, int>> camera;

vector<int> angle; //카메라 각도

bool visited[MAX][MAX][4]; //{y, x}, 해당 방향으로 비출 것인가

void copy()
{

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            copyRoom[i][j] = room[i][j];
}

int numOfBlindSpot(void)
{

    int result = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (copyRoom[i][j] == 0)
                result++;

    return result;
}

void DFS(int cnt)
{

    if (cnt == camera.size())
    {
        for (int i = 0; i < angle.size(); i++)
        {
            int y = camera[i].first;
            int x = camera[i].second;

            for (int j = 0; j < 4; j++)
                if (visited[y][x][j])
                {
                    int nextY = y + moveDir[(angle[i] + j) % 4].y;
                    int nextX = x + moveDir[(angle[i] + j) % 4].x;
                    while (1)
                    {
                        if (copyRoom[nextY][nextX] == 6)
                            break;

                        if (!(0 <= nextY && nextY < N && 0 <= nextX && nextX < M))
                            break;

                        if (copyRoom[nextY][nextX] == 0)
                            copyRoom[nextY][nextX] = -1;

                        nextY += moveDir[(angle[i] + j) % 4].y;
                        nextX += moveDir[(angle[i] + j) % 4].x;
                    }
                }
        }
        result = min(result, numOfBlindSpot());
        copy();
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        angle.push_back(i);
        DFS(cnt + 1);
        angle.pop_back();
    }
}

int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];

            if (1 <= room[i][j] && room[i][j] <= 5)
                camera.push_back({i, j});

            switch (room[i][j])
            {
            case 1:
                visited[i][j][0] = true;
                break;

            case 2:
                visited[i][j][0] = true;
                visited[i][j][2] = true;
                break;

            case 3:
                visited[i][j][0] = true;
                visited[i][j][1] = true;
                break;

            case 4:
                visited[i][j][0] = true;
                visited[i][j][1] = true;
                visited[i][j][2] = true;
                break;

            case 5:
                visited[i][j][0] = true;
                visited[i][j][1] = true;
                visited[i][j][2] = true;
                visited[i][j][3] = true;
                break;
            }
        }

    result = INF;
    copy();
    DFS(0);
    cout << result << "\n";

    return 0;
}
