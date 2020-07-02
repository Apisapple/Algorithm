#include <string>
#include <vector>
#include <iostream>

using namespace std;

string people = "ACFJMNRT";
vector <bool> check(8 , false);
int answer;

/* 순열을 만들고 조건부 계산하기 위한 함수 */
void permutation(vector<string>data, vector<char> arr, int count, int n){
    if(count == people.size()){
        for(int i = 0; i < n; i++){
            char firstPerson = data[i][0];
            char secondPerson = data[i][2];
            char compare = data[i][3];
            int distance = data[i][4] - '0' + 1;
            int firstIndex = -1;
            int secondIndex = - 1;

            for(int j = 0; j < people.size(); j++){
                if(arr[j] == firstPerson)
                    firstIndex = j;
                if(arr[j] == secondPerson)
                    secondIndex = j;
                if(firstIndex != -1 && secondIndex != -1)
                    break;
            }
            /* 만족하기 위한 조건들 */
            if(compare == '=' && abs(firstIndex - secondIndex) != distance)
                return;
            if(compare == '<' && abs(firstIndex - secondIndex) >= distance)
                return;
            if(compare == '>' && abs(firstIndex - secondIndex) <= distance)
                return;
        }
        answer++;
        return;
    }
    for(int i = 0; i < people.size(); i++){
        if(check[i] == true)
            continue;
        check[i] = true;
        arr[count] = people.at(i);
        permutation(data, arr, count + 1, n);
        check[i] = false;
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    vector <char> arr(8 , NULL);
    permutation(data, arr, 0, n);
    return answer;
}