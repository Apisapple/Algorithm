#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_LINE 5

vector<vector<char>> classSpot(MAX_LINE + 1, vector<char>(MAX_LINE + 1));
vector<bool> visited(MAX_LINE * MAX_LINE, false);
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int result = 0;

bool checkFour() {
    int result = 0;
    for(int i = 0; i < MAX_LINE * MAX_LINE; i++) {
        if(visited[i]) {
            int x = i / 5;
            int y = i % 5;

            if(classSpot[x][y] == 'S')
                result ++;
        }
    }

    if(4 <= result)
        return true;
    else
        return false;
}

bool adjacency() {
    queue<pair<int, int>> que;
    vector<vector<bool>> checkSelect(MAX_LINE, vector<bool>(MAX_LINE, false));
    vector<vector<bool>> checkQueue(MAX_LINE, vector<bool>(MAX_LINE, false));
    bool flag = false;
    int temp = 0;

    for(int i = 0;  i < MAX_LINE * MAX_LINE; i++) {
        if(visited[i]) {
            int x = i / 5;
            int y = i % 5;
            checkSelect[x][y] = true;
            if(temp == 0) {
                que.push(make_pair(x, y));
                checkQueue[x][y] = true;
                temp ++;
            }
        }
    }

    int count = 1;
    while(!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        if(count == 7) {
            flag = true;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
                if(checkSelect[nx][ny] && !checkQueue[nx][ny]) {
                    checkQueue[nx][ny] = true;
                    que.push(make_pair(nx, ny));
                    count ++;
                }
            }
        }
    }

    if(flag)
        return true;
    else
        return false;
}

void DFS(int index, int count) {
    if(count == 7) {
        if(checkFour()) {
            if(adjacency()) {
                result ++;
            }
        }
        return;
    }
    for(int i = index; i < 25; i++) {
        if(!visited[i]) {
            visited[i] = true;
            DFS(i, count + 1);
            visited[i] = false;
        }
    }
}
int main(int argc, char const *argv[]) {
    
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    for(int i = 0; i < MAX_LINE; i++) {
        for(int j = 0; j < MAX_LINE; j++) {
            cin >> classSpot[i][j];
        }
    }
    
    DFS(0, 0);
    cout << result << '\n';
    return 0;
}
