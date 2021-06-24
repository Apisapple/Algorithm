#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

vector<vector<int>> board(MAX + 1, vector<int>(MAX + 1, 0));
vector<vector<bool>> visited(MAX + 1, vector<bool>(MAX + 1, 0));
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n = 0, m = 0, k = 0, cnt = 0;

void initSolution() {

    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

}

void DFS(int x, int y) {
    visited[x][y] = true;
    cnt ++;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || n <= nx || m <= ny)
            continue;
        if(board[nx][ny] == 0 && !visited[nx][ny]) {
            DFS(nx, ny);
        }
    }
}

int main() {
    vector<int> result;
    initSolution();

    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int lx, ly, rx, ry;
        cin >> ly >> lx >> ry >> rx;

        for(int i = lx; i < rx; i ++) {
            for(int j = ly; j < ry; j++) {
                board[i][j] = 1;
                visited[i][j] = true; 
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j ++) {
            if(board[i][j] == 0 && !visited[i][j]) {
                cnt = 0;
                DFS(i, j);
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }

    return 0;
}