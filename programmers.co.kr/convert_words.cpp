#include <algorithm>
#include <limits.h>
#include <string>
#include <vector>

using namespace std;

vector<bool> isVisit(false, 50);
int answer = INT_MAX;

bool isDiffrent(string a, string b) {
    int cnt = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
    }

    if (cnt == 1)
        return true;

    return false;
}

void DFS(int cnt, string begin, string target, vector<string> words) {
    if(answer <= cnt)
        return;

    if (begin == target) {
        answer = min(answer, cnt);
        return;
    }

    for(int i = 0; i < words.size(); i++) {
        if(isDiffrent(begin, words[i]) && !isVisit[i]) {
            isVisit[i] = true;
            DFS(cnt + 1, words[i], target, words);
            isVisit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {

    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }

    DFS(0, bigin, target, words);

    return answer;
}