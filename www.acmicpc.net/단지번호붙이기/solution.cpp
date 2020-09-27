#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 25

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(int x, int y, int &count, vector< vector<int> > &board, vector< vector<bool> > &visit) {
    visit[x][y] = true;
    count ++;
    for(int i = 0; i < 4; i ++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(0 <= next_x && next_x < board.size() && 0 <= next_y && next_y < board.size()) {
            if(!visit[next_x][next_y] && board[next_x][next_y] != 0) {
                DFS(next_x, next_y, count, board, visit);
            }
        }
    }
    return;
}

int main() {

    int N = 0;
    cin >> N;
    vector <int> answer;
    vector< vector<int> > board(N, vector<int>(N, 0));    
    vector< vector<bool> > visit(N, vector<bool>(N, false));
    // 단지 입력
    for(int i = 0; i < N; i ++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < N; j++) {
            board[i][j] = temp[j] - '0';
        }
    }
 
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] != 0 && !visit[i][j]) {
                int count = 0;
                DFS(i, j, count, board, visit);
                answer.push_back(count);
            }
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
    return 0;
}