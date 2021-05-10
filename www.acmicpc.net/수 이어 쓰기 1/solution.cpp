#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0, temp1 = 9, temp2 = 1;
    string num;
    cin >> num;
    
    if(num.size() == 1) {
        cout << stoi(num);
        return 0;
    }

    for(int i = 1; i < num.size(); i++) {
        answer += temp1 * i;
        temp1 *= 10;
        temp2 *= 10;
    }

    cout << answer + (stoi(num) - temp2 + 1) * num.size() << endl;

    return 0;
}