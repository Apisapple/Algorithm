#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1000

vector<int> numberList(MAX + 1 , 0);
vector<int> dp(MAX + 1, 0);
int main() {
    int n = 0;
    int answer = 0;
    cin >> n;

    for(int i = 1; i <= n ; i++) {
        cin >> numberList[i];
    }

    for(int i = 1; i <= n; i++) {
        dp[i] = numberList[i];

        for(int j = 1; j < i; j++){
            if(numberList[i] > numberList[j] && dp[i] < dp[j] + numberList[i]) {
                dp[i] = dp[j] + numberList[i];
            }
        }
        answer = answer < dp[i] ? dp[i] : answer;
    }
    cout << answer << '\n';
    return 0;
}