#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0;

void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int main() {
    initSolution();

    cin >> n >> k;

    for(int a = 0; a <= n; a++) {
        int b = n - a;

        if(a * b < k)
            continue;

        vector<int> checking_cnt(b + 1 , 0);
        for(int i = 0; i < a; i++) {
            int x = min(b, k);
            checking_cnt[x]++;
            k -= x;
        }

        for(int i = b; 0 <= i; i--) {
            for(int j = 0; j < checking_cnt[i]; j++) {
                cout << 'A';
            }
            if(0 < i) {
                cout << 'B';
            }
        }
        cout << '\n';
        return 0;
    }
    cout << -1 << '\n';
    return 0;
}