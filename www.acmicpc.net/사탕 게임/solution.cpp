#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 51

int N = 0, answer = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<string> board(MAX);
vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));

void InitSolution() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void checkColumnCandy() {
    for(int i = 0; i < N; i++) {
        int cnt = 1;
        for(int j = 0; j < N; j++) {
            if(board[i][j] == board[i][j + 1]) {
                cnt++;
            } else {
                answer = max(answer, cnt);
                cnt = 1;
            }
        }
    }
}

void checkRowCandy() {
    for(int i = 0; i < N; i++) {
        int cnt = 1;
        for(int j = 0; j < N; j++) {
            if(board[j][i] == board[j + 1][i]){
                cnt ++;
            } else {
                answer = max(answer, cnt);
                cnt = 1;
            }
        }
    }
}

int main() {
    InitSolution();

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> board[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - 1; j++) {
            swap(board[i][j], board[i][j + 1]);
            checkColumnCandy();
            checkRowCandy();
            swap(board[i][j], board[i][j + 1]);

            swap(board[j][i], board[j + 1][i]);
            checkColumnCandy();
            checkRowCandy();
            swap(board[j][i], board[j + 1][i]);

        }
    }

    cout << answer << '\n';
    return 0;
}