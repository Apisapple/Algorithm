#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define MAX_SIZE 100

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<vector<bool>> visited(MAX_SIZE + 1, vector<bool>(MAX_SIZE + 1, false));
void makeAnswer(vector<string> &maps, vector<int> &answer);
vector<vector<bool>> makeVisitedMap(vector<string> &maps);
void searchMaxNumberOfDays(vector<string> &maps, vector<int> &answer, int y, int x);

bool isEndOfLand(vector<vector<bool>> visited);
vector<int> solution(vector<string> maps) {
  vector<int> answer;

  makeAnswer(maps, answer);

  return answer;
}

void makeAnswer(vector<string> &maps, vector<int> &answer) {

  for (int i = 0; i < maps.size(); i++) {
    for (int j = 0; j < maps[i].size(); j++) {
      if (maps[i][j] != 'X' && !visited[i][j]) {
        searchMaxNumberOfDays(maps, answer, i, j);
      }
    }
  }

  sort(answer.begin(), answer.end());

  if (answer.size() == 0)
    answer.push_back(-1);
}

// TODO : searchMaxNumberOfDays 함수 구현 필요
void searchMaxNumberOfDays(vector<string> &maps, vector<int> &answer, int y, int x) {
  queue<pair<int, int>> que;
  int result = 0;
  que.push({x, y});
  visited[y][x] = true;

  while (!que.empty()) {
    int current_x = que.front().first;
    int current_y = que.front().second;
    result += (maps[current_y][current_x] - '0');
    que.pop();

    for (int i = 0; i < 4; i++) {
      int next_x = current_x + dx[i];
      int next_y = current_y + dy[i];

      if (next_x < 0 || next_y < 0 || next_y >= maps.size() || next_x >= maps[y].size() || visited[next_y][next_x]) {
        continue;
      }

      if (maps[next_y][next_x] != 'X') {
        visited[next_y][next_x] = true;
        que.push({next_x, next_y});
      }
    }
  }

  answer.push_back(result);
}