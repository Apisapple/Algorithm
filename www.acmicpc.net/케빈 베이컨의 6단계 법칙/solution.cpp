#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int user_number = 0, relation_number = 0;

int DFS(int start, vector<vector<int>> &relation, vector<bool> visited) {
    // 연결된 사람과 단계 저장
    queue <pair<int, int>> q;
    q.push(make_pair(start, 0));
    visited[start] = true;
    int temp = 0;

    while(!q.empty()) {
        int now = q.front().first;
        int dept = q.front().second;
        q.pop();

        for(int i = 0; i < relation[now].size(); i++) {
            int next_node = relation[now][i];
            if(visited[next_node])
                continue;

            visited[next_node] = true;
            temp += dept;
            q.push(make_pair(next_node, dept + 1));
        }
    }
    
    return temp;
    
}

int main() {
    // 사람 수, 관계 수 입력
    cin >> user_number >> relation_number;
    vector<vector<int>> relation(user_number + 1);
    vector<int> total_value(user_number + 1);
    // 관계 사항 입력
    for(int i = 0; i < relation_number; i++) {
        int first, second;
        cin >> first >> second;
        relation[first].push_back(second);
        relation[second].push_back(first);
    }
    for(int i = 1; i <= user_number; i++) {
        vector<bool> visited(user_number + 1, false);
        total_value[i] = DFS(i, relation, visited);
    }

    int answer = 1;
    for(int i = 2; i < total_value.size(); i++) {
        if(total_value[answer] > total_value[i])
            answer = i;
    }
    cout << answer << endl;
    return 0;
}