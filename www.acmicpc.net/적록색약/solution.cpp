#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board_size = 0, cnt_medicine = 0, cnt_notMedicine = 0;

void DFS(vector <vector <int>> &board, int value, int x, int y) {
    board[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < board_size && 0 <= ny && ny < board_size) {
            if(board[nx][ny] == value)
                DFS(board, value, nx, ny);
        }
    }
    return;
}

int main() {
    cin >> board_size;
    vector <vector <int>> medicine(board_size, vector<int>(board_size, 0));
    vector <vector <int>> notMedicine(board_size, vector<int> (board_size, 0));

    for(int i = 0; i < board_size; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < temp.size(); j++) {
            switch (temp[j])
            {
            case 'R':
                medicine[i][j] = 1;
                notMedicine[i][j] = 1;
                break;
            case 'G':
                medicine[i][j] = 2;
                notMedicine[i][j] = 1;
                break;
            case 'B':
                medicine[i][j] = 3;
                notMedicine[i][j] = 2;
                break;
            }
        }
    }

    for(int i = 0; i < board_size; i++) {
        for(int j = 0; j < board_size; j++) {
            if(medicine[i][j] != 0) {
                cnt_medicine ++;
                DFS(medicine, medicine[i][j], i, j);
            }
            if(notMedicine[i][j] != 0) {
                cnt_notMedicine ++;
                DFS(notMedicine, notMedicine[i][j], i, j);
            }
        }
    }
    cout << cnt_medicine << " " << cnt_notMedicine << endl;
    return 0;
}