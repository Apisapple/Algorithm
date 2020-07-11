#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector <int> numberList;
    size_t previous = 0;
    size_t current = s.find(' ');
    while (current != string::npos) {
        string temp = s.substr(previous, current - previous);
        numberList.push_back(stoi(temp));
        previous = current + 1;
        current = s.find(' ', previous);
    }
    numberList.push_back(stoi(s.substr(previous, current - previous)));
    sort(numberList.begin(), numberList.end());
    return to_string(numberList[0]) + ' ' + to_string(numberList[numberList.size() - 1]);
}