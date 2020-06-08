#include <string>
#include <vector>

using namespace std;

string arr[2] = {"Even", "Odd"};

string solution(int num) {
    string answer = "";
    answer = (num % 2) == 0 ? arr[0] : arr[1];
    return answer;
}