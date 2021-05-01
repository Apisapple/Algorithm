#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100
#define MAX_K 10000

int main() {
    vector<int> dp(MAX_K + 1, MAX_K + 1);
    vector<int> coinPrice(MAX_N + 1, 0);
    int n, k;

    cin >> n >> k;

    // dp 배열 초기화
    dp[0] = 0;

    // 동전 가치 입력
    for(int i = 1; i <= n; i++)
        cin >> coinPrice[i];

    for(int i = 1; i <= n; i++ ){
        for(int j = coinPrice[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coinPrice[i]] + 1);
        }
    }
    
    if(dp[k] == MAX_K + 1)
        dp[k] = - 1;
    
    cout << dp[k] << endl;

    return 0;
}