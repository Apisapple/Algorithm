#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

bool isPrimeNumber(ll number) {
    if (number < 2)
        return false;

    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0)
            return false;
    }

    return true;
}

string convertKnumber(int n, int k) {
    string result = "";

    while (n) {
        result += to_string(n % k);
        n /= k;
    }

    return string(result.rbegin(), result.rend());
}

int solution(int n, int k) {
    string kNumber = convertKnumber(n, k);
    string temp = "";
    int answer = 0;

    for(int i = 0; i < kNumber.length(); i++) {
        if(kNumber[i] == '0' && !temp.empty()) {
            ll n = stoll(temp);
            if(isPrimeNumber(n)) {
                answer ++;
            }
            temp = "";
        } else {
            temp += kNumber[i];
        }
    }

    if(!temp.empty()) {
        ll n = stoll(temp);
        if(isPrimeNumber(n)) 
            answer ++;
    }
    return answer;
}