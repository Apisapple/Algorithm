#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

vector <bool> visited(MAX, false);
int answer = MAX;

void bfs(int N, int M) {
    int result = MAX;
    queue < pair <int, int> > que;
    que.push(make_pair(N, 0));

    while(!que.empty()) {
        int cur_index = que.front().first;
        int time = que.front(). second;
        que.pop();
        if(cur_index == M && time < answer) {
                answer = time;
        }
        if(0 <= cur_index -1 && !visited[cur_index - 1]) {
        	visited[cur_index -1] = true;
            que.push(make_pair(cur_index - 1, time + 1));
        }
        if(cur_index + 1 < MAX && !visited[cur_index + 1]) {
        	visited[cur_index + 1] = true;
            que.push(make_pair(cur_index + 1, time + 1));
        }
        if(cur_index * 2 < MAX && !visited[cur_index * 2]) {
        	visited[cur_index * 2] = true;
            que.push(make_pair(cur_index * 2, time + 1));

        }
    }
}

int main() {
    // N : 수빈  M : 동생
    int N = 0, M = 0;
    cin >> N >> M;
    bfs(N, M);
    cout << answer << endl;

    return 0;
}