#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int white_cnt, blue_cnt;

void divide_board(vector<vector<int>> &board, int x, int y, int size) {
    int temp = 0;
    for(int i = x; i < x + size; i++ ) {
        for(int j = y; j < y + size; j++) {
            if(board[i][j] == 1) 
                temp ++;
        }
    }

    if(temp == 0) {
        white_cnt ++;
    } else if(temp == size  * size) {
        blue_cnt ++;
    } else {
        divide_board(board, x, y, size / 2);
        divide_board(board, x + (size / 2), y , size / 2);
        divide_board(board, x , y + (size / 2) , size / 2);
        divide_board(board, x + (size / 2), y + (size / 2) , size / 2);
    }
    return;
}

int main() {
    int N;
    cin >> N;
    vector <vector<int>> board(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            board[i][j] = temp;
        }
    }

    divide_board(board, 0, 0, N);
    cout << white_cnt << endl;
    cout << blue_cnt << endl;
    return 0;
}