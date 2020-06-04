#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] != ' '){
            char index = ('A' <= s[i] && s[i] <= 'Z') ? 'A' : 'a';
            s[i] = index + (s[i] + n - index) % 26;
        }
    }
    answer = s;
    return answer;
}