#include <algorithm>
#include <iostream>
#include <vector>

/*  자신의 바로 다음이나 전에 경기하는 팀에게만 카약을 빌려주려고 한다. 
 즉, 팀 4는 여분의 카약을 3이나 5에게만 빌려줄 수 있다. 
 또, 카약을 하나 더 가져온 팀의 카약이 손상되었다면, 여분의 카약으로 경기에 출전하게되고, 
 이 카약은 다른 팀에게 빌려줄 수 없다. */
using namespace std;


int main() {
    // 팀의 수 : N, 손상된 팀의 수 : S, 카약을 하나 더 가져온 팀의 수 R
    int N, S, R, result = 0;

    cin >> N >> S >> R;

    vector<int> teamsInfo(N + 1, 1);
    //  파괴된 카약 정보
    for(int i = 1; i <= S; i++) {
        int temp = 0;
        cin >> temp;
        teamsInfo[temp] --;
    }
    // 여유 분을 가진 팀의 정보
    for(int i = 1; i <= R; i++) {
        int temp = 0;
        cin >> temp;
        teamsInfo[temp] ++;
    }
    // 나눠주기 시작
    for(int i = 1; i <= N; i++) {
        if(teamsInfo[i] == 0) {
            if(i == 1 && teamsInfo[i + 1] == 2) {
                teamsInfo[i + 1] --;
                teamsInfo[i] ++;
            } else if(i == N && teamsInfo[i - 1] == 2) {
                teamsInfo[i] ++;
                teamsInfo[i - 1] --;
            } else {
                if(teamsInfo[i - 1] == 2) {
                    teamsInfo[i - 1] --;
                    teamsInfo[i] ++;
                } else if (teamsInfo[i + 1] == 2) {
                    teamsInfo[i + 1] --;
                    teamsInfo[i] ++;
                }
            }
        }
    }
    // 배분을 받지 못한 친구 확인
    for(int i = 1; i <= N; i++) {
        if(teamsInfo[i] == 0)
            result ++;
    }

    cout << result << endl;
    return 0;
}