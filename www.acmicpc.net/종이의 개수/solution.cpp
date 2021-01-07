#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int cnt_minus = 0, cnt_zero = 0, cnt_one = 0;

void solution(int x, int y, int board_size, vector<vector<int>> &board) {
    
    // board의 size가 1인 경우
    if(board_size == 1) {
        int value = board[x][y];
        if(value == -1)
            cnt_minus ++;
        else if (value == 0)
            cnt_zero ++;
        else if (value == 1)
            cnt_one ++;

        return;
    }

    for(int i = x; i < x + board_size; i++) {
        for(int j = y; j < y + board_size; j++) {
            if(board[x][y] != board[i][j]) {
                int jump = board_size / 3;
                solution(x, y, board_size / 3, board);
                solution(x + jump, y, board_size / 3, board);
                solution(x + jump * 2, y, board_size / 3, board);
                solution(x, y + jump, board_size / 3, board);
                solution(x + jump, y + jump, board_size / 3, board);
                solution(x + jump * 2, y + jump, board_size / 3, board);
                solution(x, y + jump * 2, board_size / 3, board);
                solution(x + jump, y + jump * 2, board_size / 3, board);
                solution(x + jump * 2, y + jump * 2, board_size / 3, board);
                return;
            }
        }
    }


    if(board[x][y] == -1)
        cnt_minus++;
    else if(board[x][y] == 0)
        cnt_zero++;
    else if(board[x][y] == 1)
        cnt_one++;

    return;
}

int main() {
    int board_size = 0;
    cin >> board_size;
    vector <vector <int>> board(board_size, vector<int>(board_size, 0));

    for(int i = 0; i < board_size; i++) {
        for(int j = 0; j < board_size; j++) {
            cin >> board[i][j];
        }
    }

    solution(0, 0, board_size, board);

    cout << cnt_minus << endl;
    cout << cnt_zero << endl;
    cout << cnt_one << endl;
    return 0;
}