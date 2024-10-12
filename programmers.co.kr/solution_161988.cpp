#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

void init() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
}

vector<int> makePurseSequence(vector<int> &sequence, int num) {
  std::vector<int> result(sequence.size());

  std::vector<int> indices(sequence.size());
  std::iota(indices.begin(), indices.end(), 0);

  std::transform(indices.begin(), indices.end(), result.begin(),
                 [&sequence, num](int i) { return sequence[i] * (i % 2 == 0 ? num : -num); });

  return result;
}

long long solution(vector<int> sequence) {
  long long answer = INT64_MIN;
  vector<int> minusSequence = makePurseSequence(sequence, -1);
  vector<int> plusSequence = makePurseSequence(sequence, 1);

  size_t sequenceSize = sequence.size();
  long long plusSequenceDP[sequenceSize];
  long long minusSequenceDP[sequenceSize];

  plusSequenceDP[0] = plusSequence[0];
  minusSequenceDP[0] = minusSequence[0];

  if (sequenceSize == 1) {
    return max(plusSequence[0], minusSequence[0]);
  }

  for (size_t i = 1; i < sequenceSize; i++) {
    plusSequenceDP[i] = max(plusSequenceDP[i - 1] + (long long)plusSequence[i], (long long)plusSequence[i]);
    answer = max(answer, plusSequenceDP[i]);
  }

  for (size_t i = 1; i < sequenceSize; i++) {
    minusSequenceDP[i] = max(minusSequenceDP[i - 1] + (long long)minusSequence[i], (long long)minusSequence[i]);
    answer = max(answer, minusSequenceDP[i]);
  }

  return answer;
}

int main() {
  init();

  assert(10 == solution({2, 3, -6, 1, 3, -1, 2, 4}));
  return 0;
}