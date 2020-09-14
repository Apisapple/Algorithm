#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b, int c) {
    int temp = a < b ? b : a;
    return temp = temp < c ? c : temp;
}

int solution(int E, int S, int M) {
    int year_earth = 0;
    int year_sun = 0;
    int year_moon = 0;
    int year = 0;
    while(1) {
        if(year_earth > 15)
            year_earth -= 15;
        if(year_sun > 28)
            year_sun -= 28;
        if(year_moon > 19)
            year_moon -= 19;
        if(year_earth == E  && year_sun == S  && year_moon == M )
            break;
        year ++;
        year_earth ++;
        year_moon ++;
        year_sun ++;
    }
    return year;
}

int main() {
    /*  E : 지구를 나타내는 수
        S : 태양을 나타내는 수
        M : 달을 나타내는 수  */
    int E = 0, S = 0, M = 0;
    int answer = 0;
    cin >> E >> S >> M;
    answer = solution(E, S, M);
    cout << answer;
    return 0;
}