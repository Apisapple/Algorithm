#include <algorithm>
#include <deque>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void init();
int solution(vector<int> elements);
deque<int> migrationToDeque(vector<int> elements);
int getSum(const deque<int> &que, int index);
int main() {
  init();

  cout << solution({7, 9, 1, 1, 4}) << '\n';

  return 0;
}

void init() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
}

int solution(vector<int> elements) {
  deque<int> que = migrationToDeque(elements);
  set<int> sums;

  for (int index = 1; index < que.size(); index++) {
    for (int start = 0; start < que.size(); start++) {
      int sum = getSum(que, index);

      sums.insert(sum);
      que.push_back(que.front());
      que.pop_front();
    }
  }

  int sum = getSum(que, que.size());
  sums.insert(sum);

  return sums.size();
}

deque<int> migrationToDeque(vector<int> elements) {
  deque<int> result(elements.size());

  for (int i = 0; i < elements.size(); ++i) {
    result[i] = elements[i];
  }

  return result;
}

int getSum(const deque<int> &que, int index) {
  int sum = 0;

  for (int i = 0; i < index; i++) {
    sum += que[i];
  }

  return sum;
}