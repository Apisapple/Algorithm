#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 각 선택 유형에 따라 점수를 부여
// 점수가 동일할 경우, 사전순으로 선택

map<char, int> initData() {
    map<char, int> data;
    data['A'] = 0;
    data['N'] = 0;
    data['C'] = 0;
    data['F'] = 0;
    data['M'] = 0;
    data['J'] = 0;
    data['R'] = 0;
    data['T'] = 0;
    return data;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "RCJA";
    int choice_size = choices.size();
    map<char, int> data = initData();
    for(int i = 0; i < choice_size; i++) {
        if(choices[i] < 4) {
            data[survey[i][0]] += (4 - choices[i]);
        } else if (4 < choices[i]) {
            data[survey[i][1]] += (choices[i] - 4);
        }
    }
    
    if(data['R'] < data['T']) {
        answer[0] = 'T';
    }
    if(data['C'] < data['F']) {
        answer[1] = 'F';
    }
    if(data['J'] < data['M']) {
        answer[2] = 'M';
    }
    if(data['A'] < data['N']) {
        answer[3] = 'N';
    }
    
    
    return answer;
}