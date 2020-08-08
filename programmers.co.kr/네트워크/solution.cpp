#include <string>
#include <vector>

using namespace std;

vector<bool> visit(200, false);

void dfs(int start, int n, vector<vector<int>> computers) {
    visit[start] = true;
    for(int i = 0; i < n; i ++) {
        if(!visit[i] && computers[start][i]) {
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0 ; i < n; i ++) {
        if(!visit[i]){
            answer ++;
            dfs(i, n, computers);
        }
    }
    return answer;
}