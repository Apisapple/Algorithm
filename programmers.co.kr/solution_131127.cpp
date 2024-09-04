#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void init();
int solution(vector<string> want, vector<int> number, vector<string> discount);
bool isSaleItems(map<string, int> items);
map<string, int> wishItems;

int main() {

  init();

  int result = solution({"banana", "apple", "rice", "pork", "pot"}, {3, 2, 2, 2, 1},
                        {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice",
                         "pot", "banana", "apple", "banana"});
  assert(3 == result);

  result =
      solution({"apple"}, {10},
               {"banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana"});
  assert(0 == result);

  return 0;
}

void init() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
  int answer = 0;

  for (int i = 0; i < want.size(); i++) {
    wishItems[want[i]] = number[i];
  }
  for (int i = 0; i <= discount.size() - 10; i++) {
    map<string, int> m;
    for (int j = i; j < i + 10; j++) {
      m[discount[j]]++;
    }
    answer += isSaleItems(m);
    m.clear();
  }

  return answer;
}

bool isSaleItems(map<string, int> items) {
  for (auto iter : wishItems) {
    if (items.find(iter.first) == items.end()) {
      return false;
    } else if (items[iter.first] != iter.second) {
      return false;
    }
  }

  return true;
}