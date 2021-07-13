#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 20

vector<vector<int>> arr(MAX + 1, vector<int>(MAX + 1, 0));
vector<bool> visited(MAX + 1, false);
int N = 0, result = INT_MAX;

void init() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}
void getResult(int cnt, int current) {
    if(cnt == N / 2) {
        int tempA = 0, tempB = 0;

        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j< N; j++) {

                if(visited[i] && visited[j]) {
                    tempA += arr[i][j];
                    tempA += arr[j][i];
                } else if (!visited[i] && !visited[j]) {
                    tempB += arr[i][j];
                    tempB += arr[j][i];
                }
            }
        }
        result = min(result, abs(tempA - tempB));
        return;
    }
    for(int i = 0; i < N; i ++) {
        if(!visited[i] && i > current) {
            visited[i] = true;
            getResult(cnt + 1, i);
            visited[i] = false;
        }
    }
}
int main(int argc, char const *argv[]) {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    getResult(0, -1);

    cout << result << '\n'; 
    return 0;
}
