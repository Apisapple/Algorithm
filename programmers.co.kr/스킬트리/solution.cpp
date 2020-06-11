#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool checkSkill(string &skill, string &skill_tree){
    size_t prev = 0;
    bool notfound = false;
    for(int i = 0; i < skill.length(); i++){
        size_t current = skill_tree.find(skill[i]);
        /* 문자를 찾은 경우 */
        if(current != string::npos){
            if(notfound || current < prev){
                return false;
            }else{
                prev = current;
            }
        }
        /* 문자를 찾지 못한 경우 */
        else{
            notfound = true;        
        }
    }
    return true;
}
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0; i < skill_trees.size(); i++){
        if(checkSkill(skill, skill_trees[i])){
            answer ++;
        }
    }
    return answer;
}