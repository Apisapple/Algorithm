#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {

public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int count = 0;
    set<vector<int>> temp;

    for (int i = 0; i < nums.size(); i++) {
      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];

        if (sum == 0) {
          vector<int> v = {nums[i], nums[left], nums[right]};
          temp.insert(v);
          left++;
        } else if (sum < 0) {
          left++;
        } else {
          right--;
        }
      }
    }

    vector<vector<int>> result;
    for (auto it = temp.begin(); it != temp.end(); it++) {
      result.push_back(*it);
    }

    return result;
  }
};