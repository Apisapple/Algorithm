#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_TC 5
#define MAX_NODE 500
#define MAX_STREET 2500
#define MAX_HOLE 200
#define INF 987654321

int TC, NODE, STREET, HOLE;

int main() {
    cin >> TC;
    for(int i = 0; i < TC; i++) {
        cin >> NODE >> STREET >> HOLE;
        // NODE의 개수와 NODE들 간의 거리 초기화
        vector<vector<pair<int, int>>> line(NODE + 1);
        vector<int>dist(NODE + 1, INF);
        dist[1] = 0;
        // STREET 정보 입력
        for(int j = 0; j < STREET; j++) {
            int start_node, end_node, use_time;
            cin >> start_node >> end_node >> use_time;
            line[start_node].push_back(make_pair(end_node, use_time));
            line[end_node].push_back(make_pair(start_node, use_time));
        }

        for (int w_idx = 0; w_idx < HOLE; w_idx++) {
            int from_, to_, weight_;
            cin >> from_ >> to_ >> weight_;
            line.at(from_).push_back({ to_ , (-1)*weight_ });
        }

        bool flag = false;
        for(int p = 1; p <= NODE; p++) {
            for(int q = 1; q <= NODE; q++) {
                for(int r = 0; r < line[q].size(); r++) {
                    int start = q;
                    int end = line[q][r].first;
                    int value = line[q][r].second;

                    if(dist[start] + value < dist[end]) {
                        dist[end] = dist[start] + value;
                        if(p == NODE)
                            flag = true;
                    }
                }
            }
        }
        if(flag)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}