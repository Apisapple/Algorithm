#include <map>
#include <string>

using namespace std;

class Solution {
  public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            int current_num = roman_value[s[i]];
            int next_num = roman_value[s[i + 1]];

            if(current_num < next_num) {
                result += (next_num - current_num);
                i ++;
                continue;
            } else {
                result += current_num;
            }
        }

        return result;
    }

  private:
    map<char, int> roman_value = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                  {'C', 100}, {'D', 500}, {'M', 1000}};
};