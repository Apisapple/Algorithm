#include <string>
#include <math.h>

using namespace std;

/* 상의 종류를 확인하는 함수 */
int checkPrize(string &str, int index){
    int value = 1;
    if(index + 1 < str.size()){
        if(str[index + 1] == '*')
            value = 2;
        else if(str[index + 1] == '#')
            value = -1;
    }
    return value;
}
int solution(string dartResult) {
    int answer = 0;
    int score[3] = {0, 0, 0};
    int currentIndex = 0;

    for(int i = 0; i < dartResult.size(); i++){
        int exponent = 0;
        /* 보너스 확인 */
        switch(dartResult[i]){
            case 'S':
                exponent = 1;
                break;
            case 'D':
                exponent = 2;
                break;
            case 'T':
                exponent = 3;
                break;
        }
        if(exponent != 0){
            /* 얻은 점수 확인 */
            int point = stoi(dartResult.substr(0, i));
            /* 받은 상 여부 확인 */
            int multi = checkPrize(dartResult, i);
            if(multi == 1){
                /* 상을 받지 않았을 때 */
                dartResult = dartResult.substr(i + 1);
            }else{
                /* 상을 받았을 때 */
                dartResult = dartResult.substr(i + 2);
            }
            /* 스타상의 효과가 중복여부 체크 */
            if(multi == 2 && (currentIndex != 0)){
                score[currentIndex - 1] *= 2;
            }
            /* 점수 계산 */
            score[currentIndex] = pow(point, exponent) * multi;
            i = 0;
            currentIndex++;
        }
    }
    answer = score[0] + score[1] + score[2];
    return answer;
}