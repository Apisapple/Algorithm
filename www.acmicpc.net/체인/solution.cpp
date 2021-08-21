#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void initSolution() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int main() {
    initSolution();

    int chain_cnt = 0, result = 0;
    cin >> chain_cnt;

    vector<long> chain_length(chain_cnt, 0);
    for(int i = 0; i < chain_cnt; i++) {
        cin >> chain_length[i];
    }

    sort(chain_length.begin(), chain_length.end());

    while(true) {
        // all chain connection
        if(chain_length.size() == 1)
            break;

        // connect chain
        chain_length[chain_length.size() - 2] += chain_length[chain_length.size() - 1];
        chain_length.pop_back();
        result ++;
        chain_length[0] --;

        // if first chain is 0 
        if(chain_length[0] == 0) {
            for(int i = 0; i < chain_length.size() - 1; i++) {
                chain_length[i] = chain_length[i + 1];
            }
            chain_length.pop_back();
        }
    }

    cout << result << '\n';
}