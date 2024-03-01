#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    long answer = 0;

    if (!verify_scope(x)) {
      return 0;
    }

    bool is_negative = false;
    if (x < 0) {
      is_negative = true;
      x *= -1;
    }

    while (0 < x) {
      int temp = x % 10;
      x /= 10;
      answer = answer * 10 + temp;
    }

    if (!verify_scope(answer)) {
      return 0;
    }

    if (is_negative) {
      answer *= -1;
    }

    if (!verify_scope(answer)) {
      return 0;
    }

    return answer;
  }

  bool verify_scope(int x) {
    if (x <= INT32_MIN || INT32_MAX <= x) {
      return false;
    }

    return true;
  }

  bool verify_scope(long x) {
    if (x <= INT32_MIN || INT32_MAX <= x) {
      return false;
    }

    return true;
  }
};