#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int number_count = 0;
vector<int> number_list(11, 0);
vector<int> cal_list(4, 0);
vector<int> new_cal_list;
vector<int> value_list;
int calculation() {
    int result = number_list[0];
    for(int i = 0; i < number_count; i++) {
        switch (new_cal_list[i])
        {
        case 0:
            result += number_list[i + 1];
            break;
        case 1:
            result -= number_list[i + 1];
            break;
        case 2:
            result *= number_list[i + 1];
            break;
        case 3:
            result /= number_list[i + 1];
            break;
        default:
            break;
        }
    }
    return result;
}
void dfs(int depth) {
    if(depth == number_count - 1) {
        int result = calculation();
        value_list.push_back(result);
    } else {
        for(int i = 0; i < 4; i++) {
            if(cal_list[i]) {
                cal_list[i] --;
                new_cal_list.push_back(i);

                dfs(depth + 1);

                new_cal_list.pop_back();
                cal_list[i] ++;
            }
        }
    }
}

int main() {
    int total = 0;
    int depth = 0;
    cin >> number_count;
    for(int i = 0; i < number_count; i++) {
        cin >> number_list[i];
    }
    for(int i = 0; i < 4; i ++) {
        cin >> cal_list[i];
    }
    dfs(depth);
    sort(value_list.begin(), value_list.end());
    cout << value_list.back() << endl;
    cout << value_list[0] << endl;
    return 0;
}