#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 8

vector<bool> visited(MAX, false);
vector<int> result(MAX, 0);
int n = 0, m = 0;

void DFS(vector<int> &numberList, int dept, int index) {
    if(dept == m) {
        for(int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int prevNumber = -1;
    for(int i = index; i < n; i++) {
        if(!visited[i] && prevNumber != numberList[i]) {
            visited[i] = true;
            result[dept] = prevNumber = numberList[i];
            DFS(numberList, dept + 1, i);
            visited[i] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n  >> m;

    // 수열 정보 입력
    vector<int>numberList(n);
    for(int i = 0; i < n; i++) {
        cin >> numberList[i];
    }
    sort(numberList.begin(), numberList.end());
    vector<int> result;
    DFS(numberList, 0, 0);
    
    return 0;
}