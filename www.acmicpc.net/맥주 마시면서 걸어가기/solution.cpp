#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 103

using namespace std;
int testCase = 0, market_count = 0;
bool flag = false;

void DFS(int start, int end, vector<vector<int>> &board, vector<bool> &visited) {
    visited[start] = true;
    if(start == end) {
        flag = true;
        return;
    }

    for(int i = 0; i < market_count + 2; i++) {
        if(!visited[i] && board[start][i] == 1) {
            DFS(i, end, board, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    cin >> testCase;
    while(testCase --) {
        cin >> market_count;
        vector <vector<int>> board(MAX, vector<int>(MAX, 0));
        vector <bool> visited(MAX, false);
        vector <pair<int, int>> vec;

        for(int i = 0; i < market_count + 2; i++) {
            int x, y;
            cin >> x >> y;
            vec.push_back(make_pair(x, y));
        }

        for(int i = 0; i < vec.size() - 1; i++) {
            for(int j = 0; j < vec.size(); j++) {
                int distance = abs(vec[i].first - vec[j].first) + abs(vec[i].second - vec[j].second);
                if(distance <= 1000) {
                    board[i][j] = 1;
                }
            }
        }

        DFS(0, market_count + 1, board, visited);

        if(flag)
            cout << "happy" << endl;
        else
            cout << "sad" << endl;

        flag = false;
    }

    return 0;
}