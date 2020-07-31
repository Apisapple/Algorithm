#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define VALUE 65536

bool checkAlphabet(char a) {
    if('a' <= a && a <= 'z')
        return true;
    else 
        return false;
}

vector<string> stringTokenization(string arr) {
    vector<string> temp;

     for(int i = 0; i < arr.length() - 1; i ++) {
        string tempString = arr.substr(i, 2);
        if(checkAlphabet(tempString[0]) && checkAlphabet(tempString[1])) {
            temp.push_back(tempString);
        }
    }

    return temp;
} 

// 자카드 유사도 = 교집합이 크기 / 합집합의 크기
int solution(string str1, string str2) {
    double answer = 0;
    vector<string> tokenA;
    vector<string> tokenB;
    /* 문자열을 전부 소문자로 변환 */
    std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    /* 문자열들을 토큰화하여 집합 생성 */
    tokenA = stringTokenization(str1);
    tokenB = stringTokenization(str2);
    /* 토큰이 생성되지 않을 경우 예외처리 */
    if(tokenA.size() == 0 && tokenB.size() == 0)
        return VALUE;

    if(tokenA.size() > tokenB.size()){
        swap(tokenA, tokenB);
    }
    int unionValue = max(tokenA.size(), tokenB.size());
    int interValue = 0;
  

    for(string token_A : tokenA) {
        vector<string>::iterator flag = find(tokenB.begin(), tokenB.end(), token_A);
        if(flag != tokenB.end()){
            tokenB.erase(flag);
            interValue++;
        } else {
            unionValue ++;
        }
    }
    answer = (double) interValue * VALUE / unionValue;
    return (int)answer;
}