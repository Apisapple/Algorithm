#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000

vector<vector<int>> tempNumberList(MAX + 1);
vector<int> numberList(MAX + 1, 0);
vector<int> dp(MAX + 1, 0);
vector<int> answerList;
int N = 0;
void initSolution() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    initSolution();

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> numberList[i];
    }

    for(int i = 1; i <= N; i++) {
        dp[i] = 1;
        tempNumberList[i].push_back(numberList[i]);

        for(int j = 1; j < i; j++) {
            if(numberList[i] > numberList[j]) {
                if(dp[i] < dp[j] + 1) {
                    tempNumberList[i].clear();
                    tempNumberList[i] = tempNumberList[j];
                    tempNumberList[i].push_back(numberList[i]);
                    dp[i] = dp[j] + 1;
                }
            }
        }

        if(answerList.size() < tempNumberList[i].size()) {
            answerList = tempNumberList[i];
        }
    }

    cout << answerList.size() << '\n';
    for(int answer : answerList) {
        cout << answer << ' ';
    }
}