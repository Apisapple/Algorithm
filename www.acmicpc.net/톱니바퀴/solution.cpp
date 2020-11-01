#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > cogwheel(4);
vector<bool> visited(4);

void rotateGear(int gear_number, int rotate_way){
    if(rotate_way == 1) {
        int temp = cogwheel[gear_number][7];
        cogwheel[gear_number].pop_back();
        cogwheel[gear_number].insert(cogwheel[gear_number].begin(), temp);
    }else if (rotate_way == -1) {
        int temp = cogwheel[gear_number].front();
        cogwheel[gear_number].erase(cogwheel[gear_number].begin());
        cogwheel[gear_number].push_back(temp);
    }
}

void checkStatus(int gear_number, int rotate_way) {
    visited[gear_number] = true;
    int left_number = gear_number - 1;
    int right_number = gear_number + 1;
    if(0 <= left_number && !visited[left_number]) {
        if(cogwheel[left_number][2] != cogwheel[gear_number][6]) {
            checkStatus(left_number, rotate_way * (-1));
        }
    }
    if(right_number < 4 && !visited[right_number]) {
        if(cogwheel[right_number][6] != cogwheel[gear_number][2]) {
                checkStatus(right_number, rotate_way * (-1));
        }
    }
    rotateGear(gear_number, rotate_way);
}

int main() {
    int rotateCount = 0;
    int answer = 0;
    int total_value = 1;
    // 톱니바퀴 정보 입력
    for(int i = 0; i < cogwheel.size(); i++) {
        string input_value;
        cin >> input_value;
        for(int j = 0; j < input_value.length(); j++) {
            cogwheel[i].push_back(input_value[j] - '0');
        }
    }
    // 회전 횟수 입력 및 방향 입력
    cin >> rotateCount;
    for(int i = 0; i < rotateCount; i++) {
        int geal_number, rotate_way;
        cin >> geal_number >> rotate_way;
        checkStatus(geal_number - 1, rotate_way);
        for(int i = 0 ; i < 4; i ++) {
            visited[i] = false;
        }
    }
    
    for(int i = 0; i < 4; i++) {
        if(cogwheel[i][0] == 1)
            answer += total_value;
        total_value *= 2;
    }
    cout << answer << endl;
    return 0;
}