#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

stack<int> check_point(vector<int> information) {
  stack<int> result_value;

  for (int point : information) {
    if (point != 0) {
      result_value.push(point);
    }
  }

  return result_value;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
  long long answer = -1;
  stack<int> deliveries_point = check_point(deliveries);
  stack<int> pickups_point = check_point(pickups);

  while(!deliveries_point.empty() && !pickups_point.empty()) {
    answer += max(deliveries_point.size() * 2, pickups_point.size() * 2);
    empty_box = 0;
    while(!deliveries_point.empty() && empty_box <= cap) {
      
    }

  }

  return answer;
}

int main() {
  int cap = 0;
  vector<int> deliveries = {1};
  vector<int> pickups = {1};

  solution(cap, deliveries, pickups);

  return 0;
}