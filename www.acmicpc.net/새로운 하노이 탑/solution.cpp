#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct HanoiState {
    string A;
    string B;
    string C;
};
HanoiState initState;
set<pair<pair<string, string> , string>> checking;

void init() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
bool checkFinish(string A_state, string B_state, string C_state) {
    int A_size = A_state.size();
    int B_size = B_state.size();
    int C_size = C_state.size();

    if(A_size > 0) {
        for(int i = 0; i < A_size; i++) {
            if(A_state[i] != 'A')
                return false;
        }
    }
    if(B_size > 0) {
        for(int i = 0; i < B_size; i++) {
            if(B_state[i] != 'B')
                return false;
        }
    }
    if(C_size > 0) {
        for(int i = 0; i < C_size; i++) {
            if(C_state[i] != 'C')
                return false;
        }
    }
    return true;
}
string removeTop(string s) {
    string temp = "";
    for(int i = 0; i < s.size() - 1; i++) {
        temp += s[i];
    }
    return temp;
}

int findResult() {
    queue<pair<HanoiState, int>> que;
    que.push(make_pair(initState, 0));
    checking.insert(make_pair(make_pair(initState.A, initState.B), initState.C));

    while(!que.empty()) {
        string A_state = que.front().first.A;
        string B_state = que.front().first.B;
        string C_state = que.front().first.C;
        int cnt = que.front().second;
        que.pop();

        if(checkFinish(A_state, B_state, C_state)) {
            return cnt;
        }

        if(A_state.size() > 0) {
            string A_temp = removeTop(A_state);
            string B_temp = B_state + A_state[A_state.size() - 1];
            HanoiState temp = {A_temp, B_temp, C_state};

            if(checking.find(make_pair(make_pair(A_temp, B_temp), C_state)) == checking.end()) {
                que.push(make_pair(temp, cnt + 1));
                checking.insert(make_pair(make_pair(A_temp, B_temp), C_state));
            }

            string C_temp = C_state + A_state[A_state.size() - 1];
            temp = {A_temp, B_state, C_temp};

            if(checking.find(make_pair(make_pair(A_temp, B_state), C_temp)) == checking.end()) {
                que.push(make_pair(temp, cnt + 1));
                checking.insert(make_pair(make_pair(A_temp, B_state), C_temp));
            }
        }
        if(B_state.size() > 0) {
            string B_temp = removeTop(B_state);
            string A_temp = A_state + B_state[B_state.size() - 1];
            HanoiState temp = {A_temp, B_temp, C_state};

            if(checking.find(make_pair(make_pair(A_temp, B_temp), C_state)) == checking.end()) {
                que.push(make_pair(temp, cnt + 1));
                checking.insert(make_pair(make_pair(A_temp, B_temp), C_state));
            }

            string C_temp = C_state + B_state[B_state.size() - 1];
            temp = {A_state, B_temp, C_temp};

            if(checking.find(make_pair(make_pair(A_temp, B_state), C_temp)) == checking.end()) {
                que.push(make_pair(temp, cnt + 1));
                checking.insert(make_pair(make_pair(A_temp, B_state), C_temp));
            }
        }
        if(C_state.size() > 0) {
            string C_temp = removeTop(C_state);
            string A_temp = A_state + C_state[C_state.size() - 1];
            HanoiState temp = {A_temp, B_state, C_temp};

            if(checking.find(make_pair(make_pair(A_temp, B_state), C_temp)) == checking.end()) {
                que.push(make_pair(temp, cnt + 1));
                checking.insert(make_pair(make_pair(A_temp, B_state), C_temp));
            }

            string B_temp = B_state + C_state[C_state.size() - 1];
            temp = {A_state, B_temp, C_temp};

            if(checking.find(make_pair(make_pair(A_state, B_temp), C_temp)) == checking.end()) {
                que.push(make_pair(temp, cnt + 1));
                checking.insert(make_pair(make_pair(A_state, B_temp), C_temp));
            }
        }
    }
    return 0;
}

int main() {
    init();

    for(int i = 0; i < 3; i++) {
        int roundPlateCnt;
        cin >> roundPlateCnt;

        if(i == 0) {
            if(roundPlateCnt == 0) {
                initState.A = "";
            } else {
                cin >> initState.A;
            }
        } else if(i == 1) {
            if(roundPlateCnt == 0) {
                initState.B = "";
            } else {
                cin >> initState.B;
            }
        } else {
            if(roundPlateCnt == 0) {
                initState.C = "";
            } else {
                cin >> initState.C;
            }
        }
    }

    int result = findResult();
    cout << result << '\n';
    return 0;
}