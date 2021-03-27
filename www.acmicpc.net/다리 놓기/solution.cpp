#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<vector<int>> dp(31, vector <int> (31, 0));

    for(int i = 1; i <= 30; i++)
        dp[1][i] = i;

    for(int i = 2; i <= 30; i++) {
        for(int j = i; j <= 30; j++) {
            for(int k = 1; k < j ; k++) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
    int test_case;
    cin >> test_case;
    while (test_case > 0)
    {
        int left, right;
        cin >> left >> right;
        cout << dp[left][right] << endl;
        test_case --;
    }
    
    return 0;
}