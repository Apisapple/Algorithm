#include <iostream>
#include <vector>

#define MAX 51

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int width, height;
void DFS(vector< vector<int> > map, vector<vector<bool> > &visit, int x, int y) {
    visit[x][y] = true;
    for(int k = 0; k < 4; k ++) {
        int next_x = x + dx[k];
        int next_y = y + dy[k];
        if(0 <= next_x || next_x < width || 0 <= next_y || next_y < height) {
            if(map[next_x][next_y]  == 1 && !visit[next_x][next_y]) {
                DFS(map, visit, next_x, next_y);
            }
        }
    }
}

int main(int argc, const char** argv) {
    int test_case, point;
    int result = 0;
    cin >> test_case;
    for(int i = 0; i < test_case; i ++) {
        cin >> width >> height >> point;
        vector< vector<int> > map(width, vector<int> (height, 0));
        vector< vector<bool> > visit(width, vector<bool>(height, false));
        // 좌표 입력
        for(int j = 0; j < point; j++) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }

        // 탐색
        for(int p = 0; p < width; p++) {
            for(int q = 0; q < height; q++) {
                if(map[p][q] == 1 && !visit[p][q]) {
                    DFS(map, visit, p, q);
                    result ++;
                }
            }
        }
        cout << result << endl;
    }
    
    return 0;
}