#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

vector<string> all_case;

bool compare(string str1, string str2) {
    return str1.size() < str2.size() ? true : false;
}

/* 모든 경우의 수 구하기 */
void calAllCase(int index, string temp, int column_size) {
    for(int i = index; i < column_size; i++) {
        temp += to_string(i);
        all_case.push_back(temp);
        calAllCase(i + 1, temp, column_size);
        temp.pop_back();
    }
}

/* 후보키 판단 함수 */
bool checkCandidate(vector<vector<string>> relation, string tuple, int relation_height) {
    map<string , bool> check_unique;
    for(int i = 0; i < relation_height; i++) {
        string temp;
        for(int j = 0; j < tuple.size(); j++) {
            int column = tuple[j] - '0';
            temp += relation[i][column];
        }
        if(check_unique.find(temp) != check_unique.end())
            return false;
        else {
            check_unique.insert(make_pair(temp, true));
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int relation_height = relation.size();
    int relation_width = relation[0].size();

    /* 
    생각하는 과정 
    1. 모든 경우의 수를 구한다.
    2. 각각의 경우의 수가 후보키를 만족하는 지 확인한다.
        2 - 1. 후보키의 기준을 만족하는 경우 answer의 값을 추가한다.
        2 - 2. 조건을 만족하지 못하는 경우 넘어간다.
    */

    /* 모든 경우의 수 구하기 */
    calAllCase(0, "", relation_width);
    sort(all_case.begin(), all_case.end(), compare);
    for(int i = 0; i < all_case.size(); i ++) {
        if(checkCandidate(relation, all_case[i], relation_height)) {
            string temp = all_case[i];
            for(int j = all_case.size() - 1; j >= i; j--) {
                bool flag = true;
                for(char k : temp) {
                    if(all_case[j].find(k) == string::npos) {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    all_case.erase(all_case.begin() + j);
            }
            i --;
            answer ++;
        }
    }
    return answer;
}