#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for(int number : arr) {
        if(answer.empty() || answer.back() != number) {
            answer.push_back(number);
        }
    }
    
    return answer;
}