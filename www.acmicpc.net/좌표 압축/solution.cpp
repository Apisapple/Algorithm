#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int number_size = 0;
    cin >> number_size;
    vector <int> number_list(number_size, 0);
    vector <int> idx_list;
    map <int, int> keyMapping;
    for(int i = 0; i < number_size; i++) {
        cin >> number_list[i];
    }
    idx_list = number_list;
    sort(idx_list.begin(), idx_list.end());

    for(int temp = 1, i = 0; i < idx_list.size(); i++) {
        if(keyMapping[idx_list[i]] == 0)
            keyMapping[idx_list[i]] = temp ++;
        else 
            continue;
    }

    for(int i = 0; i < number_list.size(); i++)
        cout << keyMapping[number_list[i]] - 1 << " ";
    return 0;
}