#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 100000

vector<int> arr(MAX + 1, 0);
vector<int> totalSum(MAX + 1, 0);
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    
    int N = 0, M = 0, startIdx = 0, endIdx = 0, result = 0;

    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        result += arr[i];
        totalSum[i] = result;
    }
    
    for(int i = 0; i < M; i++) {
        cin >> startIdx >> endIdx;

        cout << totalSum[endIdx] - totalSum[startIdx - 1] << '\n';
    }

    return 0;
}