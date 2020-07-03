#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(pair<int, vector<int>> a, pair<int, vector<int>> b){
    if(a.first <= b.first)
        return true;
    else
        return false;
}
bool checkValue(vector<int> &temp, int value){
    for(int i = 0 ; i < temp.size(); i++){
        if(temp[i] == value)
            return false;
    }
    return true;
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<int> token;
    vector<int> temp;
    vector< pair<int,vector<int>> > arr;
    int number = 0;
    /* 각 원소의 숫자들을 찾고 크기와 같이 벡터에 저장 */
    for(int i = 0 ; i < s.size() - 1; i ++){
        if(s[i] == '{')
            continue;
        else if(s[i] == '}'){
            token.push_back(number);
            arr.push_back(make_pair(token.size(), token));
            number = 0;
            token.clear();
        }else if(s[i] == ','){
            if(s[i - 1] == '}')
                continue;
            token.push_back(number);
            number = 0;                      
        }else{ /* 숫자인 경우 */
            number *= 10;
            number = number + (s[i] - '0');
        }
    }
    /* 각 크기를 기준으로 정렬 */
    sort(arr.begin(), arr.end(), compare);

    /* 중복을 체크하고 중복되는 값이 없는 경우 통과 */
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].second.size(); j++){
            if(checkValue(temp, arr[i].second[j])){
                temp.push_back(arr[i].second[j]);
                answer.push_back(arr[i].second[j]);
            }
        }
    }
    return answer;
}