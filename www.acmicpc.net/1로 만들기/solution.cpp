#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1000000

vector <int> number_list(MAX + 1);

int main() {
    int number;
    number_list[1] = 0;
    number_list[2] = 1;
    number_list[3] = 1;
    cin >> number;
    
    for(int i = 4; i <= number; i++) {
        number_list[i] = number_list[i - 1] + 1;
        if(i % 2 == 0) {
            number_list[i] = min(number_list[i], number_list[i / 2] + 1);
        }
        if(i % 3 == 0) {
            number_list[i] = min(number_list[i], number_list[i / 3] + 1);
        }
    }
    cout << number_list[number] << endl;

    return 0;
}