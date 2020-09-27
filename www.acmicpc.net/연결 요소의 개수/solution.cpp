#include <iostream>
#include <vector>

using namespace std;

vector<bool> visit(1, false);

void dfs(int index, vector< vector<int> > &graph) {
    
    visit[index] = true;
    for(int i = 1; i < graph.size(); i++) {
        if(graph[index][i] && !visit[i]) {
            dfs(i, graph);
        }
    }
}

int main() {

    // 내용 입력
    int node, line;
    int count = 0;
    cin >> node >> line;
    
    // 방문node 체크
    visit.resize(node + 1, false);
    // 그래프 생성
    vector< vector<int> > graph(node + 1, vector<int>(node + 1, 0));
    for(int i = 0; i < line; i++) {
        int start, end;
        cin >> start >> end;
        graph[start][end] = 1;
        graph[end][start] = 1;
    }
    
    for(int i = 1; i <= node ; i++) {
        if(!visit[i]) {
            dfs(i, graph);
            count ++;
        }
    }

    cout << count << endl;
    return 0;
}