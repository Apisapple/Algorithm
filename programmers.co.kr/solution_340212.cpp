#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void init() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
}

bool isPossible(vector<int> &diffs, vector<int> &times, long long limit, int level) {
  long long currentTime = 0, prevTime = 0;

  for (uint32_t i = 0; i < diffs.size(); i++) {
    if (level >= diffs[i]) {
      currentTime += times[i];
    } else {
      long long repeatCount = diffs[i] - level;
      currentTime += times[i] + (times[i] + prevTime) * repeatCount;
    }
    prevTime = times[i];
    if (currentTime > limit)
      return false;
  }

  return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
  int leftIndex = 1, rightIndex = 300000, answer = INT32_MAX;

  while (leftIndex <= rightIndex) {
    int midIndex = (leftIndex + rightIndex) / 2;

    if (isPossible(diffs, times, limit, midIndex)) {
      rightIndex = midIndex - 1;
      answer = min(answer, midIndex);
    } else {
      leftIndex = midIndex + 1;
    }
  }

  return answer;
}

int main() {
  init();
  cout << solution({1, 5, 3}, {2, 4, 7}, 30) << '\n';
  cout << solution({1, 4, 4, 2}, {6, 3, 8, 2}, 59) << '\n';
  cout << solution({1, 328, 467, 209, 54}, {2, 7, 1, 4, 3}, 1723) << '\n';
  cout << solution({1, 99999, 100000, 99995}, {9999, 9001, 9999, 9001}, 3456789012) << '\n';

  assert(3 == solution({1, 5, 3}, {2, 4, 7}, 30));
  assert(2 == solution({1, 4, 4, 2}, {6, 3, 8, 2}, 59));
  assert(294 == solution({1, 328, 467, 209, 54}, {2, 7, 1, 4, 3}, 1723));
  assert(39354 == solution({1, 99999, 100000, 99995}, {9999, 9001, 9999, 9001}, 3456789012));
}