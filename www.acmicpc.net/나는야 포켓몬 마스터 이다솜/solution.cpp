#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>

using namespace std;

map<string, int> dict_name;
vector <string> dict_number;

int main() {
    int poketmon_count, problem_count;
    string name;
    cin >> poketmon_count >> problem_count;

    for(int i = 1 ; i <= poketmon_count; i++) {
        cin >> name;
        dict_name.insert(make_pair(name, i));
        dict_number.push_back(name);
    }

    for(int i = 0; i < problem_count; i++) {
        string str;
        cin >> str;
        if(isdigit(str[0])) {
            cout << dict_number[stoi(str) - 1] << endl;
        } else {
            cout << dict_name[str] << endl;
        }
    }
    return 0;
}