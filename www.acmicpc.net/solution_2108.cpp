#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void init() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main() {
  init();

  int N, total = 0;
  cin >> N;

  vector<int> numbers(N);
  unordered_map<int, int> freq;
  for (int i = 0; i < N; i++) {
    cin >> numbers[i];
    total += numbers[i];
    freq[numbers[i]]++;
  }

  sort(numbers.begin(), numbers.end());
  int mean = round((double)total / N);
  int median = numbers[N / 2];

  vector<pair<int, int>> temp(freq.begin(), freq.end());
  sort(temp.begin(), temp.end(), [](pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
      return a.first < b.first;
    }
    return a.second > b.second;
  });
  int freqValue = temp[0].first;
  if (temp.size() > 1 && temp[0].second == temp[1].second) {
    freqValue = temp[1].first;
  }

  int range = numbers[N - 1] - numbers[0];
  cout << mean << '\n' << median << '\n' << freqValue << '\n' << range;
  return 0;
}
