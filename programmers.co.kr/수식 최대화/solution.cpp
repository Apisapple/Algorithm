#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(string expression) {
    vector <int> numbers;
    vector <char> operaion;
    string temp;
    long long answer = 0;
    int index = 0;

    /* 숫자와 연산자 구분 */
    for(int i = 0; i < expression.length(); i ++) {
        if(expression[i] == '+' || expression[i] == '*' || expression[i] == '-') {
            temp = expression.substr(index, i );
            index = i + 1;
            numbers.push_back(stoi(temp));
            operaion.push_back(expression[i]);
        }
    }
    numbers.push_back(stoi(expression.substr(index)));
    return answer;
}