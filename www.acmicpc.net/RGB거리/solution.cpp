#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;

int main() {
    cin >> cnt;
    vector<vector<int>> houses(cnt + 1, vector<int>(3, 0));
    vector<vector<int>> dp(cnt + 1, vector<int>(3, 0));
    
    for(int i = 0 ; i < cnt; i ++) {
        cin >> houses[i][0] >> houses[i][1] >> houses[i][2];
    }
    dp[0][0] = houses[0][0];
    dp[0][1] = houses[0][1];
    dp[0][2] = houses[0][2];

    for(int i = 1; i <= cnt; i++) {
        dp[i][0] = min(dp[i - 1][1] + houses[i][0] , dp[i - 1][2] + houses[i][0]);
        dp[i][1] = min(dp[i - 1][0] + houses[i][1] , dp[i - 1][2] + houses[i][1]);
        dp[i][2] = min(dp[i - 1][0] + houses[i][2] , dp[i - 1][1] + houses[i][2]);
    }

    cout << min(dp[cnt][0] , min(dp[cnt][1], dp[cnt][2])) << endl;
    
}