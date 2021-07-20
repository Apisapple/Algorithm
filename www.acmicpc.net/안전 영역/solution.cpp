#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

int boardSize = 0, maxValue = 0, result = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<int>> board(MAX + 1, vector<int>(MAX + 1, 0));
void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

void DFS(int x, int y, int dept, vector<vector<bool>> &visited) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= boardSize || ny >= boardSize) 
            continue;
        if(board[nx][ny] <= dept || visited[nx][ny])
            continue;

        visited[nx][ny] = true;
        DFS(nx, ny, dept, visited);
    }
}

int main(int argc, char const *argv[]) {
    initSolution();

    cin >> boardSize;


    // board 정보 입력
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            cin >> board[i][j];
            maxValue = max(maxValue, board[i][j]);
        }
    }

    for(int i = 0; i < maxValue; i++) {
        int cnt = 0;
        vector<vector<bool>> visited(MAX + 1, vector<bool>(MAX + 1, false));

        for(int j = 0; j < boardSize; j++) {
            for(int k = 0; k < boardSize; k++) {
                if(board[j][k] > i && !visited[j][k]) {
                    visited[j][k] = true;
                    cnt ++;
                    DFS(j, k, i, visited);
                }
            }
        }
        result = max(cnt, result);
    }
    cout << result << '\n';

    return 0;
}
