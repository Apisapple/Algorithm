#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    vector<int> keys = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    map<int, string> roman_map;
    string answer = "";

    roman_map[1] = "I";
    roman_map[4] = "IV";
    roman_map[5] = "V";
    roman_map[9] = "IX";
    roman_map[10] = "X";
    roman_map[40] = "XL";
    roman_map[50] = "L";
    roman_map[90] = "XC";
    roman_map[100] = "C";
    roman_map[400] = "CD";
    roman_map[500] = "D";
    roman_map[900] = "CM";
    roman_map[1000] = "M";

    while (0 < num) {
      bool flag = true;

      for (int i = 0; i < keys.size(); i++) {
        if (i + 1 < keys.size() && num >= keys[i] && num < keys[i + 1]) {
          answer += roman_map[keys[i]];
          num -= keys[i];
          flag = false;
          break;
        }
      }

      if (flag) {
        answer += 'M';
        num -= 1000;
      }
    }

    return answer;
  }
};