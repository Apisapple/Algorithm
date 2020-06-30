#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue <int> arr;
    int date = 0;
    int index = 0;
    /* 날짜가 정해진 k를 넘지 않을 때 까지 반복 */
    while(date < k){
        /* 받기로 한 날이 date보다 작은것들을 우선순위 큐에 저장하여
        그 값들 중 가장 크게 공급받는 것을 가져오도록 한다. */
        if(dates[index] <= date && index < dates.size()){
            arr.push(supplies[index]);
            index ++;
        }
        /* 저장 용량이 다 떨어지게 되면 가장 크게 받은 값을 저장한다. */
        if(stock == 0){
            stock += arr.top();
            arr.pop();
            answer++;
        }
        /* 하루가 지날 때 마다 1톤씩 소모한다. */
        date ++;
        stock --;
    }
    return answer;
}