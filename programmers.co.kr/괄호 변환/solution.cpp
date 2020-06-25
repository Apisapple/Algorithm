#include <string>
#include <vector>
#include <stack>

using namespace std;

bool checkCorrect(string arr){
    int temp = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == '('){
            temp ++;
        }else{
            temp--;
            if(temp < 0)
                return false;
        }
    }
    return true;
}
string MakeCorrectString(string p){
    string u = "";
    string v = "";
    int left = 0, right = 0;
    if (p == "")
        return p;
    /* 문자열을 u와 v로 나누기 */
    for(int i = 0; i < p.size(); i++){
        if(p[i] == '(')
            left ++;
        else if(p[i] == ')')
            right ++;

        if(left == right){
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if(checkCorrect(u)){
        /* 3단계 */
        return u + MakeCorrectString(v);
    }else{
        /* 4단계 */
        string temp = "(";  // 4 - 1
        temp += MakeCorrectString(v) + ")"; // 4 - 2, 4 - 3
        u = u.substr(1, u.size() - 2); // 4- 4
        for(int j = 0; j < u.size(); j ++){
            if(u[j] == '(')
                temp += ')';
            else if(u[j] == ')')
                temp += '(';   
        }
        return temp;
    }

}
string solution(string p) {
    string answer = "";
    if(checkCorrect(p))
        return p;
    answer = MakeCorrectString(p);
    return answer;
}