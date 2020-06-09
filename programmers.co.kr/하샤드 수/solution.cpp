#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int number = x;
    while (1){
        if(number <= 0)
            break;
        int remain = number % 10;
        number /= 10;
        sum += remain;
    }
    if(x % sum != 0)
        answer = false;
    return answer;
}