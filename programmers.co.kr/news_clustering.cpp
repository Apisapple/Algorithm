#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define VALUE 65536

int solution(string str1, string str2) {
    int answer = 0, max = 0, min = 0;
    vector<string> token1, token2, words;

    // convert to lower case;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    // token
    for (int i = 0; i < str1.size() - 1; i++) {
        string temp = str1.substr(i, 2);
        if ('a' <= temp[0] && temp[0] <= 'z' && 'a' <= temp[1] && temp[1] <= 'z') {
            token1.push_back(temp);
        }
    }

    for (int i = 0; i < str2.size() - 1; i++) {
        string temp = str2.substr(i, 2);
        if ('a' <= temp[0] && temp[0] <= 'z' && 'a' <= temp[1] && temp[1] <= 'z') {
            token2.push_back(temp);
        }
    }

    if (token1.empty() && token2.empty()) {
        return VALUE;
    }

    max = token1.size() + token2.size();

    if (token1.size() < token2.size()) {
        for (string token : token1) {
            auto iter = find(token2.begin(), token2.end(), token);

            if (iter != token2.end()) {
                token2.erase(iter);
                min++;
            }
        }
    } else {
        for (string token : token2) {
            auto iter = find(token1.begin(), token1.end(), token);

            if (iter != token1.end()) {
                token1.erase(iter);
                min++;
            }
        }
    }

    max = max - min;

    if (max == 0)
        return VALUE;

    answer = (double)min / (double)max * VALUE;

    return answer;
}