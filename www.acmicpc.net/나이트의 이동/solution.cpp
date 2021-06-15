#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 300

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int testCase = 0, boardSize = 0;
int start_x = 0, start_y = 0;
int target_x = 0, target_y = 0;

void BFS(vector<vector<int>> &board, vector<vector<bool>> &visited) {
    queue<pair<int, int>> que;
    que.push(make_pair(start_x, start_y));
    visited[start_x][start_y] = true;

    while(!que.empty()) {
        int current_x = que.front().first;
        int current_y = que.front().second;
        que.pop();

        if(current_x == target_x && current_y == target_y) {
            cout << board[current_x][current_y] << '\n';
            break;
        }

        for(int i = 0; i < 8; i++) {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];

            if(0 <= next_x && next_x < boardSize && 0 <= next_y && next_y < boardSize) {
                if(!visited[next_x][next_y]) {
                    visited[next_x][next_y] = true;
                    board[next_x][next_y] = board[current_x][current_y] + 1;
                    que.push(make_pair(next_x, next_y));
                }
            }
        }
    }

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> testCase;
    while(testCase --) {
        cin >> boardSize;
        vector<vector<int>> board(boardSize, vector<int>(boardSize , 0));
        vector<vector<bool>> visited(boardSize, vector<bool>(boardSize, false));

        cin >> start_x >> start_y;
        cin >> target_x >> target_y;

        BFS(board, visited);
    }




    return 0;
}