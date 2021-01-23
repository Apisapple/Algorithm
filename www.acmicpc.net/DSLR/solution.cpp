#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

// D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
// S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
// L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
// R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.

string searchCommand(int start, int target, string command) {
    queue<pair<int, string>> que;
    que.push(make_pair(start, command));
    while(!que.empty()) {
        int number = que.front().first;
        string temp_string = que.front().second;
        que.pop();
        if(number == target) {
            cout << temp_string << endl;
            return;
        }
        int temp_D = number * 2;
        int temp_S = number - 1;
        if(temp_D >= 10000) {
            que.push(make_pair(temp_D % 10000, command + "D"));
        } else {
            que.push(make_pair(temp_D, command + "D"));
        }

        if(temp_S == 0) {
            que.push(make_pair(9999, command + "S"));
        } else {
            que.push(make_pair(temp_S, command + "S"));
        }
    }
}

int main() {
    int testCase;
    cin >> testCase;
    while (testCase --) {
        int start, target;
        string command = "";
        cin >> start >> target;
        searchCommand(start, target, command);
    }
    return 0;
}