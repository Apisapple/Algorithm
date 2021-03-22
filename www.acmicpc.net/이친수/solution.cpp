#include <iostream>

using namespace std;

#define MAX 91

int number_size = 0;
long long number[MAX][2] = { {0, 0}, {0, 1}, {1, 0} };

int main() {
    cin >> number_size;

    for(int i = 2; i <= number_size; i++) {
        number[i][0] = number[i - 1][0] + number[i - 1][1];
        number[i][1] = number[i - 1][0];
    }
    cout << number[number_size][0] + number[number_size][1] << endl;
    return 0;
}