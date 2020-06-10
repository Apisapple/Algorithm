#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 
    목표== 실패율이 높은 스테이지 부터 내림차순으로 
           스테이지의 번호가 담겨있는 배열을 반환
 */
bool compareFailrate(pair<double, int> &A, pair<double, int> &B){
    bool Flag = false;
    if(A.first > B.first){
        Flag = true;
    }else if(A.first == B.first){
        if(A.second < B.second){
            Flag = true;
        }
    }
    return Flag;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> failrates;
    int totaluser = stages.size();
    int index = 0;
    // 각 유저의 스테이지  도전을 확인하기 위한 정렬
    sort(stages.begin(), stages.end());

    for(int i = 1; i <= N; i++){
        // 만약 스테이지에 도달한 유저가 없는 경우
        if(totaluser == 0){
            failrates.push_back(make_pair(0, i));
            continue;
        }

        // 클리어하지 못한 플레이어 수 확인
        int cntfail = 0;
        while(stages[index] == i){
            index ++;
            cntfail ++;
        }

        // 실패율 계산 및 입력
        double failrate = (double)cntfail / totaluser;
        failrates.push_back(make_pair(failrate , i));
        // 전체 유저에서 클리어하지 못한 플레이어 수 제외
        totaluser -= cntfail;
    }
    // 정렬
    sort(failrates.begin(), failrates.end(), compareFailrate);
    // 정답입력
    for(int i = 0; i < N; i++){
        answer.push_back(failrates[i].second);
    }
    return answer;
}