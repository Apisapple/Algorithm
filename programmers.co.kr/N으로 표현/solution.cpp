#include <string>
#include <vector>
#include <algorithm>

#define MAX_SIZE 8

using namespace std;

int answer = 9;

void searchValue(int N, int number, int count, int value) {
    if(count > MAX_SIZE)
        return;
    if(value == number) {
        answer = min(answer, count);
        return;
    }

    int temp = 0;
    for(int i = 0; i < 9; i++) {
        temp = temp * 10 + N;
        searchValue(N, number, count + 1, temp + N);
        searchValue(N, number, count + 1, temp - N);
        searchValue(N, number, count + 1, temp * N);
        searchValue(N, number, count + 1, temp / N);
    }
}
int solution(int N, int number) {
    searchValue(N, number, 0, 0);
    return answer;
}