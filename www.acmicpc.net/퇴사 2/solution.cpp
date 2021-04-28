#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_VALUE 1500000

int main() {
    vector<pair<int, int>> cunsult;
    vector<int> dp(MAX_VALUE + 1, 0);
    cunsult.push_back(make_pair(0, 0));
    int N, answer;

    // 내용 입력
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int time, price;
        cin >> time >> price;
        cunsult.push_back(make_pair(time, price));
    }

    // 문제풀이 시작
    for(int i = 1; i <= N + 1; i ++) {
        answer = max(answer, dp[i]);
        if(i + cunsult[i].first > N + 1)
            continue;
        else 
            dp[i + cunsult[i].first] = max(dp[i + cunsult[i].first], answer + cunsult[i].second);
    }

    cout << answer << endl;
    return 0;
}