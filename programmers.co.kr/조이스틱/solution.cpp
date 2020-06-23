#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calDistance(char b){
    int valueA = b - 'A';
    int valueB = 'Z' - b + 1;
    return min(valueA, valueB);
}
int TotalValue(vector <int> &arr){
    int total = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        total += arr[i];
    }
    return total;
}

int solution(string name) {
    int answer = 0;
    int nameLength = name.size();
    string startname(nameLength, 'A');
    vector <int> upanddown(nameLength, 0);
    
    /* 위, 아래 횟수 계산 */
    for(int i = 0; i < nameLength; i++){
        upanddown[i] = calDistance(name[i]);
    }
    answer = TotalValue(upanddown);
    /* 좌, 우 횟수 계산 */
    int index = 0;
    while(true){
        int leftcnt = 0, rightcnt = 0;
        int leftindex = index , rightindex = index;
        upanddown[index] = 0;
        if(TotalValue(upanddown) == 0)
            break;
        
        while(upanddown[leftindex] == 0){
            leftcnt ++;
            leftindex = (leftindex <= 0) ? nameLength - 1 : leftindex - 1;
        }
        while(upanddown[rightindex] == 0){
            rightcnt ++;
            rightindex = (rightindex + 1) % nameLength; 
        }
        answer += min(leftcnt, rightcnt);
        index = (leftcnt < rightcnt) ? leftindex : rightindex;
    }
    return answer;
}