#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define MAX_SIZE 1000000

vector<long long> numberList(MAX_SIZE, 0);
vector<long long> answerList(MAX_SIZE, 0);
stack<long long> st;
void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}
int main() {
    initSolution();

    int numberArraySize = 0;
    cin >> numberArraySize;

    for (int i = 0; i < numberArraySize; i++)
        cin >> numberList[i];

    for (int i = numberArraySize - 1; 0 <= i; i--) {
        while(!st.empty() && st.top() <= numberList[i]) {
            st.pop();
        }

        if (st.empty())
            answerList[i] = -1;
        else 
            answerList[i] = st.top();

        st.push(numberList[i]);
    }

    for(int i = 0; i < numberArraySize; i++)
        cout << answerList[i] << ' ';

    return 0;
}