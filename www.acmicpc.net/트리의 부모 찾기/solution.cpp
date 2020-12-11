#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
vector<int> parent_list;
int node_count = 0;

void DFS(int index, vector<vector<int>> tree_list) {
    visited[index] = true;

    for(int i = 0; i < tree_list[index].size(); i++) {
        int next_node = tree_list[index][i];
        if(!visited[next_node]) {
            parent_list[next_node] = index;
            DFS(next_node, tree_list);
        }
    }
}

int main() {
    cin >> node_count;
    vector<vector<int>> tree_list(node_count + 1);
    visited.resize(node_count + 1, false);
    parent_list.resize(node_count + 1, 0);
    // 노드 연결
    for(int i = 0; i < node_count - 1; i++) {
        int start, end;
        scanf("%d", &start);
        scanf("%d", &end);
        tree_list[start].push_back(end);
        tree_list[end].push_back(start);
    }

    // 깊이 우선 탐색
    DFS(1, tree_list);

    for(int i = 2; i < parent_list.size(); i++)
        cout << parent_list[i] << endl;

    return 0;
}