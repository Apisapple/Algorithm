#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while(1){
        if(n <= 0)
            break;
        int remain = n % 10;
        n /= 10;
        answer.push_back(remain);
    }
    return answer;
}