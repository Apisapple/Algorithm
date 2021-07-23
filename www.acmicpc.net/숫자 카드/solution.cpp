#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 500000
#define MAX_SIZE 10000000

vector<int> numberList(MAX_SIZE * 2 + 1, 0);
vector<int> result(MAX + 1, 0);
int N = 0, M = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    
    int temp = 0;
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        numberList[temp + MAX_SIZE] = 1;
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> temp;
        if(numberList[temp + MAX_SIZE] == 1) {
            cout << "1 ";
        }else {
            cout << "0 ";
        }
    }


    return 0;
}