#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_STRING_SIZE 1000

int main() {
    string first_string, second_string;

    cin >> first_string;
    cin >> second_string;
    int first_len = first_string.length();
    int second_len = second_string.length();

    vector< vector<int>> dp(first_len + 1, vector<int>(second_len + 1, 0));

    for(int i = 1; i <= first_len; i++) {
        for(int j = 1; j <= second_len; j++) {
            if(first_string[i - 1] == second_string[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[first_len][second_len] << endl;
    return 0;
}