#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 20

vector<long long> factorial(MAX + 1, 1);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int number = 0, choice = 0;

    cin >> number;
    cin >> choice;
    for(int i = 1; i < MAX + 1; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    vector<bool> visited(MAX + 1, false);
    if(choice == 1) {
        long long temp;
        cin >> temp;
        vector<int> result(number, 0);

        for(int i = 0; i < number; i++) {
            for(int j = 1; j < number + 1; j++) {
                if(visited[j])
                    continue;
                if(factorial[number - i - 1] < temp) {
                    temp -= factorial[number - i - 1];
                } else {
                    result[i] = j;
                    visited[j] = true;
                    break;
                }
            }
        }
        for(int i = 0; i < number; i++) {
            cout << result[i] << ' ';
        }
    } else {
        long long answer = 0;
        vector<int> inputData(number);
        for(int i = 0; i < number; i++) {
            cin >> inputData[i];
        }

        for(int i = 0; i < number; i++) {
            for(int j = 1; j < inputData[i]; j++) {
                if(!visited[j])
                    answer += factorial[number - i - 1];
            }
            visited[inputData[i]] = true;
        }
        cout << answer + 1 << '\n';
    }

    return 0;
}