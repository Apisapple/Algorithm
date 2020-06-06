#include <string>
#include <vector>
#include <algorithm>

using namespace std;



long long solution(long long n) {
    long long answer = 0;
    int index = 1;
    vector<int> temp;
    while(1){
        if(n<=0)
            break;
        temp.push_back(n % 10);
        n /= 10;
    }
    sort(temp.begin(), temp.end());
    for(int i = 0; i < temp.size(); i++){
        answer += temp[i] * index;
        index *= 10;
    }
    return answer;
}