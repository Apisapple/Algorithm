#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int bigger, smaller;
    if(a == b){
        return a;
    }else{
        if(a >= b){
            bigger = a;
            smaller = b;
        }else{
            bigger = b;
            smaller = a;
        }
        for(int i = smaller; i <=bigger; i++){
            answer += i;
        }
    }
    return answer;
}