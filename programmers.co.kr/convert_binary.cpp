#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

string convertBinary(int num) {
    string str = std::bitset<8>(num).to_string();
    return str;
}

string deleteZero(string &s) { s.erase(remove(s.begin(), s.end(), '0'), s.end()); }

vector<int> getAnswer(string s, int dept, int cnt) {
    vector<int> answer(2, 0);
    if (s.size() == 1) {
        answer[0] = dept;
        answer[1] = cnt;

        return answer;
    }

    int initSize = s.size();
    deleteZero(s);
    string deleteBinary = convertBinary(s.size());
    getAnswer(deleteBinary, dept + 1, cnt + (initSize - s.size()));

    return answer;
}

vector<int> solution(string s) {
    vector<int> answer;

    return answer;
}

int main() {
    string s = "";
    init();

    cin >> s;

    vector<int> answer = solution(s);

    cout << answer[0] << ' ' << answer[1] << '\n';
}