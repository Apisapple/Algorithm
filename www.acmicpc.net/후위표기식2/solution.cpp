#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define MAX_SIZE 26

vector<double> alphabet(MAX_SIZE, 0);
void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int main() {
    initSolution();

    int N;
    cin >> N;

    string str = "";
    cin.ignore();
    getline(cin, str);

    for (int i = 0; i < N; i++)
        cin >> alphabet[i];

    stack<double> st;
    for (char calculator : str) {

        if (calculator == '*' || calculator == '/' || calculator == '+' || calculator == '-') {
            double firstNumber = st.top();
            st.pop();
            double secondNumber = st.top();
            st.pop();

            if (calculator == '+') {
                st.push(secondNumber + firstNumber);
            } else if (calculator == '-') {
                st.push(secondNumber - firstNumber);
            } else if (calculator == '*') {
                st.push(secondNumber * firstNumber);
            } else if (calculator == '/') {
                st.push(secondNumber / firstNumber);
            }
        } else {
            st.push(alphabet[calculator - 'A']);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << st.top() << '\n';

    return 0;
}