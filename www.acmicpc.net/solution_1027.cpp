#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void init();

int main() {
  init();

  size_t N;
  cin >> N;

  vector<int> buildings(N, 0);
  for (size_t i = 0; i < N; i++) {
    cin >> buildings[i];
  }

  vector<int> visibleBuildings(N, 0);
  for (size_t i = 0; i < N; i++) {
    double maxLevel = INT32_MIN;

    for (size_t j = i + 1; j < N; j++) {
      double level = (double)(buildings[j] - buildings[i]) / (j - i);
      if (level > maxLevel) {
        visibleBuildings[i]++;
        visibleBuildings[j]++;
        maxLevel = level;
      }
    }
  }

  cout << *max_element(visibleBuildings.begin(), visibleBuildings.end()) << '\n';

  return 0;
}

void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}