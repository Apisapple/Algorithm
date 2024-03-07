#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  vector<string> answer;
  int N;

public:
  vector<string> generateParenthesis(int n) {
    N = n;
    makeParenthesis(0, 0, 0, "");
    return answer;
  }

  void makeParenthesis(int dept, int leftUseCount, int flag, string parenthesis) {
    if (N * 2 == dept) {
      answer.push_back(parenthesis);
      return;
    }

    if (0 < flag) {
      makeParenthesis(dept + 1, leftUseCount, flag - 1, parenthesis + ')');
    }

    if (leftUseCount < N) {
      makeParenthesis(dept + 1, leftUseCount + 1, flag + 1, parenthesis + '(');
    }
  }
};