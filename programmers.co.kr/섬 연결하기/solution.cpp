#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parents_node;

int findParents(int value) {
    if(value == parents_node[value])
        return value;
    else
        return findParents(parents_node[value]);
}

bool compare(vector<int>arr1, vector<int>arr2) {
    if(arr1[2] < arr2[2])
        return true;
    else 
        return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    // 처음에는 자기 자신을 부모로 초기화
    for(int i = 0; i < n; i++) {
        parents_node.push_back(i);
    }
    // 가중치 기준으로 오름차순 정렬
    sort(costs.begin(), costs.end(), compare);
    
    for(int i = 0; i < costs.size(); i ++) {
        int start = findParents(costs[i][0]);
        int end = findParents(costs[i][1]);
        int cost = costs[i][2];

        if(start != end) {
            parents_node[start] = end;
            answer += cost;
        }
    }
    return answer;
}