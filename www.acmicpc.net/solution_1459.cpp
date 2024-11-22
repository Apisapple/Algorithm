#include <algorithm>
#include <iostream>

using namespace std;

void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {

  init();

  long long x, y, w, s;
  cin >> x >> y >> w >> s;

  long long answerA = (x + y) * w;
  long long answerB = min(x, y) * s;
  answerB += min(abs(x - y) * w, (abs(x - y) % 2 == 1 ? (abs(x - y) - 1) * s + w : abs(x - y) * s));

  cout << min(answerA, answerB) << '\n';

  return 0;
}