#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 200
// R개의 줄에 N 초 이후
int R = 0, C = 0, N = 0;

vector<vector<int>> boomerTime(MAX, vector<int>(MAX, 0));
vector<string> board(MAX);
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void releaseBoomer(int timer) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(boomerTime[i][j] == timer) {
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(0 <= nx && nx < R && 0 <= ny && ny < C) {
                        if(board[nx][ny] == '.')
                            continue;
                        
                        board[nx][ny] = '.';
                    }
                    board[i][j] = '.';
                    boomerTime[i][j] = 0;
                }
            }
        }
    }
}
void installBoomer(int timer) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(board[i][j] == 'O')
                continue;

            board[i][j] = 'O';
            boomerTime[i][j] = timer + 3;
        }
    }
}
void solution() {
    int timer = 2;

    while(true) {
        if(timer == N + 1)
            break;

        if(timer % 2 == 0) {
            installBoomer(timer);
        } else {
            releaseBoomer(timer);
        }
        timer ++;
    }
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> R >> C >> N;

    for(int i = 0; i < R; i++) {
        cin >> board[i];
    }

    for(int i = 0; i < R; i++)
        for(int j = 0; j < board[i].size(); j++)
            if(board[i][j] == 'O')
                boomerTime[i][j] = 3;

    solution();

    for(int i = 0; i < R; i++) {
        cout << board[i] << '\n';
    }
    return 0;
}