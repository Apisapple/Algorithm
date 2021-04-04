#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int answer = 0;
    string inputValue;
    stack <char> num;

    cin >> inputValue;

    for(int i = 0; i < inputValue.length(); i++) {
        if(inputValue[i] == '(') {
            num.push(inputValue[i]);
        } else {
            num.pop();
            if(inputValue[i - 1] == '(')
                answer += num.size();
            else
                answer++;
        }

    }
    cout << answer << endl;

    return 0;
}