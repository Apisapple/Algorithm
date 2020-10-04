#include <iostream>
#include <vector>

#define MAX 2000

using namespace std;

// 전역변수
int people_cnt, relation_cnt;
bool flag = false;

int main() {

    // 초기화
    cin >> people_cnt >> relation_cnt;
    vector <bool> visited(people_cnt, false);
    vector <vector <int> > relation(people_cnt + 1, vector <int> (people_cnt + 1, 0));

    // 관계 입력
    for(int i = 0; i < relation_cnt; i++) {
        int start, end;
        cin >> start >> end;
        relation[start][end] = 1;
        relation[end][start] = 1;
    }



    return 0;
}