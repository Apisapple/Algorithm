#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

#define MAX 50

int N = 0;
int main() {

    cin >> N;
    vector<int> shufflingNumberList(N, 0);
    vector<int> compareNumberList(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> shufflingNumberList[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> compareNumberList[i];
    }

    sort(shufflingNumberList.begin(), shufflingNumberList.end());
    sort(compareNumberList.begin(), compareNumberList.end(), greater<int>());

    int result = 0;
    for(int i = 0; i < N; i++) {
        result += shufflingNumberList[i] * compareNumberList[i];
    }

    cout << result << '\n';

    return 0;
}