#include <numeric>

using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    int gcd;
    long long total = (long long) w * (long long) h;
    for(int i = (w < h) ? w : h; 0 < i; i--){
        if( (w % i == 0) && (h % i) == 0){
            gcd = i;
            break;
        }
    }
    answer = total - gcd * ((w / gcd ) + (h / gcd) - 1);
    return answer;
}