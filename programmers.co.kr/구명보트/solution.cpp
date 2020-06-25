#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    vector <int> boat;
    int answer = 0;
    int totalWeight = 0;

    sort(people.begin(), people.end());
    int leftindex = 0;
    int rightindex = people.size() - 1;
    while(leftindex <= rightindex){
        totalWeight = people[leftindex] + people[rightindex];
        if(limit >= totalWeight){
            leftindex ++;
        }
        rightindex --;
        totalWeight = 0;
        answer++;
    }
    return answer;
}