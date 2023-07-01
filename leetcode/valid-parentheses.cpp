#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    bool isValid(string s) { 
      stack<char> temp; 

      for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
          temp.push(s[i]);
        } else {
          if(temp.size() == 0)
           return false;
          char top_value = temp.top();
          temp.pop();

          if((top_value == '(' && s[i] == ')') || (top_value == '{' && s[i] == '}') || (top_value == '[' && s[i] == ']')) {
            continue;
          } else {
            return false;
          }
        }
      }

      if(temp.size() == 0) {
        return true;
      }
      return false;
    }
};