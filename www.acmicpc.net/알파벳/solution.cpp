#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 20

vector<char> alphabet(26, false);
vector<vector<char>> board(MAX, vector<char>(MAX, 0));
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int maxPath = 0;
void initAlgorithm() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int dfs(int maxRow, int maxCol, int row, int col, int findPath) {
    maxPath = max(findPath, maxPath);

    for(int i = 0; i < 4; i++) {
        int nextRow = row + dx[i];
        int nextCol = col + dy[i];

        if(0 <= nextRow && nextRow < maxRow && 0 <= nextCol && nextCol < maxCol) {
            if(!alphabet[((int) board[nextRow][nextCol]) - 65]) {
                alphabet[((int) board[nextRow][nextCol]) - 65] ++;
                dfs(maxRow, maxCol, nextRow, nextCol, findPath + 1);
                alphabet[((int) board[nextRow][nextCol]) - 65] --;
            }
        }
    }

    return maxPath;
}

int solution(int height, int width) {
    int answer = 0;

    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            cin >> board[i][j];


    alphabet[(int)board[0][0] - 65] ++;

    answer = dfs(height, width, 0, 0, 1);
    return answer;
}

int main() {
    initAlgorithm();

    int height, width;
    cin >> height >> width;

    cout << solution(height, width) << '\n';

    return 0;
}