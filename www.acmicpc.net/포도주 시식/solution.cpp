#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 10001

// 포도주 사용 규칙
// 1. 포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
// 2. 연속으로 놓여 있는 3잔을 모두 마실 수는 없다.

int main() {
    int N;

    vector<int> cups(N + 1, 0);
    vector<int> dp(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        cin >> cups[i];
    }
    dp[1] = cups[1];
    if(N > 1) {
        dp[2] = dp[1] + cups[2];
    }
    if(N > 2) {
        for(int i = 3; i <= N; i++) {
            dp[i] = max(dp[i - 1], max(dp[i - 2] + cups[i], dp[i - 3] + cups[i - 1] + cups[i]));
        }
    }

    cout << dp[N] << endl;
    return 0;
}