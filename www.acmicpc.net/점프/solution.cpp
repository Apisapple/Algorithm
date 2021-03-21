#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int board_size = 0;

int main() {
    cin >> board_size;

    vector<vector<int>> board(board_size, vector<int>(board_size, 0));
    vector<vector<long>> dp(board_size + 1, vector<long>(board_size + 1, 0));
    for(int i = 0; i < board_size; i++) {
        for(int j = 0; j < board_size; j++) {
            cin >> board[i][j];
        }
    }
    dp[0][0] = 1;

    for(int i = 0; i < board_size; i++) {
        for(int j = 0; j < board_size; j++) {
            if(dp[i][j] == 0 || (i == board_size - 1 && j == board_size - 1))
                continue;

            int value = board[i][j];
            int down_index = i + value;
            int right_index = j + value;

            if(down_index < board_size)
                dp[down_index][j] = dp[down_index][j] + dp[i][j];
            if(right_index < board_size)
                dp[i][right_index] = dp[i][right_index] + dp[i][j];
        }
    }
    cout << dp[board_size - 1][board_size - 1] << endl;
    return 0;
}