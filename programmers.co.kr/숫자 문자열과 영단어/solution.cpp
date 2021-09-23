#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string answer_string = "";
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            answer_string += s[i];
        }
        else{
            if(s[i] == 'z'){
                answer_string += '0';
                i += 3;
            }
            else if(s[i] == 'o'){
                answer_string += '1';
                i += 2;
            }
            else if(s[i] == 't'){
                if(s.substr(i, 3) == "two"){
                    answer_string += '2';
                    i += 2;
                }
                else{
                    answer_string += '3';
                    i += 4;
                }
            }
            else if(s[i] == 'f'){
                if(s.substr(i, 4) == "four"){
                    answer_string += '4';
                }
                else{
                    answer_string += '5';
                }
                i += 3;
            }
            else if(s[i] == 's'){
                if(s.substr(i, 3) == "six"){
                    answer_string += '6';
                    i += 2;
                }
                else{
                    answer_string += '7';
                    i += 4;
                }
            }
            else if(s[i] == 'e'){
                answer_string += '8';
                i += 4;
            }
            else if(s[i] == 'n'){
                answer_string += '9';
                i += 3;
            }
        }
    }
    answer = stoi(answer_string);
    return answer;
}