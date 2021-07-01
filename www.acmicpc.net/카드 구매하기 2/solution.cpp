#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

#define MAX 10000

vector<int> cardPoint(MAX + 1, 0);
vector<int> dp(MAX + 1, 0);
int n = 0;
int main(int argc, char const *argv[]) {

    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> cardPoint[i];
    }
    dp[1] = cardPoint[1];


    for(int i = 2; i <= n; i++) {
        dp[i] = cardPoint[i];

        for(int j = 1; j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j] + cardPoint[j]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}
