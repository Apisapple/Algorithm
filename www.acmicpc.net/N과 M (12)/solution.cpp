#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 8

int n = 0, m = 0;
vector<int> numberList(MAX, 0);
vector<int> resultList(MAX, 0);
void DFS(int dept, int index) {
    if(dept == m) {
        for(int i = 0; i < m; i++) {
            cout << resultList[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int prev_num = -1;
    for(int i = index; i < n; i++) {
        if(prev_num != numberList[i]) {
            resultList[dept] = numberList[i];
            prev_num = numberList[i];
            DFS(dept + 1, i);
        }
    }
}
int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> numberList[i];
    }
    sort(numberList.begin(), numberList.begin() + n);
    DFS(0, 0);

    return 0;
}