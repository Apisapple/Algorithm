#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int size = s.size();
    int index = size / 2;
    int Odd = size % 2;
    switch (Odd)
    {
    //  짝수
    case 0:
        answer.push_back(s.at(index-1));
        answer.push_back(s.at(index ));   
        break;
    // 홀수
    default:
        answer.push_back(s.at(index));
        break;
    }
    return answer;
}