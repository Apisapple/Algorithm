#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 51

using namespace std;

int width = 0, height = 0, total_count = 0;
int countArea = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(int height_value, int width_value, vector <vector <int>> board, vector< vector<bool>> &visited) {
    visited[height_value][width_value] = true;
    for(int i = 0; i < 4; i ++) {
        int next_x = width_value + dx[i];
        int next_y = height_value + dy[i];
        if(0 <= next_x  && next_x < width && 0 <= next_y && next_y < height) {
            if(board[next_y][next_x] == 1 && !visited[next_y][next_x]) {
                DFS(next_y, next_x, board, visited);
            }
        }
    }
}

int main() {
    int test_case = 0;
    cin >> test_case;
    for(int i = 0; i < test_case; i++) {
        cin >> width >> height >> total_count;
        countArea = 0;
        vector< vector <int> > board(height, vector <int> (width, 0 ));
        vector< vector <bool> > visited(height, vector <bool> (width, false ));
        // 배추 심기
        for(int j = 0; j < total_count; j++) {
            int width_value, height_value;
            cin >> width_value >> height_value;
            board[height_value][width_value] = 1;
        }

        // 탐색
        for(int p = 0; p < height; p++) {
            for(int q = 0; q < width; q++) {
                if(board[p][q] == 1 && !visited[p][q]) {
                    countArea ++;
                    DFS(p, q, board, visited);
                }
            }
        }
        cout << countArea << endl;
    }
    return 0;
}