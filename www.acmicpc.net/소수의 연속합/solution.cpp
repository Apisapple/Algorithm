#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 4000000

int N = 0;

void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

void setPrimeNumber(vector<bool> &visited, vector<int> &primeNumber) {

    for(int i = 2; i * i <= N; i++) {
        if(visited[i]) {
            for(int j = i + i; j <= N; j += i) {
                visited[j] = false;
            }
        }
    }
    for(int i = 2; i <= N; i++) {
        if(visited[i])
            primeNumber.push_back(i);
    }
}

int main(int argc, const char** argv) {
    int cnt = 0, total = 0;
    vector<int>::size_type rightIndex = 0, leftIndex = 0;
    initSolution();

    cin >> N;

    vector<bool> visited(N + 1, true);
    vector<int> primeNumber;

    setPrimeNumber(visited, primeNumber);

    while(true) {
        if(N <= total)
            total -= primeNumber[leftIndex ++];
        else if(rightIndex == primeNumber.size())
            break;
        else
            total += primeNumber[rightIndex++];

        if(total == N)
            cnt ++;
    }

    cout << cnt << '\n';
    
    return 0;
}