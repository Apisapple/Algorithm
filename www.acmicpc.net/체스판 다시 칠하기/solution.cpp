#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
#include <string>

using namespace std;

#define MAX 50
#define MIN 8
#define BOARD_SIZE 8

string whiteStartBoard[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string blackStartBoard[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};
vector<string> board(MAX + 1);
int height = 0, width = 0, result = INT_MAX;
void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}
int getCnt(int x, int y, string bw[]) {
    int result = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[x + i][y + j] != bw[i][j]) {
                result ++;
            }
        }
    }
    return result;
}
int main() {

    initSolution();
    cin >> height >> width;

    for(int i = 0; i < height; i++) {
        cin >> board[i];
    }

    for(int i = 0; i + 8 <= height; i++) {
        for(int j = 0; j + 8 <= width; j++) {
            int temp = 0;
            temp = min(getCnt(i, j, whiteStartBoard), getCnt(i, j, blackStartBoard));
            result = min(result, temp);
        }
    }

    cout << result << '\n';
    return 0;
}