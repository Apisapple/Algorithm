#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
  int answer = 0;

  int start = *min_element(stones.begin(), stones.end());
  int end = *max_element(stones.begin(), stones.end());
  int mid = 0;

  while (start <= end) {
    mid = (start + end) / 2;

    int jumpingCount = 0;
    int maxJupingCount = 0;

    vector<int> temp(stones);

    for (int i = 0; i < temp.size(); i++) {
      temp[i] -= mid;

      if (temp[i] < 0) {
        jumpingCount++;
      } else {
        jumpingCount = 0;
      }

      maxJupingCount = max(maxJupingCount, jumpingCount);
    }

    if (maxJupingCount < k) {
      answer = max(answer, mid);
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return answer;
}