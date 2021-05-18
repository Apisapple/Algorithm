#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 200
#define DIV_NUM 1000000000

// 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수
vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, 0));
int n = 0, k = 0;
int result = 0;

int main() {

    cin >> n >> k;

    for(int i = 0; i <= n; i++) {
        dp[1][i] = 1;
        dp[2][i] = i + 1;
    }
    
    for(int i = 3; i <= k; i++) {
        for(int j = 0; j <= n; j++) {
            for(int l = 0; l <= j; l++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % DIV_NUM;
            }
        }
    }
    
    cout << dp[k][n] << '\n';

    return 0;
}