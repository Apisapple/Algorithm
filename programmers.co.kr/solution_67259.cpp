#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define MAX 25

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int MAP[MAX][MAX][4];
struct Car {
  int x;
  int y;
  int cost;
  int dir;
};

void init() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
}

int solution(vector<vector<int>> board) {
  int answer = INT32_MAX;

  int N = board.size();
  int M = board[0].size();

  queue<Car> que;
  que.push(Car{0, 0, 0, 1});
  que.push(Car{0, 0, 0, 2});

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      for (int k = 0; k < 4; k++) {
        MAP[i][j][k] = INT32_MAX;
      }
    }
  }

  MAP[0][0][1] = 0;
  MAP[0][0][2] = 0;

  while (!que.empty()) {
    Car now = que.front();

    int nowX = now.x;
    int nowY = now.y;
    int nowCost = now.cost;
    int nowDir = now.dir;
    que.pop();

    if (nowX == N - 1 && nowY == M - 1) {
      answer = min(answer, nowCost);
      continue;
    }

    for (int i = 0; i < 4; i++) {
      int nextX = nowX + dx[i];
      int nextY = nowY + dy[i];
      int add = 0;

      if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
        continue;

      if (board[nextX][nextY] != 1) {
        if (nowDir == i) {
          add = nowCost + 100;
        } else {
          add = nowCost + 600;
        }

        if (MAP[nextX][nextY][i] >= add) {
          MAP[nextX][nextY][i] = add;
          que.push(Car{nextX, nextY, add, i});
        }
      }
    }
  }

  return answer;
}

int main() {
  init();

  assert(solution({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}) == 900);
  assert(solution({{0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0}}) == 2100);
  assert(solution({{0, 0, 0, 0, 0, 0},
                   {0, 1, 1, 1, 1, 0},
                   {0, 0, 1, 0, 0, 0},
                   {1, 0, 0, 1, 0, 1},
                   {0, 1, 0, 0, 0, 1},
                   {0, 0, 0, 0, 0, 0}}) == 3200);
  assert(solution({{0, 0, 0, 0, 0, 0, 0, 1},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0, 0},
                   {0, 0, 0, 1, 0, 0, 0, 1},
                   {0, 0, 1, 0, 0, 0, 1, 0},
                   {0, 1, 0, 0, 0, 1, 0, 0},
                   {1, 0, 0, 0, 0, 0, 0, 0}}) == 3800);
}