#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int testCnt = 0;
    cin >> testCnt;
    while(testCnt --) {
        map<string, int> sentenceIdx;
        map<int, int> whic;
        string firstPublicKey[1000];
        string secondPublicKey[1000];
        string decrypto[1000];
        string crypto[1000];
        string sentence;
        int sentenceCnt = 0;

        cin >> sentenceCnt;
        for(int i = 0; i < sentenceCnt; i++) {
            cin >> sentence;
            firstPublicKey[i] = sentence;
            sentenceIdx[sentence] = i;
        }

        for(int i = 0; i < sentenceCnt; i++) {
            cin >> sentence;
            secondPublicKey[i] = sentence;
            whic[i] = sentenceIdx[sentence];
        }

        for(int i = 0; i < sentenceCnt; i++) {
            cin >> sentence;
            crypto[i] = sentence;

        }

        for(int i = 0; i < sentenceCnt; i++) {
            decrypto[whic[i]] = crypto[i];
        }

        for(int i = 0; i < sentenceCnt; i++)
            cout << decrypto[i] << " ";

        cout << endl;

    }
    return 0;
}