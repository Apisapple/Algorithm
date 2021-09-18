#include <string>
#include <vector>

using namespace std;

string convertString(string & new_id) {
    for(int i = 0; i < new_id.size(); i++)
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') 
            new_id[i] = tolower(new_id[i]);
    
    return new_id;
}

string eraseIllegarChar(string & new_id) {
    for(int i = 0; i < new_id.length(); ) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
              || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            i++;
            continue;
        }
        
        new_id.erase(new_id.begin() + i);
    }
    return new_id;
}

string eraseDoublePoint(string & new_id) {
    for(int i = 1; i < new_id.length(); ){
        if (new_id[i] == '.' && new_id[i - 1] == '.'){
            new_id.erase(new_id.begin() + i);
            continue;
        }
        else i++;
    }
    return new_id;
}

string solution(string new_id) {
   
    // 모든 대문자를 대응되는 소문자로 치환
    new_id = convertString(new_id);
    
    // new_id에서 알파벳 소문자, 숫자, '-', '_', '.' 를 제외한 모든 문자 제거
    new_id = eraseIllegarChar(new_id);
    
    // '.'이 2번 이상 연속된 부분을 제거
    new_id = eraseDoublePoint(new_id);
    
    // new_id에서 '.'가 처음이나 끝에 위치한다면 제거
    if(new_id.front() == '.') 
        new_id.erase(new_id.begin());
    if(new_id.back() == '.') 
        new_id.erase(new_id.end() - 1);
    
    // 빈 문자열이라면 new_id에 'a'를 대입
    if(new_id.size() == 0)
        new_id = "a";
    
    // 만약 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거
    if(16 <= new_id.size()){
        while(new_id.length() != 15){
            new_id.erase(new_id.begin() + 15);
        }
    }
    // 제거 후 마침표가 '.'가 끝에 위치하면 제거
    if(new_id.back() == '.')
        new_id.erase(new_id.end() - 1);
    
    if(new_id.size() <= 2){
        while(new_id.size() != 3){
            new_id += new_id.back();
        }
    }
    
    return new_id;
}