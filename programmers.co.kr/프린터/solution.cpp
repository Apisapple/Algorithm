#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(int i, int j){
    return j < i;
}
int solution(vector<int> priorities, int location) {
    int answer = 0;
    int value =0;
    int size = priorities.size();
    vector <int> piorityArr;
    queue<pair <int, int>> documentList;    // <index, priority>
    for(int i = 0; i < size; i ++){
        documentList.push(make_pair(i, priorities[i]));
        piorityArr.push_back(priorities[i]);
    }
    
    /* 높은 우선 순위 찾기 */
    sort(piorityArr.begin(), piorityArr.end(), compare);

    while(!documentList.empty()){
        /* 큐에서 제일 앞에 들어있는 값 */
        int index = documentList.front().first;
        int piority = documentList.front().second;
        documentList.pop();
        /* 우선순위가 높은 것 먼저 */
        if(piorityArr[value] == piority){
            answer ++;
            value ++;
            /* 우선 순위를 만족하면서 찾고자 하는 문서일 때 */
            if(index == location)
                break;
        }else{
            /* 우선순위에 맞지 않는 경우 다시 큐에 입력 */
            documentList.push(make_pair(index,piority));
        }
    }

    return answer;
}