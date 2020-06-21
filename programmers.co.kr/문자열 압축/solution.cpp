#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> devideString(string s, int index){
    vector <string> temp;
    for(int i = 0 ; i < s.length(); i+= index){
        temp.push_back(s.substr(i, index));
    }
    return temp;
}

int solution(string s) {
    // 압축이 전혀 되지 않는 경우
    int answer = s.length();
    vector <string> token;
    for(int i = 1 ; i <= s.length() / 2; i++){
        token = devideString(s, i);
        string temp = "";
        string criteria = token[0];
        int count = 1;
        for(int j = 1; j < token.size(); j++){
            if(criteria == token[j]){
                count ++;
            }else{
                if(count != 1){
                    temp += to_string(count);
                }
                temp += criteria;
                criteria = token[j];
                count = 1;
            }
        }
        if(count != 1){
            temp += to_string(count);
        }
        temp += criteria;
        if(answer > temp.length())
            answer = temp.length();
    }

    return answer;
}