#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_CNT 10
#define MAX_WEIGHT 1000

int beadCnt = 0, result = 0;
void init() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

void bruteForce(vector<int> &beadList, int total) {
    if(beadList.size() < 3) {
        result = max(result, total);
        return;
    }

    for(int i = 1; i < beadList.size() - 1; i++) {
        int temp = beadList[i];
        total += (beadList[i - 1] * beadList[i + 1]);
        beadList.erase(beadList.begin() + i);
        bruteForce(beadList, total);
        beadList.insert(beadList.begin() + i, temp);
        total -= (beadList[i - 1] * beadList[i + 1]);
    }
}

int main() {
    init();

    cin >> beadCnt;
    vector<int> beadList(beadCnt, 0);
    for(int i = 0; i < beadCnt; i++) {
        cin >> beadList[i];
    }

    bruteForce(beadList, 0);

    cout << result << '\n';

    return 0;
}