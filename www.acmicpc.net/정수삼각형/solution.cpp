#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[3] = {-1, 0, 1};

int main() {
    int N;
    cin >> N;
    vector <vector <int>> pyramid(N, vector<int> (N));

    //  피라미드 입력
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            cin >> pyramid[i - 1][j];
        }
    }

    for(int i = 1; i < N; i ++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 ) {
                pyramid[i][j] = pyramid[i- 1][0] + pyramid[i][j];
            } else if (j == i) {
                pyramid[i][j] = pyramid[i][j] + pyramid[i - 1][j - 1];
            } else {
                pyramid[i][j] = max(pyramid[i][j] + pyramid[i - 1][j - 1], pyramid[i][j] + pyramid[i - 1][j]);
            }
        }
    }
    int result = pyramid[N - 1][0];
    for(int i = 1; i < N; i++)
        result = max(result, pyramid[N  - 1][i]);
    cout << result << endl;
    return 0;
}