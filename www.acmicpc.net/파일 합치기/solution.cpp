#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define MAX 500

vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, 0));
vector<int> numberList(MAX + 1, 0);
vector<int> sum(MAX + 1, 0);
int testCase = 0, K = 0;
void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int main() {
    initSolution();

    cin >> testCase;

    while(testCase --) {
        cin >> K;
        for(int i = 1; i <= K; i++) {
            cin >> numberList[i];
            sum[i] = sum[i - 1] + numberList[i];
        }

        for(int i = 1; i < K; i++) {
            for(int x = 1; x + i <= K; x ++) {
                int y = x + i;
                dp[x][y] = INT_MAX;

                for(int mid = x; mid < y; mid ++) {
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
                }
            }
        }

        cout << dp[1][K] << '\n';
    }

    return 0;
}