#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {

    const size_t STR_LENGTH = s.length();
    if (STR_LENGTH <= 1) {
      return s;
    }

    int start = 0, maxLength = 1;
    for (int i = 0; i < STR_LENGTH; i++) {
      for (int j = 0; j <= 1; j++) {
        int low = i;
        int high = i + j;

        while (0 <= low & high < STR_LENGTH && s[low] == s[high]) {
          int currentLength = high - low + 1;
          if (currentLength > maxLength) {
            start = low;
            maxLength = currentLength;
          }

          low--;
          high++;
        }
      }
    }

    return s.substr(start, maxLength);
  }
};

int main() {

  Solution solution;

  assert(solution.longestPalindrome("babad").compare("bab") == 0);
  assert(solution.longestPalindrome("cbbd").compare("bb") == 0);

  return 0;
}
