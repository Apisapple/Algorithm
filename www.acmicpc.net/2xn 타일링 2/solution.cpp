#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define DIVNUM 10007

vector <int> dp(1001, 0);
int main() {
    int number = 0;
    cin >> number;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3; i <= 1000; i++) {
        dp[i] = ((dp[i - 1] % DIVNUM) + (dp[i - 2] % DIVNUM) * 2) % DIVNUM;
    }

    cout << dp[number] << endl;
    return 0;
}