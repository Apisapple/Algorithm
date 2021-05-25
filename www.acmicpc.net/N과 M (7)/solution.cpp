#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM 10000
#define MAX 7

int n = 0, m = 0;

void DFS(vector<int> &numberList, vector<int> &resultList) {
    if(resultList.size() == m) {
        for(int i = 0; i < m; i++) {
            cout << resultList[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        resultList.push_back(numberList[i]);
        DFS(numberList, resultList);
        resultList.pop_back();
    }
}

int main() {
    cin >> n >> m;

    vector<int> numberList(n, 0);
    vector<int> resultList;
    for(int i = 0; i < n; i++) {
        cin >> numberList[i];
    }
    
    sort(numberList.begin(), numberList.end());

    DFS(numberList, resultList);

    return 0;
}