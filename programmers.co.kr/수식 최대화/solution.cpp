#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(string expression) {
    vector<long long> numbers;
    vector<char> operation;
    vector<char> operationPriority;
    vector<vector <char>> priority;

    string temp;
    long long answer = 0;
    int index = 0;

    /* 숫자와 연산자 구분 */
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '+' || expression[i] == '*' || expression[i] == '-') {
            temp = expression.substr(index, i);
            index = i + 1;
            numbers.push_back(stol(temp));
            operation.push_back(expression[i]);
        }
    }
    operationPriority.push_back('+');
    operationPriority.push_back('-');
    operationPriority.push_back('*');
    numbers.push_back(stol(expression.substr(index)));
    sort(operationPriority.begin(), operationPriority.end());
    
    /* 연산자 우선 쉰위 순열 구하기 */
    do {
        priority.push_back(operationPriority);
    } while(next_permutation(operationPriority.begin(), operationPriority.end()));


    /* 절댓값이 제일 큰 수 찾기 */
    for(auto operPriority : priority) {
        vector <long long> copyNumbers = numbers;
        vector <char> copyOperation = operation;
        for(char oper : operPriority) {
            for(int i = 0 ; i < copyOperation.size(); i ++){
                if(copyOperation[i] == oper) {
                    switch (oper)
                    {
                    case '*':
                        copyNumbers[i] *= copyNumbers[i + 1];
                        copyOperation.erase(copyOperation.begin() + i);
                        copyNumbers.erase(copyNumbers.begin() + i + 1);
                        i --;
                        break;
                    case '+':
                        copyNumbers[i] += copyNumbers[i + 1];
                        copyOperation.erase(copyOperation.begin() + i);
                        copyNumbers.erase(copyNumbers.begin() + i + 1);
                        i --;
                        break;
                    case '-':
                        copyNumbers[i] -= copyNumbers[i + 1];
                        copyOperation.erase(copyOperation.begin() + i);
                        copyNumbers.erase(copyNumbers.begin() + i + 1);
                        i --;
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        if(abs(copyNumbers[0]) > answer)
            answer = abs(copyNumbers[0]);
    }
    return answer;
}