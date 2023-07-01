#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        int min_str_len = 201;
        string result = "";
        bool prefix_end = true;

        // 제일 짧은 글자 찾기
        for(string str : strs) {
            if(str.length() < min_str_len) {
                min_str_len = str.length();
            }
        }

        for(int index = 0; index < min_str_len; index ++) {
            char temp = strs[0][index];
            for(int i = 0; i < strs.size(); i++) {
                if(temp == strs[i][index] && i == strs.size() - 1) {
                    result.push_back(temp);
                } else if (temp != strs[i][index] ) {
                    prefix_end = false;
                    break;
                }
                continue;
            }
            if(!prefix_end) {
                break;
            }
        }
        return result;
    }
};