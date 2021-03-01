#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define DIV_NUM 10007
#define MAX_N 1000

int main() {
    vector <vector<int>> DP(MAX_N + 1, vector<int>(10, 0));
    int N = 0;
    cin >> N;

    for(int i = 0; i < 10; i++) {
        DP[0][i] = 1;
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = j; k < 10; k++) {
                DP[i][k] += DP[i - 1][j];
                DP[i][k] %= DIV_NUM;
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < 10; i++) {
        answer += DP[N - 1][i];
    }

    cout << (answer % DIV_NUM) << endl;


    return 0;
}