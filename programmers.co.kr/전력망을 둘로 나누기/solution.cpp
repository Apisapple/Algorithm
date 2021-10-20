#include <algorithm>
#include <cmath>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;

    vector<vector<bool>> edges(n + 1, vector<bool>(n + 1, false));
    for (vector<int> wire : wires) {
        edges[wire[0]][wire[1]] = true;
        edges[wire[1]][wire[0]] = true;
    }

    for (vector<int> wire : wires) {
        edges[wire[0]][wire[1]] = false;
        edges[wire[1]][wire[0]] = false;

        vector<bool> visited(n + 1, false);
        queue<int> que;
        que.push(1);
        visited[1] = true;
        int graphLength = 0;
        while (!que.empty()) {
            int currentNode = que.front();
            que.pop();
            graphLength++;
            for (int i = 1; i <= n; i++) {
                if (edges[currentNode][i] && !visited[i]) {
                    que.push(i);
                    visited[i] = true;
                }
            }
        }

        edges[wire[0]][wire[1]] = true;
        edges[wire[1]][wire[0]] = true;

        answer = min(answer, abs(n - graphLength * 2));
    }
    return answer;
}