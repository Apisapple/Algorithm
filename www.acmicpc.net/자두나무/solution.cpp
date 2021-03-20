#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_TIME 1001
#define MAX_MOVE 32

int main() {
    int drop_time, move_time;
    int dp[MAX_MOVE][2][MAX_TIME];
    cin >> drop_time >> move_time;
    vector<int> drop(drop_time + 1, 0);

    for(int i = 1; i <= drop_time; i++)
        cin >> drop[i];

    for(int i = 0; i <= move_time; i++) {
        for(int j = 1; j <= drop_time; j++) {
            if(i == 0) {
                dp[i][0][j] = dp[i][0][j - 1] + (drop[j] == 1);
            } else {
                dp[i][0][j] = max(dp[i][0][j - 1] + (drop[j] == 1), dp[i - 1][1][j - 1] + (drop[j] == 1));
                dp[i][1][j] = max(dp[i][1][j - 1] + (drop[j] == 2), dp[i - 1][0][j - 1] + (drop[j] == 2));
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j <= move_time; j++) {
            answer = max(answer, dp[j][i][drop_time]);
        }
    }

    cout << answer << endl;
}