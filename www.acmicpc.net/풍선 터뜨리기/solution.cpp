#include <iostream>
#include <vector>

using namespace std;

#define MAX_CNT 1000

int main() {
    vector<pair<int, int>> numberList;
    int cnt = 0;
    cin >> cnt;

    // 풍선 정보 입력
    for(int i = 0; i < cnt; i++) {
        int temp = 0;
        cin >> temp;
        numberList.push_back(make_pair(i + 1, temp));
    }

    // 풍선 터트리기 시작
    int nowIndex = 0;
    int allSize = cnt;
    for(int i = 0; i < allSize; i++) {
        cout << numberList[nowIndex].first << " ";
        int moveSize = numberList[nowIndex].second;
        if(moveSize > 0) {
            moveSize --;
        }

        numberList.erase(numberList.begin() + nowIndex);
        nowIndex += moveSize;
        cnt--;
        if(cnt == 0)
            break;
        if(nowIndex < 0) {
            nowIndex = cnt + nowIndex % cnt;
        }
        nowIndex %= cnt;

    }
    cout << endl;
    return 0;
}
