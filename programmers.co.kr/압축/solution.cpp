#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    map<string, int> dictionary;
    vector<int> answer;
    int index = 0;
    /* dictionary 초기화 진행 */
    for(index = 1; index < 27; index ++){
        string temp = "";
        temp += 'A' + index - 1;
        dictionary.insert(make_pair(temp, index));
    }

    for(int i = 0; i < msg.size(); i ++) {
        string temp = "";
        temp += msg[i];
        int count = 0;
        int pivot = i;

        /* 사전의 내용을 찾은 경우 */
        while(dictionary.find(temp) != dictionary.end()) {
            count ++;
            pivot ++;
            temp += msg[pivot];
        }

        i += count - 1;
        dictionary.insert(make_pair(temp, index));
        temp.pop_back();
        answer.push_back(dictionary[temp]);
        index ++;
    }
    return answer;
}