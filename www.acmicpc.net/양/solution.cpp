#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX 250

int r = 0, c = 0;
int resultSheep = 0, resultWolf = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<string> board(MAX);
vector<vector<bool>> visited(MAX, vector<bool> (MAX, false));

void BFS(int x, int y) {
    int aliveWolf = 0, aliveSheep = 0;
    queue<pair<int ,int>> que;
    que.push(make_pair(x, y));
    visited[x][y] = true;

    while(!que.empty()) {
        int current_x = que.front().first;
        int current_y = que.front().second;
        que.pop();

        if(board[current_x][current_y] == 'v')
            aliveWolf ++;
        else if(board[current_x][current_y] == 'o') 
            aliveSheep ++;

        for(int i = 0; i < 4; i++) {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];

            if(0 <= next_x && next_x < r && 0 <= next_y && next_y < c) {
                if(board[next_x][next_y] != '#' && !visited[next_x][next_y]) {
                    visited[next_x][next_y] = true;
                    que.push(make_pair(next_x, next_y));
                }
            }
        }
    }

    if(aliveSheep > aliveWolf)
        resultSheep += aliveSheep;
    else
        resultWolf += aliveWolf;
}
int main() {
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        cin >> board[i];
    }

    for(int i = 0; i < r; i ++) {
        for(int j = 0; j < c; j++) {
            if(!visited[i][j]) {
                BFS(i, j);
            }
        }
    }

    cout << resultSheep << ' ' << resultWolf;
    return 0;
}