#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int answer = arr[arr.size() - 1];
    while(1) {
        bool flag = false;
        for(int i = 0 ; i < arr.size(); i++) {
            if(answer % arr[i] == 0) {
                flag = true;
                continue;   
            }
            else {
                flag = false;
                break;   
            }
        }
        if(flag)
            break;
        answer++;
    }
    
    return answer;
}