#include <algorithm>
#include <string>
using namespace std;
int solution(string s) {
    int answer=0;
    int size = s.size();

    if(size == 0 || size == 1) {
        return size;
    }

    while(size >= 2) {
        for(int i = 0; i <= s.size() - size; i++) {
            int left = i;
            int right = size + i - 1;
            bool flag = true;

            while(left < right) {
                if(s[left] != s[right]) {
                    flag = false;
                    break;
                }
                left ++;
                right --;
            }
            if(flag)
                return size;
        }
        size --;
    }
    return 1;
}