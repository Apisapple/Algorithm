#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int main() {
    vector<pair<int ,int>> stuList;
    map<int, int> tempStu;
    map<int, int> listenStu;
    int studentCnt = 0, stuListSize = 0;

    cin >> studentCnt >> stuListSize;
    for(int i = 1; i <= stuListSize; i++) {
        int temp = 0;
        cin >> temp;
        tempStu[temp] = i;
    }

    for(auto it = tempStu.begin(); it != tempStu.end(); it++ ) {
        stuList.push_back(make_pair(it->second, it->first));
    }
    
    sort(stuList.begin(), stuList.end());

    for(int i = 0; i < min(studentCnt, int(stuList.size())); i++) {
        cout << stuList[i].second << endl;
    }
    return 0;
}