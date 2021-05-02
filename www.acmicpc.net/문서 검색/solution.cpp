#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// 이 함수는 어떤 단어가 총 몇 번 등장하는지 세려고 한다.
// 중복되어 세는 것은 뺴고 세야 한다.
// 최대 몇 번 중복되지 않게 등장하는지를 구하라
int main() {
    string doc, compSen;
    int result = 0;

    getline(cin, doc);
    getline(cin, compSen);

    if(doc.size() < compSen.size()) {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i < doc.size() - compSen.size() + 1; i ++) {
        bool flag = true;

        for(int j = 0; j < compSen.size(); j++) {
            if(doc[i + j] != compSen[j]) {
                flag = false;
                break;
            }
        }

        if(flag) {
            result ++;
            i += compSen.size() - 1;
        }
    }

    cout << result << endl;
    return 0;
}