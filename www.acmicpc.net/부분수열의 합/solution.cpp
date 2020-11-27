#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> number_list(20, 0);
int N = 0, S = 0;
int cnt = 0;

void solve(int index, int total) {
    if(index == N)
        return;
    if(total + number_list[index] == S)
        cnt ++;
    solve(index + 1, total);
    solve(index + 1, total + number_list[index]);
}

int main() {
    cin >> N >> S;
    for(int i = 0; i < N; i++) {
        cin >> number_list[i];
    }
    int index = 0, total = 0;
    solve(index, total);
    cout << cnt << endl;
    return 0;
}