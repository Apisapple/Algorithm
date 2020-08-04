#include <string>
#include <vector>

#define CONDITION 1000000007

using namespace std;

int solution(int n) {
    int answer = 0;
    vector <int> numberlist(n + 1 , 0);
    numberlist[1] = 1;
    numberlist[2] = 2;
    int index = 3;
    while(index <= n) {
        numberlist[index] = (numberlist[index - 1] + numberlist[index - 2]) % CONDITION;
        index ++;
    }
    return numberlist[n] % CONDITION;
}