#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define MAX_LEN 100

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

pair<int, int> getRobotPosition(vector<string> &board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      if (board[i][j] == 'R') {
        return make_pair(i, j);
      }
    }
  }
}

int solution(vector<string> board) {
  vector<vector<int>> visited(MAX_LEN, vector<int>(MAX_LEN, -1));

  pair<int, int> robot_position = getRobotPosition(board);

   queue<pair<int, int>> que;

  int n = board.size();
  int m = board[0].size();
  que.push(robot_position);
  visited[robot_position.first][robot_position.second] = 0;

  while (!que.empty()) {
    pair<int, int> current_position = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int next_x = current_position.first;
      int next_y = current_position.second;

      while (true) {
        if (next_x < 0 || next_y < 0 || n <= next_x || m <= next_y) {
          break;
        }

        if (board[next_x][next_y] == 'D') {
          break;
        }

        next_x += dx[i];
        next_y += dy[i];
      }
      next_x -= dx[i];
      next_y -= dy[i];

      if (board[next_x][next_y] == 'G') {
        return visited[current_position.first][current_position.second] + 1;
      }

      if (visited[next_x][next_y] >= 0) {
        continue;
      }

      visited[next_x][next_y] = visited[current_position.first][current_position.second] + 1;
      que.push({next_x, next_y});
    }
  }
  return -1;
}