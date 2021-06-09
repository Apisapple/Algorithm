#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000
#define MIN 987654321


vector<int> maze(MAX, 0);
vector<int> dp(MAX, -1);
int n = 0;

int solution(int index) {
    if(n <= index)
        return MIN;
    if(index == n - 1)
        return dp[index] = 0;
    if(dp[index] != -1)
        return dp[index];
    
    dp[index] = MIN;

    for(int i = 1; i <= maze[index]; i++) {
        dp[index] = min(solution(index + i) + 1, dp[index]);
    }

    return dp[index];
}
void initSolve() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    initSolve();
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    int answer = solution(0);

    if(answer == MIN)
      cout << "-1" << '\n';
    else
      cout << answer <<'\n';

    return 0;
}