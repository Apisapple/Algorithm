#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 1000001

using namespace std;

vector<bool> broke_btnList(10, true);


bool isPossible(int number) {
    if(number == 0) {
        if(broke_btnList[0])
            return true;
        else
            return false;
    } else {
        while (number) {
            if(!broke_btnList[number % 10])
                return false;
            number /= 10;
        }
    }
    return true;
}

int main() {
    int target, broke_btn;
    cin >> target;
    int answer = abs(target - 100);
    cin >> broke_btn;
    // 고장난 버튼 표시
    for(int i = 0; i < broke_btn; i++) {
        int temp = 0;
        cin >> temp;
        broke_btnList[temp] = false;
    }

    for(int i = 0; i < MAX; i++) {
        if(isPossible(i)) {
            int temp_size = to_string(i).length() + abs(i - target);
            answer = min(answer , temp_size);
        }
    }

    cout << answer << endl;
    return 0;
}