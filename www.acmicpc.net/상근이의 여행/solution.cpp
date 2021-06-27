#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define TEST_MAX 100
#define COUNTRY_MAX 1000
#define FLIGHT_MAX 10000


int test = 0, countryCnt = 0, flightCnt = 0, result = 0;
void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    return;
}

int main(int argc, const char** argv) {
    initSolution();
    cin >> test;

    while(test --) {
        cin >> countryCnt >> flightCnt;
        vector<vector<int>> graph(countryCnt + 1, vector<int>(countryCnt + 1, 0));
        vector<bool> visited(countryCnt + 1, false);
        result = INT_MAX;
        for(int i = 0; i < flightCnt; i++) {
            int start = 0, end = 0;
            cin >> start >> end;
            graph[start][end] = graph[end][start] = 1;
        }

        cout << countryCnt - 1 << '\n';
    }
    return 0;
}