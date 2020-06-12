#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> emptyRate(progresses.size());
    int index = 0;
    int Date = 0;
    int Count  = 1;
    /* 각 작업의 마감까지 남은 시간 계산 */
    for(int i = 0; i < progresses.size(); i++){
        emptyRate[i] = ceil((100 - progresses[i]) / speeds[i]);
    }
    /* 제일 첫 기능의 마감 날짜를 저장 */
    Date = emptyRate[0];
    answer.push_back(1);
    /* 남은 기능의 마감 날짜를 비교 */
    for(int i = 1; i < emptyRate.size(); i++){
        /* 남은 날짜가 더 긴 날이 있는 경우, index값을 증가시킴으로써 다음 배포 기능 계산 */
        if(Date < emptyRate[i]){
            Date = emptyRate[i];
            answer.push_back(1);
            index ++;
        }else{
            answer[index] ++;
        }    
    }

    return answer;
}