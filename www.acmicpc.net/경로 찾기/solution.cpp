#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 100

using namespace std;

vector <vector<int>> answer_board(MAX, vector<int>(MAX));
int board_size = 0;

void DFS(int start, vector<bool> &visited, vector<vector<int>> &board) {
    for(int i = 0; i < board[start].size(); i++) {
        if(board[start][i] == 1 && !visited[i]) {
            visited[i] = true;
            DFS(i, visited, board);
        }
    }
}

int main() {
    cin >> board_size;
    vector <vector <int>> board(board_size, vector<int>(board_size, 0));
    // 그래프 정보 입력
    for(int i = 0; i < board_size; i++){
        for(int j = 0; j < board_size; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < board_size; i++) {
        vector<bool> visited(board_size, false);
        DFS(i, visited, board);

        for(int j = 0; j < visited.size(); j++) {
            if(visited[j])
                answer_board[i][j] = 1;
        }

    }

    for(int i = 0; i < board_size; i++) {
        for(int j = 0; j < board_size; j++) {
            cout << answer_board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}