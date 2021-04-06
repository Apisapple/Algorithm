#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_CNT 100000

int main() {
    vector<pair<int, int>> timeInfo;
    int cnt = 0, temp = 0, answer = 0;
    cin >> cnt;

    for(int i = 0; i < cnt; i++) {
        int start, end;
        cin >> start >> end;
        timeInfo.push_back(make_pair(start, 1));
        timeInfo.push_back(make_pair(end, -1));
    }
    sort(timeInfo.begin(), timeInfo.end());
    
    for(pair<int, int> a:timeInfo) {
        temp += a.second;
        answer = max(answer, temp);
    }
    cout << answer << endl;
    return 0;
}