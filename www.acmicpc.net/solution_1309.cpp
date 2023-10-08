#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 100000

int main() {
  int N = 0;
  vector<int> dp(MAX + 1, 0);

  cin >> N;
  dp[0] = 1;
  dp[1] = 3;

  for (int i = 2; i <= N; i++) {
    dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
  }

  cout << dp[N] <<'\n';
}