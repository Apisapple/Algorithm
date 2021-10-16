#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    string inputData = "";
    getline(cin, inputData);

    bool flagInParenthesis = false;
    stack<char> st;
    for (char character : inputData) {
        if (character == '<') {
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << '<';
            flagInParenthesis = true;
        } else if (character == '>') {
            cout << '>';
            flagInParenthesis = false;
        } else if (flagInParenthesis) {
            cout << character;
        } else if (character == ' ' || character == '\n') {
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << " ";
        } else {
            st.push(character);
        }
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}