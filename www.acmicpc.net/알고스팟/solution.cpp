#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define MAX 100

vector<vector<int>> board(MAX, vector<int>(MAX, 0));
vector<vector<int>> dist(MAX, vector<int>(MAX, 987654321));

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int width = 0, height = 0;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS(int x, int y) {

    queue<pair<int, int>> que;
    que.push(make_pair(x, y));
    dist[x][y] = 0;

    while(!que.empty()) {
        int cur_x = que.front().first;
        int cur_y = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(nx < 0 || ny < 0 || height <= nx || width <= ny)
                continue;

            if(board[nx][ny] == 1) {
                if(dist[nx][ny] > dist[cur_x][cur_y] + 1) {
                    dist[nx][ny] = dist[cur_x][cur_y] + 1;
                    que.push(make_pair(nx, ny));
                }
            } else if(board[nx][ny] == 0) {
                if(dist[nx][ny] > dist[cur_x][cur_y]) {
                    dist[nx][ny] = dist[cur_x][cur_y];
                    que.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    cin >> width;
    cin >> height;

    for(int i = 0; i < height; i++) {
        string temp = "";
        cin >> temp;
        for(int j = 0; j < width; j++) {
            board[i][j] = temp[j] - '0';
        }
    }

    BFS(0, 0);

    cout << dist[height - 1][width - 1] << '\n';
    
    return 0;
}