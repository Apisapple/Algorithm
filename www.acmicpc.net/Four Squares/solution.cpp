#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 50000

int main() {
    int number = 0;
    cin >> number;
    vector <int> dp(MAX + 1, 0);
    vector <int> number_list(226, 0);
    for(int i = 1; i < 226; i++) {
        number_list[i] = i * i;
    }
    dp[1] = 1;
    for(int i = 2; i <= number; i++) {
        int temp = MAX;
        for(int j = 1; j * j <= i; j++) {
            temp = min(temp, dp[i - j * j] + 1);
        }
        dp[i] = temp;
    }

    cout << dp[number] << endl;
}