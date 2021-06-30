#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_LINE 200000
#define MAX_NODE 20000
#define RED 1
#define BLUE 2

vector<vector<int>> board(MAX_NODE + 1);
int visited[MAX_NODE + 1];
int testCase, nodeCnt, lineCnt;

void DFS(int start) {
    if(!visited[start]) {
        visited[start] = RED;
    }

    for(int i = 0; i < board[start].size(); i++) {
        int next = board[start][i];
        if(!visited[next]) {
            if(visited[start] == RED) {
                visited[next] = BLUE;
            } else if(visited[start] == BLUE) {
                 visited[next] = RED;
            }

            DFS(next);
        }
    }
}

bool checkBipareGraph(){
    for(int i = 1; i <= nodeCnt; i++) {
        for(int j = 0; j < board[i].size(); j++) {
            if(visited[i] == visited[board[i][j]]) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> testCase;


    while(testCase --) {
        cin >> nodeCnt >> lineCnt;
        for(int i = 0; i < lineCnt; i++) {
            int start, end;
            cin >> start >> end;

            board[start].push_back(end);
            board[end].push_back(start);
        }

        for(int i = 1; i <= nodeCnt; i++) {
            if(!visited[i]) {
                DFS(i);
            }
        }

        if(checkBipareGraph()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }


         for (int i = 0; i <= nodeCnt; i++) {
            board[i].clear();
        }
        memset(visited, false, sizeof(visited));
    }

    return 0;
}
