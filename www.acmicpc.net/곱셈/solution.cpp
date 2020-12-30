#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long int A = 0, B = 0, C = 0;
long long int ddaddable(long long int A_Value,long long int B_Value) {
    if(B_Value == 0)
        return 1;
    if(B_Value == 1)
        return A;
    if(B_Value % 2 == 1)
        return ddaddable(A_Value, B_Value -1) * A;
    long long int half_value = ddaddable(A_Value,  B_Value / 2);
    half_value %= C;
    return (half_value * half_value) % C;
}

int main() {
    cin >> A >> B >> C;

    cout << ddaddable(A, B) % C << endl;
    return 0;
}