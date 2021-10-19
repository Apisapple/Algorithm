#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define MAX_SIZE 1000000

vector<int> numberList(MAX_SIZE, 0);
vector<int> visiteCount(MAX_SIZE, 0);
vector<int> answer(MAX_SIZE, 0);
stack<pair<int, int>> st;
void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int main() {
    initSolution();

    int listSize = 0;
    cin >> listSize;

    for (int i = 0; i < listSize; i++) {
        cin >> numberList[i];
        visiteCount[numberList[i]]++;
    }

    for (int i = listSize - 1; 0 <= i; i--) {

        while (!st.empty() && st.top().first <= visiteCount[numberList[i]]) {
            st.pop();
        }

        if (st.empty())
            answer[i] = -1;
        else
            answer[i] = st.top().second;

        st.push({visiteCount[numberList[i]], numberList[i]});
    }


    for(int i = 0; i < listSize; i++)
        cout << answer[i] << ' ';
    return 0;
}