#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void init();
void getNumberOfCases(int n, int k, vector<int> &sportsKits);

int main() {
  init();

  int n = 0, k = 0;

  cin >> n >> k;

  vector<int> sportsKits(n);
  for (int i = 0; i < n; i++) {
    cin >> sportsKits[i];
  }

  getNumberOfCases(n, k, sportsKits);
  return 0;
}

void init() {
  std::ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
}

void getNumberOfCases(int n, int k, vector<int> &sportsKits) {
  int answer = 0;
  vector<int> permutation(n, 0);

  for (int i = 0; i < n; i++) {
    permutation[i] = i;
  }

  do {
    int weight = 500;
    for (int i = 0; i < n; i++) {
      weight += sportsKits[permutation[i]] - k;
      if (weight < 500) {
        break;
      }
    }

    if (weight >= 500) {
      answer++;
    }
  } while (next_permutation(permutation.begin(), permutation.end()));

  cout << answer << '\n';
}