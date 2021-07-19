#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 50

int n1 = 0, n2 = 0, temp = 0;
struct information{
    int dir;
    char antInfo;
};
struct information ans[27];

void initSoltuion() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int main(int argc, char const *argv[]) {
    char antInfo;
    initSoltuion();

    cin >> n1 >> n2;

    for(int i = 0; i < n1; i++) {
        cin >> antInfo;
        ans[n1 - 1 - i] = {0, antInfo};
    }

    for(int i = n1; i < n1 + n2; i++) {
        cin >> antInfo;
        ans[i] = {1, antInfo};
    }

    cin >> temp;
    for(int i = 0; i < temp; i++) {
        for(int j = 0; j < n1 + n2 - 1; j++) {
            if(ans[j].dir != ans[j + 1].dir && ans[j].dir == 0) {
                swap(ans[j], ans[j + 1]);
                j ++;
            }
        }
    }

    for(int i = 0; i < n1 + n2; i++) {
        cout << ans[i].antInfo;
    }
    return 0;
}
