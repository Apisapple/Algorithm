#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string inputValue;
    string result;
    cin >> inputValue;
    result = inputValue;


    for(int firstIndex = 0; firstIndex < inputValue.size() - 2; firstIndex ++) {
        for(int secondIndex = firstIndex + 1; secondIndex < inputValue.size() - 1; secondIndex++) {
            string temp = inputValue;

            reverse(temp.begin(), temp.begin() + firstIndex + 1);
            reverse(temp.begin() + firstIndex + 1, temp.begin() + secondIndex + 1);
            reverse(temp.begin() + secondIndex + 1, temp.end());

            result = min(result, temp);
        }
    }

    cout << result << endl;
    return 0;
}