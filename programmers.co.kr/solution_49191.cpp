#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {

  vector<vector<int>> nodes(n + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++) {
    nodes[i][i] = 0;
  }

  for (auto result : results) {
    nodes[result[0]][result[1]] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (nodes[i][k] && nodes[k][j]) {
          nodes[i][j] = 1;
        }
      }
    }
  }

  int answer = 0;
  for (int i = 1; i <= n; ++i) {
    bool isPossible = true;
    for (int j = 1; j <= n; ++j) {
      if (i == j)
        continue;
      if (!nodes[i][j] && !nodes[j][i]) {
        isPossible = false;
        break;
      }
    }
    if (isPossible) {
      answer++;
    }
  }

  return answer;
}

int main() {

  assert(solution(5, {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}}) == 2);

  return 0;
}
