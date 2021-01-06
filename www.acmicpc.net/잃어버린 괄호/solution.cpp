#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector <int> number_list;
    int temp_number = 0, total = 0, result = 0;
    string math_expression;
    cin >> math_expression;
    for(int i = 0; i < math_expression.length(); i++) {
        char op = math_expression[i];
        switch (op)
        {
        case '+':
            total += temp_number;
            temp_number = 0;
            break;
        case '-':
            total += temp_number;
            number_list.push_back(total);
            temp_number = 0;
            total = 0;
            break;
        default:
            temp_number *= 10;
            temp_number += (op - '0');
            break;
        }
    }
    total += temp_number;
    number_list.push_back(total);
    result = number_list[0];
    for(int i = 1; i < number_list.size(); i++) {
        result -= number_list[i];
    }
    cout << result << endl;
    return 0;
}