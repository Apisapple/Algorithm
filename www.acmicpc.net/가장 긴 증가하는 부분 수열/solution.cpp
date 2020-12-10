#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, result = 0;
    cin >> N;
    vector<int> number_list(N, 0);
    vector<int> dp(N + 1, 1);
    for(int i = 0; i < N; i++) {
        cin >> number_list[i];
    }
    for(int i = 0; i < N; i++) {
        int pivot = number_list[i];
        for(int j = 0; j < i; j++) {
            if(pivot > number_list[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result , dp[i]);
    }
    cout << result << endl;
    return 0;
}