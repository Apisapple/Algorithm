#include <string>
#include <vector>

using namespace std;
int answer = 0;
void FindValue(vector<int> &numbers, int target,int total, int index){
    if(index >= numbers.size()){
        if(total == target){
            answer++;
        }
    }else{
        FindValue(numbers, target, total + numbers[index], index + 1);
        FindValue(numbers, target, total - numbers[index], index + 1);
    }
}
int solution(vector<int> numbers, int target) {
    FindValue(numbers, target, 0, 0);
    return answer;
}