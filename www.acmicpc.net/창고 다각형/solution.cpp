#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define MAX_PILLAR 1000

bool compare(pair <int, int> first, pair<int, int> second) {
    return first.first < second.first;
}

int main() {
    vector<pair<int, int>> pillarInfo;
    int pillarCnt = 0, maxPillar = 0, maxIndex = 0;
    int answer = 0;
    cin >> pillarCnt;

    for(int i = 0; i < pillarCnt; i++) {
        int index = 0, height = 0;
        cin >> index >> height;
        if(height > maxPillar) {
            maxIndex = index;
            maxPillar = height;
        }
        pillarInfo.push_back(make_pair(index, height));
    }

    sort(pillarInfo.begin(), pillarInfo.end(), compare);
    stack<pair<int, int>> leftStack;
    stack<pair<int, int>> rightStack;

    for(int i = 0; i < pillarCnt; i++) {
        if(pillarInfo[i].first == maxIndex) {
            if(!leftStack.empty()) {
                int area = leftStack.top().second * (pillarInfo[i].first - leftStack.top().first);
                answer += area;
            }
            break;
        }
        if(leftStack.empty()) {
            leftStack.push(pillarInfo[i]);
        } else if (leftStack.top().second < pillarInfo[i].second) {
            int area = leftStack.top().second * (pillarInfo[i].first - leftStack.top().first);
            answer += area;
            leftStack.push(pillarInfo[i]);
        }
    }

    for(int i = pillarCnt - 1; 0 <= i; i--) {
        if(pillarInfo[i].first == maxIndex) {
            if(!rightStack.empty()) {
                int area = rightStack.top().second * abs(pillarInfo[i].first - rightStack.top().first);
                answer += area;
            }
            break;
        }
        if(rightStack.empty()) {
            rightStack.push(pillarInfo[i]);
        } else if (rightStack.top().second < pillarInfo[i].second) {
            int area = rightStack.top().second * abs(rightStack.top().first - pillarInfo[i].first);
            answer += area;
            rightStack.push(pillarInfo[i]);
        }
    }

    cout << answer + maxPillar << endl;
    return 0;
}