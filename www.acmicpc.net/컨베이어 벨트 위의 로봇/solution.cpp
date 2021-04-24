#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_LENGTH 100
#define MAX 1000

struct BeltInfo{
    int leftCnt;
    bool onRobot;
};

vector<BeltInfo> belt(MAX_LENGTH * 2 + 1);

// 회전 시키는 함수
void RotateBelt(int beltSize) {
    BeltInfo temp = belt[beltSize * 2 - 1];
    for(int i = beltSize * 2 - 1; 0 <= i; i--) {
        belt[i] = belt[i - 1];
    }
    belt[0] = temp;
    if(belt[beltSize - 1].onRobot) {
        belt[beltSize - 1].onRobot = false;
    }
}
void MoveBelt(int beltSize) {
    for(int i = beltSize - 2; 0 <= i; i --) {
        if(belt[i].onRobot) {
            int next = i + 1;
            if(!belt[next].onRobot && belt[next].leftCnt != 0) {
                if(next == beltSize - 1) {
                    belt[i].onRobot = false;
                    belt[next].leftCnt --;
                } else {
                    belt[i].onRobot = false;
                    belt[next].onRobot = true;
                    belt[next].leftCnt --;
                }
            }
        }
    }
}
void PushOnBelt() {
    if(!belt[0].onRobot && belt[0].leftCnt != 0) {
        belt[0].onRobot = true;
        belt[0].leftCnt --;
    }
}
int CheckCnt(int beltSize) {
    int result = 0;
    for(int i = 0; i < beltSize * 2; i ++) {
        if(belt[i].leftCnt == 0) {
            result ++;
        }
    }
    return result;
}
int main() {
    int beltLength, brokenCnt, result = 1;
    cin >> beltLength >> brokenCnt;

    for(int i = 0; i < beltLength * 2; i++) {
        cin >> belt[i].leftCnt;
        belt[i].onRobot = false;
    }

    while(1) {
        RotateBelt(beltLength);
        MoveBelt(beltLength);
        PushOnBelt();
        if(CheckCnt(beltLength) >= brokenCnt) {
            cout << result << endl;
            return 0;
        }
        result ++;
    }

    return 0;
}