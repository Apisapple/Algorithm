#include <algorithm>
#include <iostream>
#include <limits.h>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

vector<string> solution(vector<vector<int>> const line) {

    ll minX = LLONG_MAX, minY = LLONG_MAX;
    ll maxX = LLONG_MIN, maxY = LLONG_MIN;

    vector<pair<ll, ll>> points;

    for (int i = 0; i < line.size(); i++) {
        for (int j = i + 1; j < line.size(); j++) {
            ll A = line[i][0], B = line[i][1], E = line[i][2];
            ll C = line[j][0], D = line[j][1], F = line[j][2];

            ll numeratorX = B * F - E * D;
            ll numeratorY = E * C - A * F;
            ll modNumber = A * D - B * C;

            if (modNumber == 0)
                continue;
            if (numeratorX % modNumber || numeratorY % modNumber)
                continue;

            ll x = numeratorX / modNumber;
            ll y = numeratorY / modNumber;

            minX = min(minX, x);
            maxX = max(maxX, x);

            minY = min(minY, y);
            maxY = max(maxY, y);
            points.push_back({x, y});
        }
    }

    string rowValue = string(maxX - minX + 1, '.');
    vector<string> answer(maxY - minY + 1, rowValue);

    for (pair<ll, ll> point : points)
        answer[abs(point.second - maxY)][abs(point.first - minX)] = '*';

    return answer;
}
void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}
int main() {
    initSolution();

    vector<vector<int>> points = {{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}};
    vector<string> result = solution(points);

    for (string temp : result) {
        cout << temp << '\n';
    }

    return 0;
}