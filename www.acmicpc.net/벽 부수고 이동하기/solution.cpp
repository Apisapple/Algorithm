#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1000

vector<vector<int>> board(MAX, vector<int>(MAX, 0));
bool visited[MAX][MAX][2] = {false, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n = 0, m = 0;

int BFS(int x, int y) {
    queue<pair<pair<int, int>, pair<int, int>>> que;
    que.push(make_pair(make_pair(x, y), make_pair(0, 1)));
    visited[x][y][0] = true;
    
    while(!que.empty()) {
        int current_x = que.front().first.first;
        int current_y = que.front().first.second;
        int brokenInfo = que.front().second.first;
        int cntInfo = que.front().second.second;
        que.pop();

        if(current_x == n - 1 && current_y == m - 1) {
            return cntInfo;
        }

        for(int i = 0; i < 4; i++) {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];

            if(0 <= next_x && next_x < n && 0 <= next_y && next_y < m) {
                if(board[next_x][next_y] == 1 && brokenInfo == 0) {
                    visited[next_x][next_y][brokenInfo + 1] = true;
                    que.push(make_pair(make_pair(next_x, next_y), make_pair(brokenInfo + 1, cntInfo + 1)));
                } else if (board[next_x][next_y] == 0 && !visited[next_x][next_y][brokenInfo]){
                    visited[next_x][next_y][brokenInfo] = true;
                    que.push(make_pair(make_pair(next_x, next_y), make_pair(brokenInfo, cntInfo + 1)));
                }
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    // board 입력
    for(int i = 0; i < n; i++) {
        string temp = "";
        cin >> temp;
        for(int j = 0; j < m; j++) {
            board[i][j] = temp[j] - '0';
        }
    }

    BFS(0, 0);
    return 0;
}