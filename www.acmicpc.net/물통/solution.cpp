#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 201

int A = 0, B = 0, C = 0;
vector<vector<bool>> check_value(MAX, vector<bool>(MAX, false));
vector<int> possible_case;

void BFS() {
    queue<pair<pair<int, int>, int>> que;
    que.push(make_pair(make_pair(0, 0), C));

    while(!que.empty()) {
        int cur_A = que.front().first.first;
        int cur_B = que.front().first.second;
        int cur_C = que.front().second;
        que.pop();

        if(check_value[cur_A][cur_B])
            continue;
        check_value[cur_A][cur_B] = true;

        if(cur_A == 0)
            possible_case.push_back(cur_C);

        // A -> B
        if(cur_A + cur_B > B)
            que.push(make_pair(make_pair(cur_A + cur_B - B, B), cur_C));
        else
            que.push(make_pair(make_pair(0, cur_A + cur_B), cur_C));
        // A -> C
        if(cur_A + cur_C > C)
            que.push(make_pair(make_pair(cur_A + cur_C - C , cur_B), C));
        else
            que.push(make_pair(make_pair(0, cur_B), cur_A + cur_C));
        // B -> A
        if(cur_B + cur_A > A)
            que.push(make_pair(make_pair(A, cur_A + cur_B - A), cur_C));
        else
            que.push(make_pair(make_pair(cur_B + cur_A, 0), cur_C));
        // B -> C
        if(cur_B + cur_C > C)
            que.push(make_pair(make_pair(cur_A, cur_B + cur_C - C), C));
        else
            que.push(make_pair(make_pair(cur_A, 0), cur_B + cur_C));
        // C -> A
        if(cur_C + cur_A > A)
            que.push(make_pair(make_pair(A, cur_B), cur_C + cur_A - A));
        else
            que.push(make_pair(make_pair(cur_A + cur_C, cur_B), 0));
        // C -> B
        if(cur_B + cur_C > B)
            que.push(make_pair(make_pair(cur_A, B), cur_B + cur_C - B));
        else
            que.push(make_pair(make_pair(cur_A, cur_B + cur_C), 0));
    }
}

int main() {

    cin >> A >> B >> C;
    BFS();

    sort(possible_case.begin(), possible_case.end());
    for(int i = 0; i < possible_case.size(); i++)
      cout << possible_case[i] << " ";
    return 0;
}