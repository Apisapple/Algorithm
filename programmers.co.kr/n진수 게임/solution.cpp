#include <string>
#include <vector>

using namespace std;

string changeNumber(int number, int n) {
    string result = "";
    string code = "0123456789ABCDEF";
    while (number / n != 0) {
        result = code[number % n] + result;
        number /= n;
    }
    result = code[number % n] + result;
    return result;
}
/* n = 진법 | t = 미리 구할 숫자의 갯수 | m = 참가 인원 | p = 튜브의 순서 */
string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = "";

    /* 최대 t * n까지의 진법 번환 */
    for(int i = 0; i < t * m; i++) {
        temp += changeNumber(i, n);
    }
    int count = 0;
    for(int i = p - 1; i < temp.size(); i += m) {
        answer += temp[i];
        if(count + 1 == t)
            break;
        count ++;
    }
    return answer;
}