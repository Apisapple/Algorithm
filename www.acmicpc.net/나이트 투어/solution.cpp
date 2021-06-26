#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define BOARD_SIZE 6

vector<vector<bool>> visited(BOARD_SIZE, vector<bool>(BOARD_SIZE, false));
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool flag = false;

void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int main(int argc, const char** argv) {
    initSolution();
    string str;
    cin >> str;

    int startRow = 5 - (str[1] - '1');
    int startCol = str[0] - 'A';
    visited[startRow][startCol] = true;

    int pivotRow = startRow;
    int pivotCol = startCol;
    for(int i = 0; i < 35; i++) {
        cin >> str;

        int row = 5 - (str[1] - '1');
        int col = str[0] - 'A';
        flag = false;

        for(int j = 0; j < 8; j++) {
            int nx = pivotRow + dx[j];
            int ny = pivotCol + dy[j];
            if(nx < 0 || ny < 0 || 6 <= nx || 6 <= ny)
                continue;
            
            if(nx == row && ny == col && !visited[nx][ny]) {
                visited[row][col] = true;
                flag = true;
                break;
            }
        }

        if(flag) {
            pivotRow = row;
            pivotCol = col;
        } else {
            cout << "Invalid" << '\n';
            return 0;
        }
    }
    flag = false;

    for(int i = 0; i < 8; i++) {
        if(pivotRow + dx[i] == startRow && pivotCol + dy[i] == startCol) {
            flag = true;
            break;
        }
    }


    if(flag)
        cout << "Valid" << '\n';
    else
        cout << "Invalid" << '\n';
    return 0;
}