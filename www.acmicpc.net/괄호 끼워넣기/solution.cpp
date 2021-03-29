#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack <char> temp;
    string input;
    int index = 0, result = 0;
    cin >> input;
    for(int i = 0; i < input.size(); i++) {
        if(temp.empty()) {
            if(input[i] == '(') {
                temp.push(input[i]);
            } else {
                result ++;
            }
        } else {
            if(input[i] == ')' && temp.top() == '(') {
                temp.pop();
            } else {
                temp.push(input[i]);
            }
        }
    }

    if(!temp.empty())
        result += temp.size();

    cout << result << endl;
    return 0;
}