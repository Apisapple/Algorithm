#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int left_index = 0;
    int right_index = height.size() - 1;
    int answer = calc_area(right_index - left_index, min(height[left_index], height[right_index]));

    while (left_index < right_index) {
      if (height[left_index] <= height[right_index]) {
        ++left_index;
      } else {
        --right_index;
      }

      answer = max(answer, calc_area(right_index - left_index, min(height[left_index], height[right_index])));
    }

    return answer;
  }

  int calc_area(int height, int width) { return height * width; }
};