#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int list_size = 0, answer = 0;
    cin >> list_size;

    vector <int> number_list(list_size, 0);
    vector <int> dp(list_size + 1, 1);
    for(int i = 0; i < list_size; i++) {
        cin >> number_list[i];
    }

    for(int i = 0; i < list_size; i++) {
        int pivot = number_list[i];
        for(int j = 0; j < i; j++) {
            if(pivot < number_list[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(answer , dp[i]);
    }
    cout << answer << endl;
    return 0;
}