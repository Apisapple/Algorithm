#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 1000000

vector<int> primeNumber(MAX_SIZE + 1, 0);
void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    for (int i = 0; i <= MAX_SIZE; i++)
        primeNumber[i] = i;

    for (int i = 2; i * i <= MAX_SIZE; i++) {
        if (primeNumber[i] == 0) {
            continue;
        }
        for (int j = i * i; j <= MAX_SIZE; j += i) {
            primeNumber[j] = 0;
        }
    }
}
int main() {
    initSolution();

    int testCase = 0;
    cin >> testCase;

    while (testCase--) {
        int number = 0, result = 0;
        cin >> number;

        for (int i = 2; i < number; i++) {
            if (primeNumber[number - i] + primeNumber[i] == number ) {
                result++;
                if (number - i == i) {
                    result++;
                }
            }
        }

        cout << result / 2 << endl;
    }

    return 0;
}