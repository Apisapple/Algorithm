#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

vector<int> arr(MAX + 1, 0);
vector<vector<long long>> dp(MAX + 1, vector<long long>(21, 0));
int N = 0, result = 0;
void init() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}
int main(int argc, char const *argv[]){
    init();

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[1][arr[1]] ++;

    for(int i = 2; i < N; i++) {
        for(int j = 0; j <= 20; j++) {
            if(dp[i - 1][j]) {
                if(j + arr[i] <= 20)
                    dp[i][j + arr[i]] += dp[i - 1][j];
                if(0 <= j - arr[i])
                    dp[i][j - arr[i]] += dp[i - 1][j];
            }
        }
    }

    cout << dp[N - 1][arr[N]] << '\n';
    return 0;
}
