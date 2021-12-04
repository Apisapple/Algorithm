#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
#include <cstring>

using namespace std;

vector<int> scv_health(3, 0);
int dp[61][61][61];
void init() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}

int findResult(int x, int y, int z) {
    if (x < 0)
        return findResult(0, y, z);
    if (y < 0)
        return findResult(x, 0, z);
    if (z < 0)
        return findResult(x, y, 0);

    if (x == 0 && y == 0 && z == 0)
        return 0;

    int &result = dp[x][y][z];
    if (result != -1)
        return result;

    result = INT_MAX;
    result = min(result, findResult(x - 9, y - 3, z - 1) + 1);
    result = min(result, findResult(x - 9, y - 1, z - 3) + 1);
    result = min(result, findResult(x - 3, y - 9, z - 1) + 1);
    result = min(result, findResult(x - 3, y - 1, z - 9) + 1);
    result = min(result, findResult(x - 1, y - 9, z - 3) + 1);
    result = min(result, findResult(x - 1, y - 3, z - 9) + 1);

    return result;
}

int main() {
    init();

    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> scv_health[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << findResult(scv_health[0], scv_health[1], scv_health[2]) << '\n';
    return 0;
}