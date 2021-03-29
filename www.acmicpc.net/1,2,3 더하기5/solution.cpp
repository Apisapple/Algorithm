#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM 100000
#define DIV_NUM 1000000009

long long dp[MAX_NUM + 1][4];

long long solution(int number) {
    if(dp[number][1] + dp[number][2] + dp[number][3] != 0)
        return (dp[number][1] + dp[number][2] + dp[number][3]) % DIV_NUM;

    for(int i = 4; i <= number; i++) {
        if(dp[i][1] + dp[i][2] + dp[i][3] != 0)
            continue;
        for(int j = 1; j <= 3; j++) {
            long long total = 0;
            for(int k = 1; k <= 3; k++) {
                if(k == j)
                    continue;
                total = (total + dp[i - j][k]) % DIV_NUM;
            }
            dp[i][j] = total;
        }
    }

    long long result = (dp[number][1] + dp[number][2] + dp[number][3]) % DIV_NUM;

    return result;
}

int main() {
    int testCase;

    cin >> testCase;
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    while(testCase--) {
        int number;
        cin >> number;

        cout << solution(number) << endl;
    }

    return 0;
}