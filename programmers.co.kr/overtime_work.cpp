#include <queue>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> que;
    long long answer = 0;

    for (int work : works) {
        que.push(work);
    }

    for (int i = 0; i < n; i++) {

        int maxValue = que.top();
        if (maxValue != 0) {

            que.pop();
            que.push(maxValue - 1);
        }
    }

    while (!que.empty()) {
        answer += (long long)((que.top()) * (que.top()));
        que.pop();
    }
    return answer;
}