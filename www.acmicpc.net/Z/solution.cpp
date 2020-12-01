#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 15

using namespace std;

int N = 0, r = 0, c = 0;
int answer = 0;

void solve(int x, int y, int size) {
    // N은 자연수이기 때문에 제일 작은 사이즈는 2
    cout << size << endl;
    if(size == 2) {
        if(x == c && y == r) {
            cout << answer << endl;
            return;
        }
        answer ++;
        if(x + 1 == c && y == r) {
            cout  << answer << endl;
            return;
        }
        answer ++;
        if(x == c && y + 1 == r) {
            cout << answer << endl;
            return;
        }
        answer ++;
        if(x + 1 == c && y + 1 == r) {
            cout << answer << endl;
            return;
        }
        answer ++;
        return;
    }else {
        int value = size / 2;
        solve(x, y, value);
        solve(x + value, y, value);
        solve(x, y + value, value);
        solve(x + value, y + value, value);
    }
}

int main() {

    cin >> N >> r >> c;
    solve(0, 0, 1 << N);
    return 0;
}