#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    bool isPalindrome(int x) { 
        string number = to_string(x);
        int number_len = number.length();
        if(number_len % 2 == 0) {   // 길이가 짝수
            for(int i = 0; i < (number_len / 2); i++) {
                if(number[i] != number[number_len - i - 1])
                    return false;
            }
        } else { // 길이가 홀수
            for(int i = 0; i < (number_len / 2) + 1; i++) {
                if(number[i] != number[number_len - i - 1])
                    return false;
            }
        }
        return true;
    }
};
