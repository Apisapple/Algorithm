#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100

vector<vector<int>> board(MAX + 1, vector<int>(MAX + 1, 0));
queue<pair<int, int>> que;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int height, width, cnt, result, lastCnt;

void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int getCheeseCnt() {
    int returnValue = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(board[i][j] == 1)
                returnValue ++;
        }
    }
    return returnValue;
}

int main() {
    
    cin >> height >> width;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cin >> board[i][j];
        }
    }

    while (true)
    {
        lastCnt = getCheeseCnt();
        if(lastCnt == 0)
            break;
        else {
            cnt ++;
            result = lastCnt;
        }
        vector<vector<bool>> visited(MAX + 1, vector<bool>(MAX + 1, false));
        lastCnt = 0;

        que.push(make_pair(0 ,0));
        visited[0][0] = true;

        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >=0 && ny >= 0 && nx < height && ny < width && !visited[nx][ny]) {
                    if (board[nx][ny] == 0)
                            que.push({nx, ny});
                    else if (board[nx][ny] == 1)
                            board[nx][ny] = 0;

                    visited[nx][ny] = true;
                }
            }
        }
    }
    
    cout << cnt << '\n' << result << '\n';

    return 0;
}