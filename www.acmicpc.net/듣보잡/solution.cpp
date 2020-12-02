#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int noListen_count, noSee_count;
    cin >> noListen_count >> noSee_count;

    vector <string> noListen_list(noListen_count);
    vector <string> result_list;

    for(int i = 0; i < noListen_count; i++) {
        cin >> noListen_list[i];
    }
    sort(noListen_list.begin(), noListen_list.end());
    for(int i = 0; i < noSee_count; i++) {
        string temp;
        cin >> temp;
        if(binary_search(noListen_list.begin(), noListen_list.end(), temp)) {
            result_list.push_back(temp);
        }
    }
    sort(result_list.begin(), result_list.end());
    printf("%d", (int)result_list.size());
    for(int i = 0; i < result_list.size(); i++) {
        printf("%s\n", result_list[i].c_str());
    }
    return 0;
}