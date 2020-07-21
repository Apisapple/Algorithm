#include <stack>
#include <string>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack <char> temp;
    for(int i = 0; i < s.length(); i ++) {
        if(temp.empty() || s[i] != temp.top())
            temp.push(s[i]);
        else
            temp.pop();
    }
    if(temp.empty())
        answer = 1;
    return answer;
}