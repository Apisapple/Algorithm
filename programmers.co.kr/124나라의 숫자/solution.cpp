#include <string>
#include <vector>
#include <math.h>

using namespace std;

char NumberList[3] = {'1', '2', '4'};

string getValue(int n, string &answer)
{
    /*  quiotient : 목
    remainder : 나머지 */
    int remainder = n % 3;
    if(n < 0){
        return answer;
    }else{
        n /= 3;
        if(remainder == 0){
            n -= 1;
            answer = NumberList[2] + answer;
            return getValue(n, answer);
        }else{
            return getValue(n, answer);
        }
        
    }
}
string solution(int n)
{
    string answer = "";
    getValue(n, answer);
    return answer;
}