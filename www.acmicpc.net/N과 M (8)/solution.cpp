#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0;

void DFS(vector<int> &resultList, vector<int> &numberList, int index) {
    if(resultList.size() == m) {
        for(int i = 0; i < m; i++) {
            cout << resultList[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = index; i < n; i++) {
        resultList.push_back(numberList[i]);
        DFS(resultList, numberList, i);
        resultList.pop_back();
    }
}

int main() {
    cin >> n >> m;
    
    vector<int> resultList;
    vector<int> numberList(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> numberList[i];
    }
    sort(numberList.begin(), numberList.end());

    DFS(resultList, numberList, 0);

    return 0;
}