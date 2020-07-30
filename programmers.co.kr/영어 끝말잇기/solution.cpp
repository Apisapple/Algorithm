#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string, bool> sayList;
    vector<int> answer;
    int turn = 1;
    int person = 2;
    sayList.insert(make_pair(words[0], true));
    for(int i = 1; i < words.size(); i ++) {
        if(person > n) {
            person = 1;
            turn ++;
        }
        char last_alphabet = words[i - 1][words[i -1].size() - 1];
        bool check = sayList.find(words[i]) -> second; 
        
        if(last_alphabet != words[i][0]) {/* 단어가 틀린 경우 */
            answer.push_back(person);
            answer.push_back(turn);
            break;
        } else if(check != sayList.end() -> second) { /* 단어를 찾은 경우 */
            answer.push_back(person);
            answer.push_back(turn);
            break;
        } else { /* 정상적인 경우 */
            sayList.insert(make_pair(words[i], true));
        }

        person ++;
    }
    if(answer.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}