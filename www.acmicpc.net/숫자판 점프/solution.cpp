#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;


int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<int>> board(5, vector<int>(5, 0));
vector<vector<bool>> visited(5, vector<bool>(5, 0));
set<int> result;
int number = 0;
void DFS(int x, int y, int dept) {
    if(dept == 6) {
        result.insert(number);
        return;
    }
    for(int i = 0; i < 4; i++) {
        int temp = 0;
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x < 0 || 5 <= next_x || next_y < 0 || 5 <= next_y)
            continue;

        temp = number;
        number = (number * 10) + board[next_x][next_y];
        DFS(next_x, next_y, dept + 1);
        number = temp;
    }
}
int main() {

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> board[i][j];


    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            DFS(i, j, 0);
        }
    }

    
    return 0;
}