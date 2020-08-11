#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* 
만들어야 하는 기능
1. 키를 회전시키는 함수
2. 판에 끼우는 함수 
*/

int key_size = 0;
int lock_size = 0;
int board_size = 0;

/* 키를 회전 시키는 함수 오른쪽으로 90도 */
void rotateKey(vector<vector<int>> &key) {
    int size = key.size();
    vector<vector<int>> result(size, vector<int>(size, 0));
    for(int i = 0; i < size / 2; i++) {
        for(int j = i; j < size - i - 1; j++) {
            int temp = key[size -j -1][i];
            key[size -j -1][i] = key[size -i -1][size -j -1];
            key[size -i -1][size -j -1] = key[j][size -i -1];
            key[j][size -i -1] = key[i][j];
            key[i][j] = temp;
        }
    }
}

bool checkKey(int x, int y, vector<vector<int>> key, vector<vector<int>> board) {
    for(int i = x; i < x + key_size; i++) {
        for(int j = y; j < y + key_size; j++) {
            board[i][j] = board[i][j] + key[i - x][j - y];
        }
    }
    for(int i = key_size - 1; i <= board_size - key_size; i++) {
        for(int j = key_size - 1; j <= board_size - key_size; j++) {
            if(board[i][j] == 1)
                continue;
            else
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    key_size = key.size();
    lock_size = lock.size();
    board_size = lock_size + (key_size - 1) * 2;
    vector<vector<int>> board(board_size, vector<int> (board_size, 0));

    for(int i = key_size - 1; i <= board_size - key_size ; i++) {
        for(int j = key_size - 1; j <= board_size - key_size; j++) {
            board[i][j] = lock[i - key_size + 1][j - key_size + 1];
        }
    }

    for(int i = 0; i < 4; i ++) {
        for(int j = 0; j <= board_size - key_size; j++) {
            for(int k = 0; k <= board_size - key_size; k++) {
                if(checkKey(j, k, key, board)) {
                    return true;
                }
            }
        }
        rotateKey(key);
    }
    
    return false;
}