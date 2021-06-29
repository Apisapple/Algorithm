#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000

vector<int> boxList(MAX + 1, 0);
vector<int> dp(MAX + 1, 0);
int boxCnt = 0, result = 0;
int main(int argc, const char** argv) {

    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> boxCnt;

    for(int i = 0; i < boxCnt; i++) {
        cin >> boxList[i];
        dp[i] = 1;
    }

    for(int i = 0; i < boxCnt; i++) {
        for(int j = 0; j < i; j++) {
            if(boxList[j] < boxList[i] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        result = max(result, dp[i]);
    }

    cout << result << '\n';
    return 0;
}