#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
  int answer = 0;

  vector<int> left(a.size(), 0);
  vector<int> right(a.size(), 0);

  int minValue = a[0];
  for (int i = 0; i < a.size(); i++) {
    minValue = min(minValue, a[i]);
    left[i] = minValue;
  }

  minValue = a[a.size() - 1];
  for (int i = a.size() - 1; i >= 0; i--) {
    minValue = min(minValue, a[i]);
    right[i] = minValue;
  }

  for (int i = 0; i < a.size(); i++) {
    if (a[i] <= left[i] || a[i] <= right[i]) {
      answer++;
    }
  }

  return answer;
}

int main() {
  vector<int> test_1 = {9, -1, -5};
  vector<int> test_2 = {-16, 27, 65, -2, 58, -92, -71, -68, -61, -33};

  assert(solution(test_1) == 3 && "test_1 failed");
  assert(solution(test_2) == 6 && "test_2 failed");
}