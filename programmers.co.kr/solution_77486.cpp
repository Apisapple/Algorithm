#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, string> parents;
unordered_map<string, int> gain;

void update_gain(const string &now, int sell_again) {
  if (now == "-")
    return;

  int delivery = sell_again / 10;
  gain[now] += sell_again - delivery;

  if (delivery == 0)
    return;

  update_gain(parents[now], delivery);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {

  vector<int> answer;

  for (size_t i = 0; i < enroll.size(); i++) {
    parents[enroll[i]] = referral[i];
  }

  for (size_t i = 0; i < seller.size(); i++) {
    update_gain(seller[i], amount[i] * 100);
  }

  for (const auto &name : enroll) {
    answer.push_back(gain[name]);
  }

  return answer;
}

// int main() {
//   vector<int> answer = solution({"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"},
//                                 {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
//                                 {"young", "john", "tod", "emily", "mary"}, {12, 4, 2, 5, 10});

//   for (const auto &value : answer) {
//     cout << value << " ";
//   }
//   cout << '\n';

//   return 0;
// }
