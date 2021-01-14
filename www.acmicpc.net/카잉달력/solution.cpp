#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

#define MAX_M 10
#define MAX_N 12

int gcd(int x, int y) {
    while(y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }

    return x;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int test_case = 0, i = 0;
    cin >> test_case;

    while(test_case --) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int limit = lcm(m, n);

        for(i = x; i <= limit; i+= m) {
            int temp = 0;
            if(i % n == 0)
                temp = n;
            else
                temp = i % n;

            if(temp == y) {
                cout << i << endl;
                break;
            }

        }
        if(i > limit)
            cout << "-1" << endl;
    }
    return 0;
}