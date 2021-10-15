#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<char> right, left;
    string commandLine;
    int commandCnt;

    cin >> commandLine;
    for (int i = 0; i < commandLine.size(); i++) {
        left.push(commandLine[i]);
    }

    cin >> commandCnt;
    for (int i = 0; i < commandCnt; i++) {
        char command;
        cin >> command;

        switch (command) {
        case 'P':
            char temp;
            cin >> temp;
            left.push(temp);
            break;
        case 'L':
            if (left.empty())
                continue;
            right.push(left.top());
            left.pop();
            break;
        case 'B':
            if (left.empty())
                continue;
            left.pop();
            break;
        case 'D':
            if (right.empty())
                continue;
            left.push(right.top());
            right.pop();
            break;
        }
    }

    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }

    return 0;
}