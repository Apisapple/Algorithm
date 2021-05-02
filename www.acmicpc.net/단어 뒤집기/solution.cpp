#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int testCase = 0;

    cin >> testCase;
    cin.ignore();
    for(int i = 0; i < testCase; i++) {
        stack<char> tempStack;
        string temp;

        getline(cin, temp);
        temp += '\n';

        for(char ch : temp) {
            if(ch == ' ' || ch == '\n') {
                while(!tempStack.empty()) {
                    cout << tempStack.top();
                    tempStack.pop();
                }
                cout << " ";
            } else {
                tempStack.push(ch);
            }
        }
    }
    return 0;
}