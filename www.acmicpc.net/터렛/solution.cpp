#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testCase = 0;
    int firstX, firstY, firstDistance;
    int secondX, secondY, secondDistance;
    int result = 0;
    cin >> testCase;

    for(int i = 0; i < testCase; i++) {
        cin >> firstX >> firstY >> firstDistance >> secondX >> secondY >> secondDistance;

        double d = sqrt(pow(secondX - firstX, 2) + pow(secondY - firstY, 2));
        int minus = abs(firstDistance - secondDistance);
        int plus = firstDistance + secondDistance;

        if(d == 0.0) {
            if(firstDistance == secondDistance) {
                result = -1;
            } else {
                result = 0;
            }
        } else {
            if(minus < d && d < plus) {
                result = 2;
            } else if (plus == d || minus == d) {
                result = 1;
            } else {
                result = 0;
            }
        }
        cout << result << '\n';
    }

    return 0;
}