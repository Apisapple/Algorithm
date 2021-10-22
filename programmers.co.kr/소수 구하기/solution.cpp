#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000

void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}
void solution(int n, int m) {

    vector<bool> numberList(m + 1, true);
    numberList[1] = false;
    for (int i = 2; i <= m; i++) {
        if (numberList[i]) {
            int numberStage = 2;
            while (i * numberStage <= m) {
                numberList[i * numberStage] = false;
                numberStage++;
            }
        }
    }

    for (int i = n; i <= m; i++) {
        if (numberList[i]) {
            cout << i << '\n';
        }
    }
}

int main(int argc, const char **argv) {
    initSolution();

    int n = 0, m = 0;
    cin >> n >> m;
    solution(n, m);

    return 0;
}