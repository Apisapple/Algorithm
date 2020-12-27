#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 200001
int N, K;
int ans_time = MAX, cnt = 0;

void BFS(vector <bool> &visited) {
    int index = N;
    int time = 0;
    queue <pair<int, int>> que;
    que.push(make_pair(index, time));

    while(!que.empty()) {
        int current_index = que.front().first;
        int current_time = que.front().second;
        que.pop();

        if(ans_time < current_time)
            continue;
        
        visited[current_index] = true;
        if(current_index == K) {
            ans_time = min(ans_time, current_time);
            cnt ++;
            continue;
        }
        if(current_index + 1 <= K && !visited[current_index + 1]) {
            que.push(make_pair(current_index + 1, current_time + 1));
        }

        if(current_index - 1 >= 0 && !visited[current_index - 1]) {
            que.push(make_pair(current_index - 1, current_time  + 1));
        }

        if(current_index * 2 <= 2 * K && !visited[current_index * 2]) {
            que.push(make_pair(current_index * 2, current_time + 1));
        }
    }
}

int main() {
    cin >> N >> K;
    vector <bool> visited(MAX, false);

    BFS(visited);

    cout << ans_time << endl;
    cout << cnt << endl;

    
    return 0;
}