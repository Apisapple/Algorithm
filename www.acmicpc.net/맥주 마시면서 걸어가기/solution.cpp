#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 103

vector<vector<int>> board(MAX, vector<int>(MAX, 0));
vector<bool> visted(MAX, false);
int mall_cnt = 0;
bool flag = false;
void DFS(int x, int end) {
    visted[x] = true;
    if(x == end)
        flag = true;

    for(int i = 0; i < mall_cnt + 2; i++) {
        if(board[x][i] == 1 && !visted[i]) {
            DFS(i, end);
        }
    }
}

int distance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int t = 0;
    cin >> t;
    while(t --) {
        flag = false;
        cin >> mall_cnt;
        vector<pair<int, int>> mapping;

        for(int i = 0; i < mall_cnt + 2; i++) {
            int x, y;
            cin >> x >> y;
            mapping.push_back(make_pair(x, y));
        }
        for(int i = 0 ; i < mapping.size() - 1; i++) {
            for(int j = 0; j < mapping.size(); j++) {
                if(distance(mapping[i], mapping[j]) <= 1000) {
                    board[i][j] = 1;
                }
            }
        }

        DFS(0, mall_cnt + 1);
    
        if(flag)
            cout << "happy" << endl;
        else
            cout << "sad" << endl;
    }
    return 0;
}