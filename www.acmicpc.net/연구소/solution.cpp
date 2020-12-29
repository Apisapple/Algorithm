#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define MAX 8

using namespace std;

int height = 0, width = 0;
int result = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<int>> board(MAX, vector<int>(MAX, 0));
vector<vector<int>> copy_board;
vector<pair<int, int>> que;

void BFS() {
    queue<pair<int, int>> copy_que;
    for(int i = 0; i < que.size(); i++) {
        copy_que.push(make_pair(que[i].first, que[i].second));
    }

    while(!copy_que.empty()) {
        int x = copy_que.front().first;
        int y = copy_que.front().second;
        copy_que.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= width || ny >= height)
                continue;

            if(copy_board[nx][ny] == 0) {
                copy_board[nx][ny] = 2;
                copy_que.push(make_pair(nx, ny));
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(copy_board[i][j] == 0)
                cnt++;
        }
    }
    result = max(result, cnt);
}

void makeWall(int cnt) {
    if(cnt == 3) {
        copy_board = board;           
        BFS();
        return;
    }

    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(board[i][j] == 0) {
                board[i][j] = 1;
                makeWall(cnt + 1);
                board[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> width >> height;

    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2)
                que.push_back(make_pair(i, j));
        }
    }

    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(board[i][j] == 0) {
                board[i][j] = 1;
                makeWall(1);
                board[i][j] = 0;
            }
        }
    }

    cout << result << endl;
    return 0;
}