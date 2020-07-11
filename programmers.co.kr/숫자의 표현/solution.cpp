#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int total = 0;
    
    for(int i = 1; i <= n; i++) {
        total = i;
        for(int j = i + 1; total <= n; j ++) {
            if(total == n){
                answer ++;
                break;
            }
            total += j;
        }
        total = 0;
    }
    return answer;
}