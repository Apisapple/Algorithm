#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_SIZE 5000
#define DIV_NUM 1000000

vector <int> dp (MAX_SIZE + 1, 0);

vector<int> convertStrToNum(string encrypt) {
    vector<int> result(encrypt.size());
    for(int i = 0; i < encrypt.size(); i++) {
        result[i] = encrypt[i] - '0';
    }
    return result;
}

int main() {
    vector<int> encrypt_num;
    string encrypt;
    cin >> encrypt;
    if(encrypt[0] == '0') {
        cout << 0 << endl;
        return 0;
    }
    encrypt_num = convertStrToNum(encrypt);

    dp[0] = dp[1] = 1;
    for(int i = 2; i <= encrypt.size(); i++) {
        if(encrypt_num[i - 1] == 0 && encrypt_num[i - 2] == 0) {
            cout << 0 << endl;
            return 0;
        }
        if(encrypt_num[i - 1] != 0)
            dp[i] += dp[i - 1];
        if(encrypt_num[i - 2] != 0) {
            int number = encrypt_num[i - 2] * 10 + encrypt_num[i - 1];
            if(number <= 26)
                dp[i] += dp[i - 2];
        }
        dp[i] %= DIV_NUM;
    }
    cout << dp[encrypt.size()] << endl;
    return 0;
}