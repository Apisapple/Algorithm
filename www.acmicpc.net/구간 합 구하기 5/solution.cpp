#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int table_size = 0, rotate_count = 0;
    cin >> table_size >> rotate_count;

    vector<vector<int>> table(table_size, vector<int>(table_size, 0));
    vector<vector<int>> dp(table_size + 1, vector<int>(table_size + 1, 0));
    // 구간 합 표 입력
    for(int i = 0; i < table_size; i++) {
        for(int j = 0; j < table_size; j++) {
            cin >> table[i][j];
        }
    }
    // DP 값 입력
    for(int i = 0; i < table_size; i++) {
        for(int j = 0; j < table_size; j++) {
            dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + table[i][j]; 
        }
    }
   
    for(int i = 0; i < rotate_count; i++) {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1] << "\n";

    }

    return 0;
}