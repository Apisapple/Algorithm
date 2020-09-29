#include <iostream>
#include <vector>

#define MAX 50

using namespace std;

int width, height;
int land_count = 0;
int dx[8] = {1, -1, 0, 0, 1 , 1, -1, -1};
int dy[8] = {0, 0, 1, -1 , -1, 1, -1, 1};
vector <vector<int> > visited;

void DFS(int y, int x, vector< vector <int> > board) {
    visited[y][x] = 1;
    land_count ++;

    for(int i = 0; i < 8; i++) {
        int next_height = y + dy[i];
        int next_width = x + dx[i];
        if(0 <= next_height && next_height < height && 0 <= next_width && next_width < width) {
            if(visited[next_height][next_width] == 0 && board[next_height][next_width] == 1)
                DFS(next_height, next_width, board);
        }
    }
}

int main() {

    while(1) {
        cin >> width >> height;
        land_count = 0;
        if(width == 0 || height == 0)
            return 0;
        
        vector <vector <int> > board(width, vector<int> (height, 0));
        visited = board;
        // board 내용 입력
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                cin >> board[i][j];
            }
        }

        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j ++) {
                if(visited[i][j] == 0 && board[i][j] == 1) {
                    DFS(i, j, board);
                }
            }
        }
        cout << land_count << endl;
    }
}