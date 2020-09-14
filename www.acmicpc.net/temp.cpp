#include <string>
#include <vector>
#include <cmath>
#include <iostream>

#define MAX_SIZE 10

using namespace std;

vector<int> answer;

int countIndex(int number) {
    int result = 0;
    while (number != 0) {
        result ++;
        number /= 10;
    }
    return result;
}

void searchValue(int n, int count) {
    if(n < 10) {
        if(answer[1] > n) {
            answer[0] = count;
            answer[1] = n;
        } else if (answer[1] == n && answer[0] > count) {
            answer[0] = count;
        }
        return;
    }
    int max_index = countIndex(n);
    count ++;
    for(int i = 1; i < max_index; i++) {
        int value = pow(10, i);
        int header = n / value;
        int remain = n % value;
        if(value >= 100 && remain < 10)
            continue;
        n = header + remain;
        searchValue(n, count);        
    }
}

vector<int> solution(int n) {
    answer.push_back(11);
    answer.push_back(10);
    searchValue(n, 0);
    return answer;
}