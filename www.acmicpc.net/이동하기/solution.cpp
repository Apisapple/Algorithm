#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int width = 0, height = 0;
    cin >> height >> width;
    vector< vector <int> > board(height, vector<int> (width, 0));
    vector< vector <int> > dp(height, vector<int> (width, 0));

    // 미로 값 입력
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int value = 0;
            cin >> value;
            board[i][j] = value;
        }
    }
    // 시작점 초기화
    dp[0][0] = board[0][0];

    // 가로 0 번째 줄 초기화
    for(int i = 1; i < width ; i++) {
        dp[0][i] = board[0][i] + dp[0][i - 1];
    }
    // 세로 0 번째 줄 초기화
    for(int i = 1; i < height; i++) {
        dp[i][0] = board[i][0] + dp[i - 1][0];
    }
    //  동적 프로그래밍 시작
    for(int i = 1; i < height; i++) {
        for(int j = 1; j < width; j++) {
            int temp_first = board[i][j] + dp[i][j - 1];
            int temp_second = board[i][j] + dp[i - 1][j];
            dp[i][j] = max(temp_first, temp_second);
        }
    }
    cout << dp[height - 1][width - 1];
    return 0;
}