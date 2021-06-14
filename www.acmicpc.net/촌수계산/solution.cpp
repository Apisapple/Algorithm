#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 100

using namespace std;

vector<bool> visited(MAX + 1, 0);
vector<vector<int>> relation(MAX + 1);
int result = -1;

void DFS(int start, int target, int dept) {
    if(start == target) {
        result = dept;
        return;
    }
    for(int i = 0; i < relation[start].size(); i++) {
        if(!visited[relation[start][i]]) {
            visited[relation[start][i]] = true;
            DFS(relation[start][i], target, dept + 1);
            visited[relation[start][i]] = false;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0, start = 0, target = 0, relationCnt = 0;

    cin >> n;
    cin >> start >> target;
    cin >> relationCnt;


    for(int i = 0; i < relationCnt; i++) {
        int first, second;

        cin >> first >> second;

        relation[first].push_back(second);
        relation[second].push_back(first);
    }
    
    DFS(start, target, 0);

    cout << result << '\n';

    return 0;
}