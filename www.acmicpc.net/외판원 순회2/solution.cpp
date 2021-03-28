#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool visited_city[11] = {false,};
int board[11][11] = {0,};
int answer = 9999999;
int city_cnt = 0;

void find_street(int start_city, int target, int dept, int total_value) {
    if(dept == city_cnt && target == start_city) {
        if(answer > total_value)
            answer = total_value;
        return;
    }

    for(int i = 0; i < city_cnt; i++) {
        if(board[target][i] == 0)
            continue;

        if(!visited_city[target] && board[target][i] > 0) {
            // 방문에 대한 기록 표시
            visited_city[target] = true;
            total_value += board[target][i];

            // 깊이 우선 탐색
            if(total_value <= answer)
                find_street(start_city, i, dept + 1, total_value);

            total_value -= board[target][i];
            visited_city[target] = false;
        }
    }
} 

int main() {

    cin >> city_cnt;

    // 지도 정보 입력
    for(int i = 0; i < city_cnt; i++) {
        for(int j = 0; j < city_cnt; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < city_cnt; i++)
        find_street(i, i, 0, 0);
    cout << answer << endl;
    return 0;
}