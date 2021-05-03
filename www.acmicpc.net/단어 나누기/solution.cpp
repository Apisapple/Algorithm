#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<string> token;
string answer = "";
void makeToken(string temp, int firstIndex, int secondIndex) {
    string a = "", b = "", c = "";

    for(int i = 0; i <= firstIndex; i++) {
        a = a + temp[i];
    }
    for(int i = firstIndex + 1; i <= secondIndex; i ++) {
        b = b + temp[i];
    }
    for(int i = secondIndex + 1; i < temp.size(); i++) {
        c = c + temp[i];
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());

    if(answer == "")
        answer = a + b + c;
    else {
        if(answer > a + b + c)
            answer = a + b + c;
    }
}

int main() {
    string inputValue = "";
    cin >> inputValue;

    for(int i = 0; i < inputValue.size() - 1; i++) {
        for(int j = i; j < inputValue.size() - 1; j++){
            if(i < j) {
                string temp = inputValue;
                makeToken(temp, i, j);
            }
        }
    }
    cout << answer << endl;
    return 0;
}