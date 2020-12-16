#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_POINT 20000
#define MAX_LINE 300000
#define INF 99999999
// 정점의 개수 V, 간선의 개수 E
int V = 0, E = 0;
vector <pair<int, int>> board[MAX_POINT];

int main() {
    // 내용 출력 확인을 위한 추가
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    int start = 0;
    cin >> start;

    //입력
    for(int i = 0; i < E; i++) {
        int start_node, end_node, value;
        cin >> start_node >> end_node >> value;
        board[start_node].push_back(make_pair(end_node, value));
    }

    // 간선의 값을 INF로 초기화
    vector<int> Dist(V + 1, INF);

    // 우선순위 큐를 통한 다이익스트라 알고리즘 시작
    priority_queue<pair<int, int>> pq;
    // 시작지점의 거리는 0
    pq.push(make_pair(0, start));
    Dist[start] = 0;

    while(pq.empty()) {
        int cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        for(int i = 0; i < board[current_node].size(); i++) {
            int next_node = board[current_node][i].first;
            int next_cost = board[current_node][i].second;
            if(Dist[next_node] > next_cost - cost) {
                Dist[next_node] = next_cost - cost;
                pq.push(make_pair(Dist[next_node], next_node));
            }
        }
    }

    for(int i = 1; i <= V; i++) {
        if(Dist[i] == INF) cout << "INF" << endl;
        else cout << Dist[i] << endl;
    }
    return 0;
}