#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}
int main() {
    initSolution();

    int testCnt = 0;
    cin >> testCnt;
    while (testCnt--) {
        stack <char> stackTemp;
        string temp;
        cin >> temp;

        for(char character : temp) {
            if(character == '(' || stackTemp.empty()) {
                stackTemp.push(character);
            } else if (character == ')') {
                if(stackTemp.top() == '(')
                    stackTemp.pop();
            }
        }

        if(stackTemp.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}