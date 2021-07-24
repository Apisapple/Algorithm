#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000

int N = 0, M = 0;
vector<vector<int>> board(MAX + 1, vector<int>(MAX + 1, 0));
vector<vector<int>> cache(MAX + 1, vector<int>(MAX + 1, 0));

void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int getResult() {
    int result = 0;

    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            if(board[i][j] == 0) {
                cache[i][j] = min(min(cache[i - 1][j], cache[i - 1][j - 1]), cache[i][j - 1]) + 1;
                result = max(result, cache[i][j]);
            }
        }
    }

    return result;
}

int main() {
    initSolution();

    cin >> M >> N;

    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    cout << getResult() << '\n';
    return 0;
}