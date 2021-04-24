#include <iostream>
#include <vector>

using namespace std;

#define DIV_NUM 1000000009;
#define MAX_NUM 1000000

int main() {
    long long testCase = 0, number = 0;
    vector<long long> dp(MAX_NUM, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    cin >> testCase;
    while(testCase --) {
        cin >> number;
        for(int i = 4; i <= number; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % DIV_NUM;
        }
        cout << dp[number] << endl;
    }
    return 0;
}