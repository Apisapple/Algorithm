#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAXSIZE 200001

using namespace std;

int N = 0, K = 0;
int ans_time = MAXSIZE;
vector <bool> visited(MAXSIZE, false);

void BFS() {
    int index = N;
    int time = 0;
    queue <pair<int, int>> que;
    que.push(make_pair(index, time));

    while (!que.empty())
    {
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
            que.push(make_pair(current_index * 2, current_time));
        }
    }
    
}  

int main() {
    cin >> N >> K;

    BFS();

    cout << ans_time << endl;

    return 0;
}
