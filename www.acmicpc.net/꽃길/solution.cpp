#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 10

vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));
vector<vector<int>> board(MAX, vector<int>(MAX, 0));
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n = 0, result = -1;


void initSolution() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int calculation() {
    int total = 0, cnt = 0;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(visited[i][j]) {
                total += board[i][j];
                cnt ++;
                if(cnt == 15)
                    return total;
            }
        }
    }
}

void DFS(int cnt) {

    if(cnt == 3) {
        int temp = calculation();
        if(result == -1 || temp < result) {
            result = temp;
        }
        return;
    }

    for(int i = 1; i < n - 1; i ++) {
        for(int j = 1; j < n - 1; j++) {
            bool flag = true;
            for(int p = 0; p < 4; p++) {
                int nx = i + dx[p];
                int ny = j + dy[p];

                if(visited[nx][ny]) {
                    flag = false;
                    break;
                }
            }

            if(!flag)
                continue;

            visited[i][j] = true;
            for(int p = 0; p < 4; p++) {
                int nx = i + dx[p];
                int ny = j + dy[p];
                visited[nx][ny] = true;
            }

            DFS(cnt + 1);

            visited[i][j] = false;
            for(int p = 0; p < 4; p++) {
                int nx = i + dx[p];
                int ny = j + dy[p];
                visited[nx][ny] = false;
            }
        }
    }
}

int main() {

    initSolution();

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    DFS(0);

    cout << result << '\n';

    return 0;
}