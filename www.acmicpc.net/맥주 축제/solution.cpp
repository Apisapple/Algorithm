#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 200000
#define MAX_M 200000


int main() {
    int N, K;
    long long M;
    int answer = 0, total = 0;
    vector<pair<int, int>> drinkInfo;
    cin >> N >> M >> K;

    for(int i = 0; i < K; i++) {
        int drinkLevel;
        int drinkGrade;
        cin >> drinkLevel >> drinkGrade;
        drinkInfo.push_back(make_pair(drinkGrade, drinkLevel));
    }
    priority_queue<int> pq;
    sort(drinkInfo.begin(), drinkInfo.end());
    for(int i = 0; i < K; i++) {
        pq.push(-drinkInfo[i].second);
        total += drinkInfo[i].second;
        if(pq.size() > N) {
            total += pq.top();
            pq.pop();
        }
        if(pq.size() == N && total >= M) {
            cout << drinkInfo[i].first << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}