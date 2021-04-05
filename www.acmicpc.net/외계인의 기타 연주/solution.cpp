#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

#define MAX_MELODY 500000
#define MAX_PLAT 300000

using namespace std;

int main() {
    int melody, plat, answer = 0;
    cin >> melody >> plat;

    stack <int> melodyList[7];

    for(int i = 0; i < melody; i++) {
        int line = 0, platNumber = 0;
        cin >> line >> platNumber;

        // 하나의 줄에 손가락이 아무것도 올라가 있지 않는 경우
        if(melodyList[line].empty()) {
            melodyList[line].push(platNumber);
            answer ++;
        } else {
            // 줄에 손이 올라가 있지만 크기보다 작은 것이 올라가 있는 경우
            if(platNumber > melodyList[line].top()) {
                melodyList[line].push(platNumber);
                answer ++;
            } else if (platNumber == melodyList[line].top()) { //이미 같은 음에 올라가 있는 경우
                continue;
            } else {
                // 소리가 나기 위해 더 높은 음에 있는 손가락을 땐다.
                while(!melodyList[line].empty() && platNumber < melodyList[line].top()) {
                    melodyList[line].pop();
                    answer ++;
                }
            }
            if(!melodyList[line].empty() && platNumber == melodyList[line].top())
                continue;
            else {
                melodyList[line].push(platNumber);
                answer ++;
            }
        }
    }
    cout << answer << endl;
    return 0;
}