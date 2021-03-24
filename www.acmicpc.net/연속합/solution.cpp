#include <iostream>
#include <vector>

using namespace std;

#define MAX 100001

int main() {
    int num = 0;
    cin >> num;

    vector<int> number_list(MAX, 0);
    vector<int> dp(MAX, 0);

    for(int i = 0; i < num; i++) {
        cin >> number_list[i];
        dp[i] = number_list[i];
    }

    int answer = 0;
    answer = dp[0];

    for(int i = 1; i < num; i++ ){
        dp[i] = max(dp[i], dp[i - 1] + number_list[i]);
        if(dp[i] > answer) {
            answer = dp[i];
        }
    }
    cout << answer << endl;
    return 0;
}