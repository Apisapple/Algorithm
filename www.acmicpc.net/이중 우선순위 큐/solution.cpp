#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int testCase = 0, calcCase = 0;
    cin >> testCase;
    while (testCase --)
    {
        priority_queue<pair <int, int>> max_heap;
        priority_queue<pair<int, int> , vector<pair <int, int>>, greater<pair<int,int>>> min_heap;
        cin >> calcCase;
        vector <bool> visited(calcCase, false);
        for(int i = 0; i < calcCase; i++) {
            char oper;
            int value;
            cin >> oper >> value;
            if(oper == 'I') {
                max_heap.push(make_pair(value, i));
                min_heap.push(make_pair(value, i));
                visited[i] = true;
            } else {
                if(value == 1) {
                    while (!max_heap.empty() && !visited[max_heap.top().second]) {
                        max_heap.pop();
                    }
                    if(!max_heap.empty()) {
                        visited[max_heap.top().second] = false;
                        max_heap.pop();
                    }
                } else if (value == -1) {
                    while(!min_heap.empty() && !visited[min_heap.top().second]) {
                        min_heap.pop();
                    }
                    if(!min_heap.empty()) {
                        visited[min_heap.top().second] = false;
                        min_heap.pop();
                    }
                }
            }
        }
        while(!max_heap.empty() && !visited[max_heap.top().second])
            max_heap.pop();
        while(!min_heap.empty() && !visited[min_heap.top().second])
            min_heap.pop();

        if(min_heap.empty() && max_heap.empty())
            cout << "EMPTY" << endl;
        else
            cout << max_heap.top().first << " " << min_heap.top().first << endl;
    }
    
    return 0;
}