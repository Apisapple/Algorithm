#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack <char> laser;

    for(int i = 0 ; i < arrangement.size(); i++){
        if(arrangement[i] == '('){
            laser.push('(');
        }else{
            laser.pop();
            if(arrangement[i - 1] == '('){
                answer += laser.size();
            }else{
                answer++;
            }
        }
    }
    return answer;
}