#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needle_size = needle.length();
        int haystack_size = haystack.length();
        int answer = -1;

        if (haystack_size < needle_size) {
            return answer;
        }

        for(int i = 0; i <= haystack_size - needle_size; ++i) {
            string temp = haystack.substr(i, needle_size);
            if (temp == needle) {
                answer = i;
                break;
            }
        }


        return answer;
    }
};