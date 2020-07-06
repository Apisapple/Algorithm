#include <string>
#include <vector>

using namespace std;

int countOne(int num){
    int result = 0;
    for(int i = num; i != 1; i /= 2){
        if(i % 2 == 1)
            result++;
    }
    return result;
}
int solution(int n) {
    int baseCount = countOne(n);
    int compareCount = 0;
    while(1){
        compareCount = countOne(++n);
        if(compareCount == baseCount)
            return n;
    }
}