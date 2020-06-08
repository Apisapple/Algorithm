#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int min = n < m ? n : m;
    int max = n <= m ? m : n;
    int gcd;
    int lcm;
    for(int i = 1; i <= min; i++){
        if( (n % i == 0) && (m % i == 0)){
            gcd = i;
        }
    }
    for(int i = max; ; i++){
        if((i % n == 0) && (i % m == 0)){
            lcm = i;
            break;
        }
    }
    answer.push_back(gcd);
    answer.push_back(lcm);
    return answer;
}