#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    queue <int> que;
    cin >> n >> k;

    for(int i = 0 ; i < n; i++) {
        que.push(i + 1);
    }

    cout << "<";
    while(true) {
        for(int i = 1; i < k; i++) {
            que.push(que.front());
            que.pop();
        }
        cout << que.front();
        que.pop();
        if(!que.empty()) {
            cout<<", ";
        } else {
            break;
        }
    }
    cout << ">";
    return 0;
}