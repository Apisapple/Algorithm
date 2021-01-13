#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N = 0;

void compress(int x, int y, int size, vector<string> &board) {
    for(int i = x; i < x + size; i++) {
        for(int j = y; j < y + size; j++) {
            if(board[x][y] != board[i][j]) {
                cout << "(";
                if(size == 1) {
                    cout << board[x][y];
                    return;
                }
                compress(x, y, size / 2, board);
                compress(x, y + (size / 2), size / 2, board);
                compress(x + (size / 2), y, size / 2, board);
                compress(x + (size / 2), y + (size / 2), size / 2, board);
                cout << ")";
                return;
            }
        }
    }

    cout << board[x][y];
    return;
}

int main() {
    cin >> N;

    vector<string> board(N);

    for(int i = 0; i < N; i++) {
        cin >> board[i];
    }

    compress(0, 0, N, board);

    return 0;
}