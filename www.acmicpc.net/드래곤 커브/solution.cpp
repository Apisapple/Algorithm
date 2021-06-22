#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

vector<vector<int>> board(MAX + 1, vector<int>(MAX + 1, 0));
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int N = 0;
int x = 0, y = 0, d = 0, g = 0;
void initSolution() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void makeDragon(vector<int> &directionInfo) {
    int area = directionInfo.size();
    for(int i = area - 1; 0 <= i; i--) {
        int nextArea = (directionInfo[i] + 1) % 4;
        x = x + dx[nextArea];
        y = y + dy[nextArea];
        board[x][y] = 1;

        directionInfo.push_back(nextArea);
    }
}

void countSquare() {
    int cnt = 0;
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if (board[i][j] == 1 && board[i + 1][j] == 1 &&
                board[i][j + 1] == 1 && board[i + 1][j + 1] == true)
            {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
}

int main() {

    initSolution();

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> y >> x >> d >> g;
        vector<int> directionInfo;

        board[x][y] = 1;
        x = x + dx[d];
        y = y + dy[d];
        board[x][y] = 1;

        directionInfo.push_back(d);
        for(int j = 0; j < g; j++) {
            makeDragon(directionInfo);
        }

    }

    countSquare();

    return 0;
}