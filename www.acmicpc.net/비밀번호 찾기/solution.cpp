#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define MAXSIZE 100000

int main() {
    int site_count = 0, find_count = 0;
    cin >> site_count >> find_count;
    map <string, string> dict_password;

    for(int i = 0; i < site_count; i++) {
        string site_address, password;
        cin >> site_address >> password;
        dict_password[site_address] = password;
    }

    for(int i = 0; i < find_count; i++) {
        string find_daddres;
        cin >> find_daddres;
        cout << dict_password[find_daddres] << endl;
    }
    return 0;
}