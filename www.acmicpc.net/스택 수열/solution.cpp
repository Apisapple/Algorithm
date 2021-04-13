#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    vector<char> pm;
    vector<int> solveList;
    stack<int> numberList;
    int n = 0, temp = 0, index = 0;
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        solveList.push_back(temp);
    }
    for(int i = 1; i <= n; i++) {
        numberList.push(i);
        pm.push_back('+');
        while(!numberList.empty()) {
            if(solveList[index] == numberList.top()) {
                numberList.pop();
                pm.push_back('-');
                index ++;
            } else {
                break;
            }
        }
    }

    if(numberList.empty()) {
        for(int i = 0; i < pm.size(); i++) {
            cout << pm[i] << "\n";
        }
    }else {
        cout << "NO\n";
    }
    return 0;
}