#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 11
#define MAX_NUM 100

vector<int> numberList(MAX_N, 0);
vector<int> operCnt(4, 0);
int N = 0, maxResult = -1e9, minResult = 1e9;

void findResult(int total, int index) {
    if(index == N) {
        maxResult = max(maxResult, total);
        minResult = min(minResult, total);

        return;
    }

    for(int i = 0; i < 4; i ++) {
        if(operCnt[i] > 0) {
            operCnt[i] --;

            switch (i)
            {
            case 0:
                findResult(total + numberList[index], index + 1);
                break;
            case 1:
                findResult(total - numberList[index], index + 1);
                break;
            case 2:
                findResult(total * numberList[index], index + 1);
                break;
            case 3:
                findResult(total / numberList[index], index + 1);
                break;
            }

            operCnt[i] ++;
        }
    }

    return;
}
int main() {
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> numberList[i];

    for(int i = 0; i < 4; i++)
        cin >> operCnt[i];

    findResult(numberList[0], 1);

    cout << maxResult << '\n' << minResult << endl;
    return 0;
}