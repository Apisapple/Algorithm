#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int number_size = 0;
    cin >> number_size;
    vector <int> number(number_size, 0);

    for(int i = 0; i < number_size; i++) {
        cin >> number[i];
    }
    bool flag = true;
    
    if(prev_permutation(number.begin(), number.end())) {
        for(int i = 0; i < number_size; i++) {
            cout << number[i] << " ";
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }
}