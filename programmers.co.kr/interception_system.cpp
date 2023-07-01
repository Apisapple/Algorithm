#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> get_sorting_targets(vector<vector<int>> targets) {
  vector<pair<int, int>> result;

  for (vector<int> target : targets) {
    result.push_back(make_pair(target[0], target[1]));
  }

  sort(result.begin(), result.end());

  return result;
}

int cnt_minimum_missile(vector<pair<int, int>> targets) {
  int minimum_missil = 1, index = targets[0].second;

  for (int i = 1; i < targets.size(); i++) {
    if (targets[i].first >= index) {
      minimum_missil++;
      index = targets[i].second;
    } else {
      index = min(index, targets[i].second);
    }
  }

  return minimum_missil;
}

int solution(vector<vector<int>> targets) {
  int answer = 0;

  // 1. sorting targets information
  vector<pair<int, int>> sorting_targets = get_sorting_targets(targets);

  // 2. count minimum shooting
  return cnt_minimum_missile(sorting_targets);
}