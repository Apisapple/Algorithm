#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000

vector<int> dp(MAX + 1, 0);
int tc = 0;
void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}
int main(int argc, char const *argv[]) {
    int number = 0;
    initSolution();

    /* calculation dp */
    dp[0] = 1;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= MAX; j++) {
            if(0 <= j - i) {
                dp[j] += dp[j - i];
            }
        }
    }

    cin >> tc;
    for(int i = 0; i < tc; i++) {
        cin >> number;
        cout << dp[number] << '\n';
    }

    return 0;
}
