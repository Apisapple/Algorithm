#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int numSize = nums.size();

    int index;
    for (index = numSize - 2; 0 <= index; index--) {
      if (nums[index] < nums[index + 1]) {
        break;
      }
    }

    if (index >= 0)
      for (int j = numSize - 1; j > index; --j)
        if (nums[j] > nums[index]) {
          swap(nums[index], nums[j]);
          break;
        }

    reverse(nums, index + 1, numSize - 1);
  }

private:
  void reverse(vector<int> &nums, int l, int r) {
    while (l < r)
      swap(nums[l++], nums[r--]);
  }
};