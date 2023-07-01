#include <iostream>
#include <string>
#include <vector>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

string solution(string p) {
    string answer = "";

    if (p.empty()) {
        return answer;
    }
    return answer;
}

int main() {

    string input_string;

    cin >> input_string;

    cout << solution(input_string) << '\n';

    return 0;
}