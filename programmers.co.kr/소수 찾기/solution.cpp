#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 1부터 N까지의 소수개수 = 에라토스테네스의 체
숫자 N이 소수인지 판별 = func(int n)
int func(int n)
{
    int answer = 0;
    for(int i = 2; i <= n; i++){
        bool flag = true;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0)
                flag = false;
        }
        if(flag)
            answer++;
    }
    return answer;
}

 */

int solution(int n)
{
    int answer = 0;
    vector <bool> NumberList(n + 1, false);
    for(int i = 2; i <= n ; i++)
    {
        if(!NumberList[i]){
            answer++;
            NumberList[i] = true;
        }
        for(int j = i * 2; j <= n; j += i){
            NumberList[j] = true;
        }
    }
    return answer;
}
