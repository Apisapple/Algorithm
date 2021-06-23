#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 100
#define MIN 0

vector<vector<int>> board(MAX + 1, vector<int> (MAX + 1, 0));
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void initSolution() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int getNextDirection(int currentDir, char command) {
    if(command == 'R') {
        if(currentDir == 0)
            return 2;
        else if (currentDir == 1)
            return 3;
        else if (currentDir == 2)
            return 1;
        else if (currentDir == 3)
            return 0;
        
    } else if(command == 'L') {

        if(currentDir == 0)
            return 3;
        else if (currentDir == 1)
            return 2;
        else if (currentDir == 2)
            return 0;
        else if (currentDir == 3)
            return 1;
    }
    return 0;
}

int main() {
    initSolution();


    int inputSize = 0;
    string inputData;

    cin >> inputSize;
    cin >> inputData;

    // init setting start line
    int x = 50, y = 50;
    int direction = 2;
    
    board[x][y] = 1;

    for(int i = 0; i < inputSize; i++) {
        if(inputData[i] == 'R' || inputData[i] == 'L') {
            direction = getNextDirection(direction, inputData[i]);
        } else if(inputData[i] == 'F') {
            x = x + dx[direction];
            y = y + dy[direction];
            board[x][y] = 1;
        }
    }

    // find start index & end index

    int start_x = MAX, start_y = MAX;
    int end_x = 0, end_y = 0;

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(board[i][j] == 1) {
                start_x = min(start_x, i);
                start_y = min(start_y, j);
                end_x = max(end_x, i);
                end_y = max(end_y, j);
            }
        }
    }
    
    for(int i = start_x; i <= end_x; i++) {
        for(int j = start_y; j <= end_y; j++) {
            if(board[i][j] == 1)
                cout << ".";
            else
                cout << "#";
        }
        cout << '\n';
    }


    return 0;
}