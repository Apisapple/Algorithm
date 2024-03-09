#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int answer = nums[0] + nums[1] + nums[2];
    int nums_size = nums.size();

    for (int start = 0; start < nums_size - 2; start++) {

      for (int end = start + 1, pivot = nums_size - 1; end < pivot;) {

        int current_sum = nums[start] + nums[end] + nums[pivot];

        if (abs(current_sum - target) < abs(answer - target)) {
          answer = current_sum;
        }

        if (current_sum - target == 0) {
          return current_sum;
        } else if (current_sum - target > 0) {
          --pivot;
        } else {
          ++end;
        }
      }
    }

    return answer;
  }
};