#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    int index = 0;
    for(int i = 0; i < seoul.size(); i++){
        if(seoul[i] == "Kim"){
            index = i;
            break;
        }
    }
    answer += to_string(index);
    answer += "에 있다";
    return answer;
}