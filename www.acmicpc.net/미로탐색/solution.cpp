#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int height, width, count;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y, vector< vector <int> > &board) {
    queue <pair <int, int> > que;
    que.push(make_pair(0, 0));

    while(!que.empty()) {
        pair <int, int> current = que.front();
        que.pop();
        
        for(int i = 0; i < 4; i ++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];

            if(0 <= nx && nx < width && 0 <= ny && ny < height && board[ny][nx] == 1) {
                que.push(make_pair(nx, ny));
                board[ny][nx] = board[current.second][current.first] + 1;
            }
        }
    }
}

int main() {
    cin >> height >> width;

    // 미로 값 입력
    vector < vector <int> > maze(height, vector<int> (width, 0));
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int temp = 0;
            scanf("%1d", &temp);
            maze[i][j] = temp;
        }
    }
    // 완전 탐색 시작
    DFS(0 , 0, maze);

    // 정답 출력
	cout << maze[height - 1][width - 1];
    return 0;
}