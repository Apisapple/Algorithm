#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    long long number = sqrt(n);
    if(number * number == n){
        answer = (number + 1) * (number + 1);
    }
    return answer;
}