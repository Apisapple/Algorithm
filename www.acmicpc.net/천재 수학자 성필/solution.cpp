#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    string input;
    stack <int> temp;
    cin >> input;
    for(int i = 0; i < input.size(); i++) {
        if('0' <= input[i] && input[i] <= '9') {
            temp.push(input[i] - '0');
        }else{
            int firstNum = temp.top();
            temp.pop();
            int secondNum = temp.top();
            temp.pop();
            switch (input[i])
            {
            case '+':
                temp.push(firstNum + secondNum);
                break;
            case '-':
                temp.push(secondNum - firstNum);
                break;
            case '*':
                temp.push(firstNum * secondNum);
                break;
            case '/':
                temp.push(secondNum / firstNum);
                break;
            }
        }
    }
    while(!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }
    return 0;
}