#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 전역변수 선연
int width, height;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(vector<vector <int> > &board) {
    queue <pair<int, int>> que;
    // board에 익은 토마토들 내용 입력
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(board[i][j] == 1) {
                que.push(make_pair(i, j));
            }
        }
    }

    // 완전 탐색 시작
    while(!que.empty()) {
        pair <int, int> current = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int next_x = current.second + dx[i];
            int next_y = current.first + dy[i];
            if(0 <= next_x && next_x < width && 0 <= next_y && next_y < height && board[next_y][next_x] == 0) {
                que.push(make_pair(next_y, next_x));
                board[next_y][next_x] = board[current.first][current.second] + 1;
            }
        }
    }
}

int main() {
    int answer = -1;
    // 보드판 입력
    cin >> width >> height;
    vector <vector <int> > board(height, vector <int> (width, 0));
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cin >> board[i][j];
        }
    }
    // 완전 탐색
    dfs(board);
    // 내용 출력 확인
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(board[i][j] == 0) {
                anwer = -1;
                cout << answer << endl;
                return 0;
            } else {
                if(board[i][j] > answer)
                    answer = board[i][j];
            }
        }
    }
    cout << answer - 1 << endl;

    return 0;
}