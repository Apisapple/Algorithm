#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 100000

int n = 0;
vector<int> numberList(MAX + 1, 0);
vector<int> leftSum(MAX + 1, 0);
vector<int> rightSum(MAX + 1, 0);
void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int getResult() {
    int result  = numberList[1];
    if(n == 1)
        return result;

    leftSum[1] = numberList[1];
    rightSum[n] = numberList[n];

    for(int i = 2; i <= n; i++) {
        leftSum[i] = max(numberList[i], leftSum[i - 1] + numberList[i]);
        result = max(result, leftSum[i]);
    }

    for(int i = n - 1; 1 <= i; i--) {
        rightSum[i] = max(numberList[i], rightSum[i + 1] + numberList[i]);
    }
    
    for(int i = 2; i <= n - 1; i ++)
        result = max(result, leftSum[i - 1] + rightSum[i + 1]);

    return result;
}

int main(int argc, char const *argv[]) {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> numberList[i];
    }
    cout << getResult() << '\n';
    return 0;
}
