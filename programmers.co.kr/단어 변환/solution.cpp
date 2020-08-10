#include <string>
#include <vector>

using namespace std;

int answer = 50;

void dfs(string begin, string target, vector<string> words, vector<bool> &use_check, int count) {
    for(int i = 0; i < words.size(); i ++) {
        int cnt = 0;
        for(int j = 0; j < words[i].size(); j ++) {
            if(!use_check[i] && begin[j] != words[i][j])
                cnt ++;
        }
        if(cnt == 1) {
            if(target == words[i] && answer > count + 1) {
                answer = count + 1;
                return;
            }
            use_check[i] = true;
            dfs(words[i], target, words, use_check, count + 1);
            use_check[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> use_check(words.size(), false);
    dfs(begin, target, words, use_check, 0);
    if(answer == 50)
        return 0;
    return answer;
}