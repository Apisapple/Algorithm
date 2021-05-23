#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 8
#define MAX_NUMBER 10000

vector<vector<int>> result;
vector<bool> visited;
void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void findAnswer(vector<int> &numberList, vector<int> &makeList, int size, int index) {
    if(makeList.size() == size) {
        bool flag = false;
        sort(makeList.begin(), makeList.end());
        for(int i = 0; i < result.size(); i++) {
            if(makeList == result[i])
                flag = true;
        }
        if(!flag)
            result.push_back(makeList);

        return;
    }

    for(int i = index ; i < numberList.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            makeList.push_back(numberList[i]);
            findAnswer(numberList, makeList, size, i + 1);
            makeList.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    int N = 0, M = 0;

    cin >> N >> M;
    vector<int> numberList(N, 0);
    vector<int> makeList;
    visited.resize(N, false);
    for(int i = 0; i < N; i++) {
        cin >> numberList[i];
    }
    
    sort(numberList.begin(), numberList.end());

    findAnswer(numberList, makeList, M, 0);
    
    sort(result.begin(), result.end());
    
    for(int i = 0 ; i < result.size(); i++) {
      for(int j = 0 ; j < result[i].size(); j ++) {
        cout << result[i][j] << ' ';
      }
      cout << '\n';
    }

    return 0;
}