#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define DIVNUM 1000000000
#define MAX 100

int main() {
    long long dp[MAX + 1][10] = {0,};
    long long result = 0;
    int num;
    cin >> num;

    for(int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= num; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 0) { // 1의 자리 숫자가 0인 경우
                dp[i][0] = dp[i - 1][1] % DIVNUM;
            } else if(j == 9) { // 1의 자리 숫자가 9인 경우
                dp[i][9] = dp[i - 1][8] % DIVNUM;
            } else { // 그 외의 경우
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % DIVNUM;
            }
        }
    }
    for(int i = 1; i < 10; i++) {
        result = (result + dp[num][i]) % DIVNUM;
    }

    cout << result << endl;

    return 0;
}