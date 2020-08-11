#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int answer = 0;
int height = 0;
int width = 0;

void dfs(int x, int y, vector<vector<int>> board, vector<vector<bool>> &check_visit, int total, int count) {
    if(count > 3) {
        answer = max(answer , total);
        return;
    }
    for(int i = 0; i < 4; i ++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= height|| ny < 0 || ny >= width)
            continue;
        if(!check_visit[nx][ny]) {
            total += board[nx][ny];
            cout << "total : " << total << endl;
            check_visit[nx][ny] = true;
            dfs(nx, ny, board, check_visit, total, count + 1);
            check_visit[nx][ny] = false;
        }
    }
}

int solution(vector<vector<int>> board, vector<vector<bool>> &check_visit) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j ++) {
            int total = 0;
            total += board[i][j];
            check_visit[i][j] = true;
            dfs(i, j, board, check_visit, total, 1);
            check_visit[i][j] = false;
        }
    }
    return answer;
}

int main() {
    int result = 0;
    int total = 0;
    int temp = 0;
    cin >> height >> width;
    
    vector<vector<int>> board(height, vector<int>(width));
    vector<vector<bool>> check_visit(height, vector<bool>(width, false));
    for(int i = 0; i < height; i ++) {
        for(int j = 0; j < width; j ++) {
            cin >> temp;
            board[i][j] = temp;
        }
    }
    for(int i = 0; i < height; i ++) {
        for(int j = 0; j < width; j ++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    result = solution(board, check_visit);

    cout << result << endl;
    return 0;
}