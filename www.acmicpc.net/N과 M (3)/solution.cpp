#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 7

vector<int> result(MAX, 0);
vector<int> numberList(MAX, 0);
int N, M;

void solution(int dept) {
    if(dept == M) {
        for(int i = 0; i < M; i++) {
            cout << result[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < N; i ++) {
            result[dept] = numberList[i];
            solution(dept + 1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for(int i = 0; i < numberList.size(); i++) {
        numberList[i] = i + 1;
    }

    solution(0);

    return 0;
}