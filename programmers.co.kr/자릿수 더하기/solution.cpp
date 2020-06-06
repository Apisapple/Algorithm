#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    while(1){
        if(n <= 0){
            break;
        }
        int remain = n % 10;
        n /= 10;
        answer += remain;
    }

    return answer;
}