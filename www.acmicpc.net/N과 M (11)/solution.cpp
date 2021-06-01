#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 8

vector<int> result;
int n = 0, m = 0;

void DFS(vector<int> numberList, int dept) {
    if(dept == m) {
        for(int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    vector<bool> visited(MAX, false);
    for(int i = 0; i < n; i++) {
        if(!visited[numberList[i]]) {
            visited[numberList[i]] = true;
            result.push_back(numberList[i]);
            DFS(numberList, dept + 1);
            result.pop_back();
        }
    }
}
int main() {

    cin >> n >> m;
    vector<int> numberList(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> numberList[i];
    }

    sort(numberList.begin(), numberList.end());

    DFS(numberList, 0);
    return 0;
}