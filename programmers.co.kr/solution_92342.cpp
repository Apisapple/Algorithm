#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> ANSWER(1, -1);
int MAX_DIFF = 0;

void init();
vector<int> solution(int n, vector<int> info);
void getAnswer(int index, int arrows, vector<int> ryan, vector<int> apeache);
void calcPoint(vector<int> ryan, vector<int> apeache);
bool compare(vector<int> ryan);

int main() {
  init();

  vector<int> answer = solution(5, {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0});
  for (int ans : answer) {
    cout << ans << ' ';
  }
  cout << '\n';

  answer = solution(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  for (int ans : answer) {
    cout << ans << ' ';
  }
  cout << '\n';

  answer = solution(9, {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1});
  for (int ans : answer) {
    cout << ans << ' ';
  }
  cout << '\n';

  answer = solution(10, {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3});
  for (int ans : answer) {
    cout << ans << ' ';
  }
  cout << '\n';

  return 0;
}

void init() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
}

vector<int> solution(int n, vector<int> info) {
  vector<int> ryan(11, 0);

  getAnswer(0, n, ryan, info);

  if (ANSWER.empty()) {
    ANSWER.push_back(-1);
  }

  return ANSWER;
}

void getAnswer(int index, int arrows, vector<int> ryan, vector<int> apeache) {
  if (index == 11 || arrows == 0) {
    ryan[10] += arrows;
    calcPoint(ryan, apeache);
    ryan[10] -= arrows;
    return;
  }

  if (apeache[index] < arrows) {
    ryan[index] += apeache[index] + 1;
    getAnswer(index + 1, arrows - apeache[index] - 1, ryan, apeache);
    ryan[index] -= apeache[index] + 1;
  }

  getAnswer(index + 1, arrows, ryan, apeache);
}

void calcPoint(vector<int> ryan, vector<int> apeache) {
  int ryanPoint = 0, apeachePoint = 0;

  for (int i = 0; i < 11; i++) {
    if (ryan[i] > apeache[i]) {
      ryanPoint += 10 - i;
    } else if (apeache[i] > 0) {
      apeachePoint += 10 - i;
    }
  }

  int diff = ryanPoint - apeachePoint;
  if (diff > 0 && MAX_DIFF <= diff) {
    if (MAX_DIFF == diff && !compare(ryan)) {
      return;
    }

    MAX_DIFF = diff;
    ANSWER = ryan;
  }
}

bool compare(vector<int> ryan) {
  for (int i = 10; i >= 0; i--) {
    if (ryan[i] > ANSWER[i])
      return true;
    else if (ryan[i] < ANSWER[i])
      return false;
  }
}