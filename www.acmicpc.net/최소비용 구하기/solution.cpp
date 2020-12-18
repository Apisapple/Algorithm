#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_CITY 1001
#define MAX_BUS 100001
#define INF 987654321

vector<int> dist(MAX_CITY, 0);
vector<pair<int, int>> value_arr[MAX_BUS];

void dijkstra(int start_city) {
    // 시작값 0츠로 초기화
    dist[start_city] = 0;

    // 우선순위 큐 생성
    priority_queue<pair <int, int>> pq;
    pq.push(make_pair(start_city, dist[start_city]));

    while(!pq.empty()) {
        int current_city = pq.top().first;
        int cost = - pq.top().second;
        pq.pop();

        if(dist[current_city] < cost) 
            continue;
        
        for(int i = 0; i < value_arr[current_city].size(); i++) {
            int next_city = value_arr[current_city][i].first;
            int next_cost = value_arr[current_city][i].second + cost;

            if(next_cost < dist[next_city]) {
                dist[next_city] = next_cost;
                pq.push(make_pair(next_city, -dist[next_city]));
            }
        }
    }
}

int main() {
    int start_city = 0, end_city = 0, N = 0, M = 0;
    // 도시의 개수와 버스노선 개수 입력
    cin >> N;
    cin >> M;
    // 간선 거리 초기화
    for(int i = 0; i <= N; i++) 
        dist[i] = INF;
    // 거리 값 입력
    for(int i = 0; i < M; i++) {
        int start, end, value;
        cin >> start >> end >> value;
        value_arr[start].push_back(make_pair(end, value));
    }
    // 시작도시, 도착도시 입력
    cin >> start_city;
    cin >> end_city;
    // 다이익스트라 탐색 시작 및 결과 값 출력
    dijkstra(start_city);
    cout << dist[end_city] << endl;
    return 0;
}