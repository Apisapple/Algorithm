#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
private:
  map<char, string> m = {{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                         {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

  vector<string> result;

public:
  vector<string> letterCombinations(string digits) {
    if (digits.size() != 0) {
      generateCombinations("", digits, 0);
    }

    return result;
  }

  void generateCombinations(string current, string digits, int index) {
    if (index == digits.size()) {
      result.push_back(current);
    } else {
      char current_digit = digits[index];
      string mapping = m[current_digit];
      for (int i = 0; i < mapping.size(); i++) {
        generateCombinations(current + mapping[i], digits, index + 1);
      }
    }
  }
};