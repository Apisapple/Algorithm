#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
#define MAX 50
/* 
    비어있는 곳 : '.'
    물이 차있는 곳 :  '*'
    돌이 있는 곳 : 'X'
    비버의 굴 : 'D'
    고슴도치의 위치 : 'S'
    */

vector<vector<char>> board(MAX + 1, vector<char>(MAX + 1));
vector<vector<bool>> visited(MAX + 1, vector<bool>(MAX + 1, false));
queue<pair<int, int>> start;
queue<pair<int, int>> water;
string imposibble = "KAKTUS";
int targetX = 0, targetY = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r, c;

void BFS() {
    int result = 0;
    while(!start.empty()) {
        result ++;
        int waterSize = water.size();
        while(waterSize --) {
            int curX = water.front().first;
            int curY = water.front().second;
            water.pop();
            for(int i = 0; i < 4; i ++) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                if(nextX < 0 || r <= nextX || nextY < 0 || c <= nextY)
                    continue;
                if(board[nextX][nextY] == 'X' || board[nextX][nextY] == 'D' || board[nextX][nextY] == '*')
                    continue;
                water.push(make_pair(nextX, nextY));
                board[nextX][nextY] = '*';
            }
        }

        int startSize = start.size();
        while(startSize --) {
            int curX = start.front().first;
            int curY = start.front().second;
            start.pop();

            visited[curX][curY] = true;
            if(curX == targetX && curY == targetY) {
                cout << result - 1 << endl;
                return;
            }
            for(int i = 0; i < 4; i ++) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];

                if(nextX < 0 || r <= nextX || nextY < 0 || c <= nextY)
                    continue;
                
                if(board[nextX][nextY] == 'X' || board[nextX][nextY] == '*' || visited[nextX][nextY])
                    continue;

                visited[nextX][nextY] = true;
                start.push(make_pair(nextX, nextY));
            }
        }
    }
    cout << imposibble << endl;
    return;
}
int main() {

    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'S'){
                start.push(make_pair(i, j));
            }else if(board[i][j] == 'D'){
                targetX = i, targetY = j;
            }else if(board[i][j] == '*') {
                water.push(make_pair(i, j));
            }
        }
    }

    BFS();

    return 0;
}