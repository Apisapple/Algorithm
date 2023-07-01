#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

stack<int> go_path, back_path;

void set_deliveries_info(vector<int> deliveries) {
  for (auto delivery : deliveries)
    go_path.push(delivery);
}

void set_pickups_info(vector<int> pickups) {
  for (auto pickup : pickups) {
    back_path.push(pickup);
  }
}

void check_delivery_info() {
  while (!go_path.empty() && !go_path.top()) {
    go_path.pop();
  }
}

void check_pickup_info() {
  while (!back_path.empty() && !back_path.top()) {
    back_path.pop();
  }
}

long long get_answer(int cap) {
  long long answer = 0;
  int box_count = 0;
  while (!(go_path.empty() && back_path.empty())) {
    answer += max(go_path.size() * 2, back_path.size() * 2);

    box_count = 0;
    while (!go_path.empty() && box_count <= cap) {
      if (go_path.top() + box_count <= cap)
        box_count += go_path.top();
      else {
        go_path.top() -= (cap - box_count);
        break;
      }
      go_path.pop();
    }
    box_count = 0;
    while (!back_path.empty() && box_count <= cap) {
      if (back_path.top() + box_count <= cap)
        box_count += back_path.top();
      else {
        back_path.top() -= (cap - box_count);
        break;
      }
      back_path.pop();
    }
  }

  return answer;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
  set_deliveries_info(deliveries);
  set_pickups_info(pickups);

  check_delivery_info();
  check_pickup_info();

  return get_answer(cap);
}

int main() {
  int cap = 4, n = 5;
  vector<int> deliveries = {1, 0, 3, 1, 2};
  vector<int> pickups = {0, 3, 0, 4, 0};

  solution(cap, n, deliveries, pickups);

  return 0;
}