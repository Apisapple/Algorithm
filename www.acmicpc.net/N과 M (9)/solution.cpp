#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 8

using namespace std;

vector<int> numberList(MAX, 0);
vector<int> result(MAX, 0);
vector<int> visited(MAX, false);
int n = 0, m = 0;

void DFS(int dept) {
    if(dept == m) {
        for(int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int temp = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && numberList[i] != temp) {
            result[dept] = numberList[i];
            temp = result[dept];
            visited[i] = true;
            DFS(dept + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> numberList[i];
    }

    sort(numberList.begin(), numberList.begin() + n);

    DFS(0);


    return 0;
}