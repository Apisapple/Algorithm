#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp (16, 0);
    dp[1] = 3;  
    dp[2] = 11;
    if(n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }else {
        for(int i = 3; i <= n / 2; i++) {
            dp[i] = 3 * dp[i - 1] + 2;
            for(int j = i - 2; j > 0; j--) {
                dp[i] += 2 * dp[j];
            }
        }
    }
    cout << dp[n/2] << '\n';
    
    return 0;
}