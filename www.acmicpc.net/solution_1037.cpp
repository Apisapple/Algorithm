#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void init() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {

  init();

  int N;
  cin >> N;

  vector<int> numbers(N);
  for (int i = 0; i < N; i++) {
    cin >> numbers[i];
  }

  sort(numbers.begin(), numbers.end());
  
  cout << numbers[0] * numbers[N - 1] << '\n';

  return 0;
}
