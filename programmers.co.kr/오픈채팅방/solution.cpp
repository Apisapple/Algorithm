#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string> solution(vector<string> records) {
    map <string, string> mapnickname;
    vector <string> users;
    vector <string> answer;
    string enter = "님이 들어왔습니다.";
    string leave = "님이 나갔습니다.";
    string behavior;
    string id;
    string nickname;
    for(string record : records) {
        stringstream token(record);
        token >> behavior;
        token >> id;
        token >> nickname;
        if(behavior == "Enter") {
            answer.push_back(enter);
            mapnickname[id] = nickname;
            users.push_back(id);
        } else if (behavior == "Leave") {
            answer.push_back(leave);
            users.push_back(id);
        } else {
            mapnickname[id] = nickname;
        }
        token.clear();
    }
    for(int i = 0; i < answer.size(); i ++) {
        answer[i] = mapnickname[users[i]] + answer[i];
    }
    return answer;
}