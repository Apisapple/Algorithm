#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int Most , less = 0;
    priority_queue<int, vector<int>, greater<int>> List; 
    for(int i = 0 ; i < scoville.size(); i++){
        List.push(scoville[i]);
    }
    while(List.top() < K){
        if(List.size() == 1){
            return -1;
        }else{
            Most = List.top();
            List.pop();
            less = List.top();
            List.pop();
            List.push(Most + less * 2);
            answer++;
        }
    }

    return answer;
}