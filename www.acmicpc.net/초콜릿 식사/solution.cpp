#include <algorithm>
#include <iostream>

using namespace std;

void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int getMinSize(int K) {
    int result = 1;

    while(result < K) {
        result = result << 1;
    }

    return result;
}

int getCntOne(int K) {
    int result = 0;
    while(K != 0) {
        K = K & (K - 1);
        result ++;
    }
    return result;
}

int main() {
    int K = 0, minSize = 0, cntOne = 0, tempCnt = 0, tempSize = 0, splitCnt = 0;

    initSolution();

    cin >> K;

    minSize = getMinSize(K);
    cntOne = getCntOne(K);
    tempSize = minSize;
    while(cntOne != tempCnt) {
        if((K & tempSize) != 0)
            tempCnt ++;

        splitCnt++;
        tempSize >>= 1;
    }

    cout << minSize << ' ' << splitCnt - 1 << '\n';
    return 0;
}