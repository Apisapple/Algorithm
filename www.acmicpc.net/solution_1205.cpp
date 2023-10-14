#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void init();
int main() {
  init();

  int n, score, p;
  cin >> n >> score >> p;

  vector<int> scores(n);

  for (int i = 0; i < n; i++) {
    cin >> scores[i];
  }
  scores.push_back(score);

  sort(scores.begin(), scores.end(), greater<int>());

  int rank = 0, idx = 0;
  for (idx = 0; idx < scores.size(); idx++) {
    rank = idx + 1;

    while (idx + 1 < scores.size() && scores[idx + 1] == scores[idx])
      idx++;

    if (scores[idx] == score)
      break;
  }

  idx < p ? cout << rank : cout << -1;

  return 0;
}

void init() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
}