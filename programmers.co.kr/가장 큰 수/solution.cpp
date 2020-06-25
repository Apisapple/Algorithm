#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return (a + b > b + a) ? true : false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector <string> token;

    for(int i = 0 ; i < numbers.size(); i++){
        token.push_back(to_string(numbers[i]));
    }
    sort(token.begin(), token.end(), compare);

    for(int i = 0 ; i < token.size(); i++){
        answer += token[i];
    }
    if(answer[0] == '0')
        return "0";
    return answer;
}