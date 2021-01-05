#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int number = 0;
    int two_cnt = 0, five_cnt = 0;
    cin >> number;

    for(int i = 2; i <= number; i*=2) {
        two_cnt += (number / i);
    }

    for(int i = 5; i <= number; i*=5) {
        five_cnt += (number / i);
    }

    two_cnt < five_cnt ? cout << two_cnt << endl : cout << five_cnt << endl;

    return 0;
}