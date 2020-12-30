#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define MAX 100

using namespace std;

vector<vector<string>> board(MAX + 1, vector<string>(MAX + 1, ""));

string addCombination(string first, string second) {
    int sum = 0;
    string result = "";

    while (!first.empty() || !second.empty() || sum) 
    {
        if(!first.empty()) {
            sum += first.back() - '0';
            first.pop_back();
        }
        if(!second.empty()) {
            sum += second.back() - '0';
            second.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string combination(int N, int M) {
    if(N == M || M == 0)
        return "1";

    string result = board[N][M];
    if(result != "")
        return result;

    result = addCombination(combination(N -1, M -1), combination(N -1, M));
    return result;
}

int main() {
    int N, M;

    cin >> N >> M;
    return 0;
}