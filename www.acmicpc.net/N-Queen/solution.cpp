#include <iostream>
#include <vector>
#include <algorithm>

#define MAXSIZE 15
using namespace std;

int board[MAXSIZE];
int total = 0;
int board_size = 0;

bool checkLotation(int pivot) {
    for(int i = 0; i < pivot; i++) {
        if(board[pivot] == board[i] || abs(board[pivot] - board[i]) == pivot - i)
            return false;
    }
    return true;
}

void dfs(int pivot) {
    if(pivot == board_size) {
        total ++;
        return;
    }
    for(int i = 0; i < board_size; i++) {
        board[pivot] = i;
        if(checkLotation(pivot)) {
            dfs(pivot + 1);
        }
    }
}

int main() {
    cin >> board_size;
    dfs(0);
    cout << total << endl;
    return 0;
}