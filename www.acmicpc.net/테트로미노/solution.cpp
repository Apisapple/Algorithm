#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, ans = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(vector<vector<int>> &board, vector<vector<bool>> &visited, int x, int y, int cnt, int total) {
    if(cnt == 4) {
        ans = ans < total ? total : ans;
        return;
    } 
    for(int i = 0; i < 4; i ++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < N && 0 <= ny && ny < M) {
            if(!visited[nx][ny]) {
                visited[nx][ny] = true;
                DFS(board, visited, nx, ny, cnt + 1, total + board[nx][ny]);
                visited[nx][ny] = false;
            }
        }
    }
}
void checkingOH(vector<vector<int>> &board, int x, int y) {
     int sum = 0;
    //ㅗ
    if (x - 1 >= 0 && y + 2 < M) {
        sum = board[x][y] + board[x][y + 1] + board[x][y + 2] + board[x - 1][y + 1];
        ans = ans < sum ? sum : ans;
    }
    //ㅏ
    if (x + 2 < N && y + 1 < M) {
        sum = board[x][y] + board[x + 1][y] + board[x + 2][y] + board[x + 1][y + 1];
        ans = ans < sum ? sum : ans;
    }
    //ㅜ
    if (x + 1 < N && y + 2 < M) {
        sum = board[x][y] + board[x][y + 1] + board[x][y + 2] + board[x + 1][y + 1];
        ans = ans < sum ? sum : ans;
    }
    //ㅓ
    if (x + 2 < N && y - 1 >= 0) {
        sum = board[x][y] + board[x + 1][y] + board[x + 2][y] + board[x + 1][y - 1];
        ans = ans < sum ? sum : ans;
    }
}
int main() {
    cin >> N >> M;
    vector<vector<int>> board(N, vector <int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            visited[i][j] = true;
            DFS(board, visited, i, j, 1, board[i][j]);
            visited[i][j] = false;
            checkingOH(board, i, j);
        }
    }
    cout << ans << endl;
    return 0;
}