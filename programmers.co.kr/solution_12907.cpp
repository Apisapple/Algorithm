#include <cassert>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < money.size(); i++) {
    for (size_t j = money[i]; j <= n; j++) {
      dp[j] += dp[j - money[i]];
      dp[j] %= 1000000007;
    }
  }
  return dp[n];
}

int main() {
  int n = 5;
  vector<int> money = {1, 2, 5};
  //   solution(n, money); // 4
  assert(solution(n, money) == 4);
  return 0;
}