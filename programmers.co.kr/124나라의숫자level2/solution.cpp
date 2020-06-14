#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";
    while(n > 0){
        int remainder = n % 3;
        switch (remainder)
        {
        case 0:
            answer.insert(0, "4");
            n = (n / 3) - 1;
            break;
        
        default:
            answer.insert(0, to_string(remainder));
            n /= 3;
            break;
        }
    }
    return answer;
}