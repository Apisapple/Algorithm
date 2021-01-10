#include <iostream>
#include <string>

using namespace std;

int main() {
    int N_size = 0, S_size = 0, result = 0;
    string N = "I", S;

    cin >> N_size;
    cin >> S_size;
    cin >> S;

    for(int i = 0; i < S_size; i++) {
        int tempN_size = 0;
        if(S[i] == 'I') {
            while(S[i + 1] == 'O' && S[i + 2] == 'I') {
                tempN_size ++;
                if(tempN_size == N_size) {
                    tempN_size --;
                    result ++;
                }
                i += 2;
            }
        } else if(S[i] == 'O')
            continue;
    }
    cout << result << endl;

    return 0;
}