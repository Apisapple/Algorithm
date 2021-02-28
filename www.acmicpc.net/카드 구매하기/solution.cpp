#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int card_cnt = 0;
    cin >> card_cnt;
    vector<int> card_list(card_cnt + 1, 0);
    vector<int> dp(card_cnt + 1, 0);
    for(int i = 1; i <= card_cnt; i++) {
        cin >> card_list[i];
    }
    dp[1] = card_list[0];
    for(int i = 1; i <= card_cnt; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + card_list[j]);
        }
    }
  
    cout << dp[card_cnt] << endl;
    return 0;
}