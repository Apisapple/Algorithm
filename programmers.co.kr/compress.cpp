#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> initData() {
    map<string, int> ret;

    for(int i = 1; i < 27; i++) {
        char a = 'A' + (i - 1);
        string temp = "";
        temp.push_back(a);
        ret[temp] = i;
    }

    return ret;
}

vector<int> solution(string msg) {
    vector<int> answer;

    map<string, int> dict = initData();

    int index = 27;
    while(msg.size() != 0) {
        for(int i = 1; i <= msg.size(); i++) {
            string sub = msg.substr(0, i);
            if(dict[sub] == 0) {
                dict[sub] = index;
                index ++;
                string preStr = msg.substr(0, i - 1);
                answer.push_back(dict[preStr]);
                msg = msg.substr(i - 1, msg.size() - preStr.size());
                break;
            } else {
                if(msg.size() == i) {
                    answer.push_back(dict[msg]);
                    msg = "";
                }
            }
        }
    }

    return answer;
}