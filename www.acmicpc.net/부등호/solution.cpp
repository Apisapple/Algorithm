#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> result;
vector<int> number;
vector<int> visited(10, false);
int numberList[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int k = 0;

bool checkData(vector<char> &oper) {
    for(int i = 0; i < k; i++) {
        if(oper[i] == '<') {
            if(number[i] > number[i + 1])
                return false;
        } else if(oper[i] == '>') {
            if(number[i] < number[i + 1])
                return false;
        }
    }
    return true;
}
void dfs(vector<char> &oper, int dept) {
    if(dept == k + 1) {
        if(checkData(oper)) {
            string temp = "";
            for(int i = 0; i< number.size(); i++) {
                temp += to_string(number[i]);
            }
            result.push_back(temp);
        }
    }

    for(int i = 0; i <= 9; i++) {
        if(!visited[i]) {
            visited[i] = true;
            number.push_back(numberList[i]);
            dfs(oper, dept + 1);
            number.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> k;
    vector<char> oper(k);
    for(int i = 0; i < k; i++) {
        cin >> oper[i];
    }

    dfs(oper, 0);

    sort(result.begin(), result.end());

    cout << result[result.size() - 1] << '\n';
    cout << result[0] << '\n';
    return 0;
}