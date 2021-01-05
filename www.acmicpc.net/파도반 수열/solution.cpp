#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

vector<long long int>dp(MAX + 1, 0);
int main() {
    int tc, number;
    cin >> tc;
    while(tc --) {
        cin >> number;

        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;

        for(int i = 6; i <= MAX; i++) 
            dp[i] = dp[i - 3] + dp[i - 2];

        cout << dp[number] << endl;
    }


    return 0;
}