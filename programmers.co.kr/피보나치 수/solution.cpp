#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector <int> numberList;
    int number = 1234567;
    int answer = 0;
    int a = 0;
    int b = 1;
    
    for(int i = 2 ; i <= n; i++) {
        answer = (a + b) % number;
        a = b % number;
        b = answer % number;
    }

    return answer;
}