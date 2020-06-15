#include <string>
#include <vector>
#include <queue>

using namespace std;

/* 생각해야할 상황
1. 다리 위에 아무 트럭이 없을 때.
2. 다리 위에 트럭이 있으나 최대 무게를 넘지 않을 때
3. 다리 위에 트럭이 있고 최대 무게를 넘을 때
4. 트럭이 다리를 전부 지났을 때.
 */

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue <int> onBridge;
    int current_weight = 0;
    /* 모든 트럭을 순서대로 입력 */
    for(int i = 0; i < truck_weights.size(); i++){
        int truck_weight = truck_weights[i];
        while(1){
            /* 다리위에 트럭이 없는 경우 트럭을 queue에 입력 */
            if(onBridge.empty()){
                onBridge.push(truck_weight);
                current_weight += truck_weight;
                answer ++;
                break;
            }
            /* 제일 먼저 들어간 트럭이 끝 지점에 도달할 때  */
            else if(onBridge.size() == bridge_length){
                current_weight -= onBridge.front();
                onBridge.pop();
                answer++;
            }
            /* 트럭이 다리 위에 있을 때 */
            else{
                if(truck_weight + current_weight >= weight){
                    onBridge.push(0);
                    answer++;
                }else{
                    onBridge.push(truck_weight);
                    current_weight += truck_weight;
                    answer++;
                    break;
                }
            }
        }
    }
    return answer + bridge_length;
}