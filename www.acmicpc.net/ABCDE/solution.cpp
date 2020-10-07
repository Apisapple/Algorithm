#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 2000

using namespace std;

// 전역변수
int people_cnt, relation_cnt;
int flag = 0;
vector <vector <int> > relation;
vector <bool> visited;;

void DFS(int dep, int index) {
    // 4번 이어지면 성공
    visited[index] = true;
    if(dep == 4) {
        flag = 1;
        return;
    }
    //  완전 탐색
    for(int i = 0; i <  relation[index].size(); i++) {
        int next = relation[index][i];
        if(!visited[next]) {
            DFS(dep + 1, next);
        }
    }
    visited[index] = false;
    return;
}

int main() {
    
    // 관계 입력
    cin >> people_cnt >> relation_cnt;
    visited.resize(people_cnt, false);
    relation.resize(people_cnt);
    for(int i = 0 ; i < relation_cnt; i++) {
        int first, second;
        cin >> first >> second;
        relation[first].push_back(second);
        relation[second].push_back(first);
    }
    for(int i = 0; i < relation.size(); i++) {
        DFS(0, i);
        fill(visited.begin(), visited.end(), false);
    }
  
    cout << flag << endl;
    return 0;
}