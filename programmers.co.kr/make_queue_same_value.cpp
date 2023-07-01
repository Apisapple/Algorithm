#include <string>
#include <vector>
#include <numeric>
#include <iostream>

#define ll long long

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    ll sum1 = accumulate(queue1.begin(), queue1.end(), 0ll);
    ll sum2 = accumulate(queue2.begin(), queue2.end(), 0ll);
    size_t queue1_size = queue1.size();
    size_t queue2_size = queue2.size();
    int idx1 = 0;
    int idx2 = 0;
    if((sum1 + sum2) % 2 == 0) {
        while(sum1 != sum2) {
            if(queue1_size + queue2_size + 2 < answer) {
                answer = -1;
                break;
            }
            
            if(sum1 < sum2) {
                queue1.push_back(queue2.at(idx2));
                sum1 += queue2.at(idx2);
                sum2 -= queue2.at(idx2);
                idx2 ++;
            } else {
                queue2.push_back(queue1.at(idx1));
                sum1 -= queue1.at(idx1);
                sum2 += queue1.at(idx1);
                idx1 ++;
            }
            
            answer++;
        }
    } else {
        answer = -1;
    }
    return answer;
}