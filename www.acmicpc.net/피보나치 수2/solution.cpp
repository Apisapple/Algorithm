#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 90

int main() {
    int N;
    cin >> N;

    vector<long long> dp(MAX + 1, 0);
    
    dp[1] = 1;

    for(int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[N] << endl;
    return 0;
}