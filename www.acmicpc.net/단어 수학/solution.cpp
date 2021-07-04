#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long answer;
long long number;
vector<long long> arr(27, 0);
vector<long long> V;
string word;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> number;

    for(int i = 0; i < number; i++) {
        cin >> word;

        int temp = 1;
        for(int j = word.size() - 1; 0 <= j; j--) {
            arr[word[j] - 'A'] += temp;
            temp *= 10;
        }
    }

    for(int i = 0; i < 27; i++) {
        if(arr[i] != 0)
            V.push_back(arr[i]);
    }

    sort(V.begin(), V.end());

    int value = 9;
    for(int i = V.size() - 1; 0 <= i; i--) {
        answer += V[i] * value;
        value --;
    }

    cout << answer << '\n';

    return 0;
}
