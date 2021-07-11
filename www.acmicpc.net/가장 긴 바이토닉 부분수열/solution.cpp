#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000

vector<int> numberList(MAX + 1, 0);
vector<int> upDp(MAX + 1, 0);
vector<int> downDp(MAX + 1, 0);
void init() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int main(int argc, char const *argv[]) {
    init();

    int listSize = 0, answer = 0;
    cin >> listSize;
    for(int i = 1; i <= listSize; i++)
        cin >> numberList[i];

    // Counting up DP
    for(int i = 1; i <= listSize; i++) {
        upDp[i] = 1;

        for(int j = 1; j <= i; j++) {
            if(numberList[j] < numberList[i] && upDp[i] < upDp[j] + 1 )
                upDp[i] = upDp[j] + 1;
        }
    }
    // Counting down DP
    for(int i = listSize; 1 <= i; i --) {
        downDp[i] = 1;

        for(int j = listSize; i <= j; j --) {
            if(numberList[j] < numberList[i] && downDp[i] < downDp[j] + 1 )
                downDp[i] = downDp[j] + 1;
        }
    }

    for(int i = 1; i <= listSize; i++) {
        answer = max(answer, upDp[i] + downDp[i] - 1);
    }
    cout << answer << '\n';
    return 0; 
}
