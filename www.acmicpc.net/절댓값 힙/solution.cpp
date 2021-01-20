#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    int N = 0;
    cin >> N;
    while(N --) {
        int number = 0;
        cin >> number;

        if (number == 0 ) {
            if(que.empty()){
                cout << "0" << endl;
            } else {
                int value = que.top().second;
                cout << value << endl;
                que.pop();
            }
        } else {
            que.push(make_pair(abs(number), number));
        }        
    }
    return 0;
}