#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define MAX 15

int L = 0, C = 0;
vector<string> result;
vector<char> consonant;
vector<char> vowel;
map<string, bool> visit;

void makeCrypto(int consoIndex, int voIndex, int conCnt, int voCnt, string crypt) {
    if(crypt.size() == L && voCnt >= 1 && conCnt >= 2) {
      sort(crypt.begin(), crypt.end());
      if(!visit.count(crypt)) {
        visit[crypt] = true;
        result.push_back(crypt);
      }
    }
    if(crypt.size() == L)
        return;

    for(int i = voIndex + 1; i < vowel.size(); i++) {
        makeCrypto(consoIndex, i, conCnt, voCnt + 1, crypt + vowel[i]);
    }
    for(int i = consoIndex + 1; i < consonant.size(); i++) {
        makeCrypto(i, voIndex, conCnt + 1, voCnt, crypt + consonant[i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> L >> C;

    for(int i = 0; i < C; i++) {
        char temp;
        cin >> temp;

        if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
            vowel.push_back(temp);
        else
            consonant.push_back(temp);
    }
    sort(consonant.begin(), consonant.end());
    sort(vowel.begin(), vowel.end());
    string temp = "";
    makeCrypto(-1, -1, 0, 0, temp);

    sort(result.begin(), result.end());
    for(string t : result) {
        cout << t << '\n';
    }
    return 0;
}