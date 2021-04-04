#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 20

using namespace std;

int main() {
    int number_list_size = 0;
    cin >> number_list_size;

    int choice = 0;
    cin >> choice;

    vector<long long> number_list(MAX + 1, 1);
    vector<bool> check_list(MAX + 1, false);

    if(choice == 1) {
        long long find;
        cin >> find;

        for(int i = 0; i < number_list_size; i++) {
            for(int j = 1; j < number_list_size + 1; j++) {

            }
        }
    } else if(choice == 2) {

    }
    return 0;
}