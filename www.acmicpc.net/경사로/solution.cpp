#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

vector<vector<int>> board(MAX + 1, vector<int>(MAX + 1, 0));
vector<vector<int>> rotateBoard(MAX + 1, vector<int>(MAX + 1, 0));
int boardSize = 0, length = 0, result = 0;

void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}
bool checkMakingRoad(vector<vector<int>> &board, int x, int y) {
    int pivot = board[x][y + 1];
    for(int i = y + 1; i < y + 1 + length; i++) {
        if(board[x][i] != pivot)
            return false;
    }
    return true;
}
int calculation(vector<vector<int>> &board) {
    int result = 0;

    for(int i = 0; i < boardSize; i++) {
        bool flag = true;
        int beforeRoad = 1;

        for(int j = 0; j < boardSize - 1; j ++) {
            if(board[i][j] == board[i][j + 1]) {
                beforeRoad ++;
            } else if(board[i][j] == board[i][j + 1] + 1) {
                if(checkMakingRoad(board, i, j)) {
                    j = j + length - 1;
                    beforeRoad = 0;
                } else {
                    flag = false;;
                    break;
                }
            } else if(board[i][j] + 1 == board[i][j + 1]) {
                if(length <= beforeRoad)
                    beforeRoad = 1;
                else {
                    flag = false;
                    break;
                }
            } else if(2 <= abs(board[i][j] - board[i][j + 1]) ) {
                flag = false;
                break;
            }
        }

        if(flag) {
            result ++;
        }
    }

    return result;
}

int main() {

    initSolution();

    cin >> boardSize >> length;

    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            cin >> board[i][j];
            rotateBoard[j][i] = board[i][j];
        }
    }
    return 0;
}