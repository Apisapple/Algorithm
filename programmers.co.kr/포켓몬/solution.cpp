#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int max_index = 1;
    int max_choice = nums.size() / 2;
    vector <int> Monster_list(200001, 0);
    for(int i = 0; i < nums.size(); i ++){
        if(max_index <= nums[i])
            max_index = nums[i];
        Monster_list[nums[i]] ++;
    }
    for(int i = 1; i <= max_index; i ++){
        if(max_choice <= answer)
            break;
        if(Monster_list[i] != 0)
            answer++;
    }
    return answer;
}