#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

int answer = 0;

int main() {
    int total_count = 0;
    cin >> total_count;

    vector <long long> DP(MAX, 0);
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;
    DP[4] = 4;
    DP[5] = 5;

    for(int i = 6; i <= total_count; i ++) {
        // 1. 하나 전에서 1개가 1개 추가 또는 3개전의 값을 복사하였을 때
        DP[i] = max(DP[i -1] + 1, DP[i - 3] * 2);
        //  2. 2번 복사 하였을 때
        DP[i] = max(DP[i], DP[i - 4] * 3);
        //  3. 5번 전의 값을 3번 복사하였을 때
        DP[i] = max(DP[i], DP[i - 5] * 4);
    }
    cout << DP[total_count] << endl;
    return 0;
}