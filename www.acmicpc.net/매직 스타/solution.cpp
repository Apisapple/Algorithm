#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> list;
vector<bool> checkList(13, false);
int xCnt = 0;

void initSolution() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool checkBoard(vector<string> &inputData) {
    if ((inputData[0][4] - 'A' + 1) + (inputData[1][3] - 'A' + 1) + (inputData[2][2] - 'A' + 1) + (inputData[3][1] - 'A' + 1) != 26) return false;
    if ((inputData[0][4] - 'A' + 1) + (inputData[1][5] - 'A' + 1) + (inputData[2][6] - 'A' + 1) + (inputData[3][7] - 'A' + 1) != 26) return false;
    if ((inputData[1][1] - 'A' + 1) + (inputData[1][3] - 'A' + 1) + (inputData[1][5] - 'A' + 1) + (inputData[1][7] - 'A' + 1) != 26) return false;
    if ((inputData[3][1] - 'A' + 1) + (inputData[3][3] - 'A' + 1) + (inputData[3][5] - 'A' + 1) + (inputData[3][7] - 'A' + 1) != 26) return false;
    if ((inputData[4][4] - 'A' + 1) + (inputData[3][3] - 'A' + 1) + (inputData[2][2] - 'A' + 1) + (inputData[1][1] - 'A' + 1) != 26) return false;
    if ((inputData[4][4] - 'A' + 1) + (inputData[3][5] - 'A' + 1) + (inputData[2][6] - 'A' + 1) + (inputData[1][7] - 'A' + 1) != 26) return false;
 
    return true;
}

void DFS(vector<string> &inputData, int index, int cnt) {
    if(cnt == xCnt) {
        if(checkBoard(inputData)) {
            for(int i = 0; i < 5; i++) {
                cout << inputData[i] << '\n';
            }
            exit(0);
        }
        return;
    }

    for(int i = 0; i < 12; i++) {
        if(checkList[i])
            continue;
        
        checkList[i] = true;
        inputData[list[index].first][list[index].second] = i + 'A';
        DFS(inputData, index + 1, cnt + 1);
        inputData[list[index].first][list[index].second] = 'x';
        checkList[i] = false;
    }
}

int main() {
    initSolution();
    vector<string> inputData(5);

    for(int i = 0; i < 5; i++) {
        cin >> inputData[i];
    }

    for(int i = 0; i < 5; i ++) {
        for(int j = 0; j < 9; j++) {
            if(inputData[i][j] == 'x') {
                list.push_back(make_pair(i, j));
                xCnt ++;
            } else if ('A' <= inputData[i][j] && inputData[i][j] <= 'L') {
                checkList[inputData[i][j] - 'A'] = true;
            }
        }
    }

    DFS(inputData, 0, 0);
    return 0;
}